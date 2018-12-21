// Created by alex on 15.12.18.

#include "Server.h"

Server::Server(int sockFd, Client & client) : sockFd(sockFd), client(&client), respond(false),
        requestPos(0), error(false), direct(false), requested(false) {
    initResponseParser(&parser);
    setupResponseSettings(&settings);
    response.complete = false;
    urn = client.getUrn();
}


void Server::sendRequest() {
    ssize_t len = write(sockFd, client->getRequestData() + requestPos, client->getRequestSize() - requestPos);
    if (len < 0) {
        error = true;
        perror("Error in server: send");
    } else {
        requestPos += len;
        if (requestPos == client->getRequestSize()) {
            requested = true;
        }
    }
}


void Server::receiveResponseToCache(CacheEntry & entry) {
    ssize_t len = read(sockFd, buf, BUF_SIZE);
    if (len < 0) {
        error = true;
        perror("Error in server: receive to cache");
    } else if (len == 0) {
        respond = true;
        entry.setFull(true);
    } else {
        entry.append(buf, len);
    }
}

void Server::receiveResponseToBuf() {
    ssize_t len = read(sockFd, buf, BUF_SIZE);
    if (len < 0) {
        error = true;
        perror("Error in server: receive to buffer");
    } else if (len == 0) {
        respond = true;
    } else {
        responseData.append(buf, len);
        if (!response.complete) {
            parser.data = &response;
            ssize_t parsed = http_parser_execute(&parser, &settings, buf, len);
            if (parsed != len) {
                error = true;
            }
        }
    }
}

HttpResponse &Server::getResponse() {
    return response;
}

bool Server::headersComplete() {
    return response.complete;
}

std::string &Server::getResponseData() {
    return responseData;
}

int Server::getSocket() {
    return sockFd;
}

bool Server::hasError() {
    return error;
}

bool Server::isRespond() {
    return respond;
}

bool Server::isDirect() {
    return direct;
}

void Server::setDirect(bool direct) {
    this->direct = direct;
}

bool Server::hasData() {
    return !responseData.empty();
}

const char *Server::getData() {
    return responseData.c_str();
}

size_t Server::getDataLen() {
    return responseData.size();
}

void Server::eraseData(size_t len) {
    responseData.erase(0, len);
}

std::string &Server::getUrn() {
    return urn;
}

Client *Server::getClient() {
    return client;
}

bool Server::isRequested() const {
    return requested;
}
