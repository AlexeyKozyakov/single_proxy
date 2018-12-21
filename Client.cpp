//
// Created by alex on 13.12.18.
//

#include "Client.h"

Client::Client(int sockFd) :
    responsePos(0), sockFd(sockFd), server(NULL), requested(false), finalized(false), error(false),
        waiting(false) {
    initRequestParser(&parser);
    setupRequestSettings(&settings);
    request.complete = false;
}

void Client::receiveRequest() {
    ssize_t len = read(sockFd,buf, BUF_SIZE);
    if (len < 0) {
        error = true;
        perror("Error in client: receive");
    } else if (len == 0) {
        requested = true;
    } else {
        std::string requestPart(buf, 0, len);
        requestData.append(requestPart);
        parser.data = &request;
        ssize_t parsed = http_parser_execute(&parser, &settings, buf, len);
        if (request.complete) {
            size_t connectionPos = requestData.find("Connection:");
            if (connectionPos != std::string::npos) {
                ssize_t connectionEnd = requestData.find("\n", connectionPos);
                if (connectionEnd != std::string::npos) {
                    requestData.replace(connectionPos, connectionEnd + 1 - connectionPos, "Connection: close\r\n");
                }
            }
        }
        if (parsed != len) {
            error = true;
        }
    }
}

void Client::sendResponseFromCache(CacheEntry & entry) {
    waiting = false;
    if (entry.isFull() && responsePos == entry.getSize()) {
        finalized = true;
    } else if (responsePos >= entry.getSize()) {
        waiting = true;
    } else {
        ssize_t len = write(sockFd, entry.getData() + responsePos, entry.getSize() - responsePos);
        if (len < 0) {
            error = true;
        } else {
            responsePos += len;
        }
    }
}

void Client::sendResponseFromServer() {
    waiting = false;
    if (server->isRespond() && !server->hasData()) {
        finalized = true;
    } else {
        if (server->hasData()) {
            ssize_t len = write(sockFd, server->getData(), server->getDataLen());
            if (len < 0) {
                error = true;
                perror("Error in client: send");
            } else {
                if (len > 0) {
                    server->eraseData(len);
                    responsePos += len;
                }
            }
        } else {
            waiting = true;
        }
    }
}

HttpRequest &Client::getRequest() {
    return request;
}

int Client::getSocket() const {
    return sockFd;
}

const char * Client::getRequestData() {
    return requestData.c_str();
}

bool Client::hasError() const {
    return error;
}

bool Client::headersComplete() const {
    return request.complete;
}

bool Client::isFinalized() const {
    return finalized;
}

bool Client::isWaiting() const {
    return waiting;
}

bool Client::isDirect() const {
    if (server == NULL) {
        return false;
    }
    return server->isDirect();
}

size_t Client::getRequestSize() {
    return requestData.size();
}

void Client::setServer(Server &server) {
    this->server = &server;
}

Server *Client::getServer() {
    return server;
}

std::string &Client::getUrn() {
    return request.urn;
}

bool Client::isRequested() {
    return requested;
}
