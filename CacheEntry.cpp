//
// Created by alex on 12.12.18.
//

#include "CacheEntry.h"


CacheEntry::CacheEntry() : full(false) {}

void CacheEntry::append(const char *buf, ssize_t len) {
    data.append(buf, len);
}

void CacheEntry::addClient(int clientSocket) {
    clients.insert(clientSocket);
}

void CacheEntry::removeClient(int clientSocket) {
    clients.erase(clientSocket);
}

std::set<int> &CacheEntry::getClients() {
    return clients;
}

const char *CacheEntry::getData() {
    return data.c_str();
}

size_t CacheEntry::getSize() const {
    return data.size();
}

void CacheEntry::setFull(bool full) {
    CacheEntry::full = full;
}

bool CacheEntry::isFull() {
    return full;
}
