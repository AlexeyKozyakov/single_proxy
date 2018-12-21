//
// Created by alex on 12.12.18.
//

#ifndef PROXY_PROXY_H
#define PROXY_PROXY_H

#include "http_parser.h"
#include "Selector.h"
#include "CacheEntry.h"
#include "Client.h"
#include "Server.h"
#include <map>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <cstring>

class MyProxy {

public:

    MyProxy(int port);

    void start();

    void stop();

private:
    bool running;
    int port;
    int sockFd;
    Selector selector;
    std::map<int, Client> clients;
    std::map<int, Server> servers;
    std::map<std::string, CacheEntry> cache;


    void startListening();

    void selectLoop();

    void acceptNewConnection();

    void handlePollin(pollfd & selectedFd, int index);

    void handlePollout(pollfd & selectedFd, int index);

    int connectToServer(sockaddr_in & addr);

    void closeClient(std::map<int, Client>::iterator & clientIt, size_t fdPollNum);

    void closeServer(std::map<int, Server>::iterator & serverIt, size_t fdPollNum);

    void createServerSocket();

    void bindServerSocket();

    int closeSocket(int socket);

    sockaddr_in * getAddress(std::string url, sockaddr_in * address);

};


#endif //PROXY_PROXY_H
