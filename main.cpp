#include <iostream>
#include <stdlib.h>
#include <csignal>
#include "MyProxy.h"

MyProxy * proxy;

void signalHandler( int signum ) {
    proxy->stop();
    delete proxy;
    exit(0);
}


int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cerr << "Wrong program arguments\nUsage: " << argv[0] << " <port>\n";
        return 0;
    }
    int port = atoi(argv[1]);
    proxy = new MyProxy(port);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT, signalHandler);
    proxy->start();
    return 0;
}
