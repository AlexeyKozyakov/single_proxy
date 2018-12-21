//

#include "MyProxy.h"

MyProxy::MyProxy(int port) : port(port), running(true) {}

void MyProxy::start() {
    try {
        startListening();
        std::cout << "Proxy started\n";
        selectLoop();
    } catch (std::runtime_error & e) {
        std::cerr << "Error occurred while starting server";
    } catch (std::bad_alloc & e1) {
        std::cerr << "BAD ALLOC!";
    }
}

void MyProxy::stop() {
    for (std::map<int, Client>::iterator iter = clients.begin(); iter != clients.end(); iter++) {
        closeSocket(iter->second.getSocket());
    }
    for (std::map<int, Server>::iterator iter = servers.begin(); iter != servers.end(); iter++) {
        closeSocket(iter->second.getSocket());
    }
    closeSocket(sockFd);
    std::cout << "Proxy finalized\n";
}

void MyProxy::startListening() {
    createServerSocket();
    bindServerSocket();
    if (listen(sockFd, BACKLOG_SIZE) < 0 ) {
        std::cerr << "Error while starting listening";
        throw std::runtime_error("Error while starting listening");
    }
    selector.registerFd(sockFd, POLLIN);
}

void MyProxy::selectLoop() {
    while (running) {
        if (selector.doPoll() > 0) {
            std::vector<pollfd> & descriptors = selector.getDescriptors();
            for (int i = 0; i < descriptors.size(); i++) {
                if (!descriptors[i].revents)
                    continue;
                if (descriptors[i].revents & POLLIN) {
                    std::cerr << "POLLIN\n";
                    handlePollin(descriptors[i], i);
                }
                if (descriptors[i].revents & POLLOUT) {
                    std::cerr << "POLLOUT\n";
                    handlePollout(descriptors[i], i);
                }
                if (descriptors[i].revents & POLLNVAL) {
                    std::cerr << "POLLNVAL\n";
                }
            }
            selector.clearInvalid();
        }
    }
}

void MyProxy::acceptNewConnection() {
    int clientSockFd;
    if ((clientSockFd = accept(sockFd, NULL, NULL)) != -1) {
        clients.insert(std::pair<int, Client>(clientSockFd, Client(clientSockFd)));
        selector.registerFd(clientSockFd, POLLIN);
        std::cerr << "Client accepted " << clientSockFd << "\n";
    }
}

void MyProxy::handlePollin(pollfd &selectedFd, int index) {
    if (selectedFd.fd == sockFd) {
        acceptNewConnection();
    } else {
        std::map<int, Client>::iterator clientIt = clients.find(selectedFd.fd);
        if (clientIt != clients.end()) {
            Client & client = clientIt->second;
            client.receiveRequest();
            if (client.hasError()) {
                closeClient(clientIt, index);
            } else if (client.headersComplete()) {
                selectedFd.events &= ~POLLIN;
                HttpRequest & request = client.getRequest();
                if (request.method != HTTP_GET) {
                    std::cerr << "Method not supported\n";
                    closeClient(clientIt, index);
                } else if (request.urn.empty()) {
                    std::cerr << "Empty host field\n";
                    closeClient(clientIt, index);
                } else if (request.port != 80){
                    std::cerr << "Unsupported port";
                    closeClient(clientIt, index);
                } else {
                    std::map<std::string, CacheEntry>::iterator cacheItr = cache.find(request.urn);
                    if (cacheItr == cache.end()) {
                        sockaddr_in addr;
                        if (getAddress(request.url, &addr) == NULL) {
                            closeClient(clientIt, index);
                        } else {
                            int serverFd = connectToServer(addr);
                            if (serverFd < 0) {
                                closeClient(clientIt, index);
                            } else {
                                std::cerr << "connected to server " << serverFd << "\n";
                                servers.insert(std::pair<int, Server>(serverFd, Server(serverFd, client)));
                                client.setServer(servers.find(serverFd)->second);
                                selector.registerFd(serverFd, POLLOUT);
                            }
                        }
                    } else {
                        selector.registerFd(client.getSocket(), POLLOUT);
                        cache.find(client.getUrn())->second.addClient(client.getSocket());
                    }
                }
            } else if (client.isRequested()) {
                closeClient(clientIt, index);
            }
        } else {
            std::map<int, Server>::iterator serverIt = servers.find(selectedFd.fd);
            Server & server = serverIt->second;
            if (!server.headersComplete() || server.isDirect()) {
                server.receiveResponseToBuf();
                if (server.hasError()) {
                    if (server.isDirect()) {
                        std::map<int, Client>::iterator cIt = clients.find(server.getClient()->getSocket());
                        if (cIt != clients.end()) {
                            closeClient(cIt, selector.getIndex(cIt->first));
                        }
                    }
                    closeServer(serverIt, index);
                } else {
                    if (server.isRespond()) {
                        selectedFd.events &= ~POLLIN;
                    }
                    if (server.headersComplete()) {
                        if (server.isDirect()) {
                            selector.getPollfd(server.getClient()->getSocket()).events |= POLLOUT;
                        } else {
                            if (server.getResponse().status_code == 200) {
                                server.setDirect(false);
                                cache.insert(std::pair<std::string, CacheEntry>(server.getUrn(), CacheEntry()));
                                cache.find(server.getUrn())->second.addClient(server.getClient()->getSocket());
                                cache.find(server.getUrn())->second.append(server.getData(), server.getDataLen());
                                std::cerr << "Cache entry for " << server.getUrn() <<" created\n";
                            } else {
                                server.setDirect(true);
                            }
                            selector.getPollfd(server.getClient()->getSocket()).events |= POLLOUT;
                        }
                    }
                }
            } else {
                std::map<std::string, CacheEntry>::iterator cacheItr = cache.find(server.getUrn());
                CacheEntry &entry = cacheItr->second;
                server.receiveResponseToCache(entry);
                if (server.hasError()) {
                    std::cerr << "Cache entry for " << server.getUrn() <<" removed\n";
                    closeServer(serverIt, index);
                    std::set<int> & clients_set = entry.getClients();
                    for (std::set<int>::iterator it = clients_set.begin(); it != clients_set.end(); it++) {
                        std::map<int, Client>::iterator cIt = clients.find(*it);
                        closeClient(cIt, selector.getIndex(*it));
                    }
                    cache.erase(cacheItr);
                } else {
                    if (server.isRespond()) {
                        closeServer(serverIt, index);
                    }
                    std::set<int> & clients = entry.getClients();
                    for (std::set<int>::iterator it = clients.begin(); it != clients.end(); it++) {
                        selector.getPollfd(*it).events |= POLLOUT;
                    }
                }
            }
        }
    }
}

void MyProxy::handlePollout(pollfd &selectedFd, int index) {
    std::map<int, Client>::iterator clientIt = clients.find(selectedFd.fd);
    if (clientIt != clients.end()) {
        Client & client = clientIt->second;
        if (client.isDirect()) {
            client.sendResponseFromServer();
            if (client.hasError() || client.isFinalized()) {
                std::map<int, Server>::iterator sIt = servers.find(client.getServer()->getSocket());
                if (sIt != servers.end()) {
                    closeServer(sIt, selector.getIndex(sIt->first));
                }
                closeClient(clientIt, index);
            } else if (client.isWaiting()) {
                selectedFd.events &= ~POLLOUT;
            }
        } else{
            std::map<std::string, CacheEntry>::iterator cacheItr = cache.find(client.getUrn());
            if (cacheItr != cache.end()) {
                CacheEntry & entry = cacheItr->second;
                client.sendResponseFromCache(entry);
                if (client.isFinalized() || client.hasError()) {
                    closeClient(clientIt, index);
                    entry.removeClient(client.getSocket());
                } else if (client.isWaiting()) {
                    selectedFd.events &= ~POLLOUT;
                }
            } else {
                selectedFd.events &= ~POLLOUT;
            }
        }
    } else {
        std::map<int, Server>::iterator serverIt = servers.find(selectedFd.fd);
        Server & server = serverIt->second;
        server.sendRequest();
        if (server.hasError()) {
            closeServer(serverIt, index);
        } else if (server.isRequested()) {
            selectedFd.events = POLLIN;
        }
    }
}

int MyProxy::connectToServer(sockaddr_in &addr) {
    int serverFd = socket(PF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        perror("Error while creating remote server socket");
    } else {
        if (connect(serverFd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("Error while connecting to remote server");
            return -1;
        }
    }
    return serverFd;
}

void MyProxy::closeClient(std::map<int, Client>::iterator &clientIt, size_t fdPollNum) {
    std::cerr << "Client closed " << clientIt->first << "\n";
    closeSocket(clientIt->first);
    clients.erase(clientIt);
    selector.unregisterFd(fdPollNum);

}

void MyProxy::closeServer(std::map<int, Server>::iterator &serverIt, size_t fdPollNum) {
    std::cerr << "Server closed " << serverIt->first << "\n";
    closeSocket(serverIt->first);
    servers.erase(serverIt);
    selector.unregisterFd(fdPollNum);
}

void MyProxy::createServerSocket() {
    sockFd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockFd < 0) {
        perror("Error while creating server socket");
        throw std::runtime_error("Error while creating server socket");
    }
}

void MyProxy::bindServerSocket() {
    sockaddr_in addr;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (bind(sockFd, (sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error whine binding server socket");
        throw std::runtime_error("Error whine binding server socket");
    }
}

int MyProxy::closeSocket(int socket) {
    int ret = close(socket);
    if (ret < 0) {
        perror("Error while closing socket");
    }
    return ret;
}

sockaddr_in *MyProxy::getAddress(std::string url, sockaddr_in *address) {
    struct hostent * host;
    if ((host = gethostbyname(url.c_str())) == NULL) {
        herror("Cannot find server IP address");
        return NULL;
    }
    address->sin_family = AF_INET;
    address->sin_port = htons(80);
    memcpy(&address->sin_addr.s_addr,host->h_addr, host->h_length);
    return address;
}
