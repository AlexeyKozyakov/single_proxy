//
// Created by alex on 13.12.18.
//

#ifndef PROXY_CLIENT_H
#define PROXY_CLIENT_H



#include "CacheEntry.h"
#include "parser.h"
#include "Server.h"


class Server;

class Client {

public:

    Client(int sockFd);

    void setServer(Server & server);

    void receiveRequest();

    void sendResponseFromCache(CacheEntry & entry);

    void sendResponseFromServer();

    HttpRequest & getRequest();

    const char * getRequestData();

    int getSocket() const;

    size_t getRequestSize();

    bool hasError() const;

    bool headersComplete() const;

    bool isFinalized() const;

    bool isWaiting() const;

    bool isDirect() const;

    Server * getServer();

    std::string & getUrn();

    bool isRequested();

private:

    ssize_t responsePos;
    int sockFd;
    HttpRequest request;
    std::string requestData;
    char buf[BUF_SIZE];
    http_parser parser;
    http_parser_settings settings;
    Server * server;
    bool requested;
    bool finalized;
    bool error;
    bool waiting;
};


#endif //PROXY_CLIENT_H
