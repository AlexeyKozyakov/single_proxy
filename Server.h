//
// Created by alex on 15.12.18.
//

#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H


#include <unistd.h>
#include <stdio.h>
#include "constants.h"
#include "CacheEntry.h"
#include "parser.h"
#include "Client.h"

class Client;

class Server {

public:

    Server(int sockFd, Client & client);

    void sendRequest();

    void receiveResponseToCache(CacheEntry & entry);

    void receiveResponseToBuf();

    std::string & getResponseData();

    HttpResponse & getResponse();

    bool headersComplete();

    int getSocket();

    bool hasError();

    bool isRespond();

    bool isDirect();

    void setDirect(bool direct);

    bool hasData();

    const char * getData();

    size_t getDataLen();

    void eraseData(size_t len);

    std::string & getUrn();

    Client * getClient();

    bool isRequested() const;

private:

    int sockFd;
    size_t requestPos;
    HttpResponse response;
    std::string responseData;
    http_parser parser;
    http_parser_settings settings;
    Client * client;
    std::string urn;
    char buf[BUF_SIZE];
    bool respond;
    bool error;
    bool direct;
    bool requested;
};


#endif //PROXY_SERVER_H
