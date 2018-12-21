//
// Created by alex on 12.12.18.
//

#ifndef PROXY_SELECTOR_H
#define PROXY_SELECTOR_H


#include <sys/socket.h>
#include <stdio.h>
#include <poll.h>
#include <vector>
#include <cstdio>
#include <set>
#include <map>


class Selector {

public:

    Selector();

    int doPoll();

    std::vector<pollfd> & getDescriptors();

    void registerFd(int fd, short requestedEvents);

    void unregisterFd(ssize_t fdNum);

    pollfd & getPollfd(int socket);

    size_t getIndex(int fd);

    void clearInvalid();

private:

    std::vector<pollfd> descriptors;
    std::map<int, size_t > descToIndex;
    int timeout;
    pollfd invalid;

};


#endif //PROXY_SELECTOR_H
