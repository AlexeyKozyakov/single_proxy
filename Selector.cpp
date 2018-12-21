//
// Created by alex on 12.12.18.
//

#include "Selector.h"

Selector::Selector() : timeout(-1) {
    invalid.fd = -1;
    invalid.events = 0;
    invalid.revents = 0;
}

int Selector::doPoll() {
    int retVal = poll(&descriptors.front(), descriptors.size(), timeout);
    if (retVal < 0) {
        perror("Error in poll");
    }
    return retVal;
}

std::vector<pollfd> & Selector::getDescriptors() {
    return descriptors;
}

void Selector::registerFd(int fd, short requestedEvents) {
    pollfd desc;
    desc.fd = fd;
    desc.events = requestedEvents;
    desc.revents = 0;
    descriptors.push_back(desc);
    descToIndex[fd] = descriptors.size() - 1;
}

void Selector::unregisterFd(ssize_t fdNum) {
    descToIndex.erase(descriptors[fdNum].fd);
    descriptors[fdNum] = invalid;
}

pollfd &Selector::getPollfd(int socket) {
    return descriptors[descToIndex[socket]];
}

size_t Selector::getIndex(int fd) {
    return descToIndex[fd];
}

void Selector::clearInvalid() {
    for (int i = descriptors.size() - 1; i >= 0; i--) {
        if (descriptors[i].fd == -1) {
            descriptors[i] = descriptors[descriptors.size() - 1];
            descToIndex[descriptors[i].fd] = i;
            descriptors.pop_back();
        }
    }
}
