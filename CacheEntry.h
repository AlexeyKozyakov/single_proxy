//
// Created by alex on 12.12.18.
//

#ifndef PROXY_CACHEENTRY_H
#define PROXY_CACHEENTRY_H


#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "Selector.h"
#include "http_structs.h"
#include "constants.h"

class CacheEntry {

public:

    CacheEntry();

    void append(const char * buf, ssize_t len);

    void addClient(int clientSocket);

    void removeClient(int clientSocket);

    std::set<int> & getClients();

    const char * getData();

    size_t getSize() const;

    void setFull(bool full);

    bool isFull();

private:

    bool full;
    std::string data;
    std::set<int> clients;

};


#endif //PROXY_CACHEENTRY_H
