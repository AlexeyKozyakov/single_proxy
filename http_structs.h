#ifndef HTTP_STRUCTS_H
#define HTTP_STRUCTS_H

#include <string>
#include <map>

struct HttpExchange {
    HttpExchange() : previousHeader(true), complete(false) {}
    unsigned short http_major;
    unsigned short http_minor;
    std::map<std::string, std::string> headers;
    std::string lastHeaderName;
    std::string lastHeaderValue;
    bool previousHeader;
    bool complete;
    int port;
};

struct HttpRequest : HttpExchange {
    std::string urn;
    std::string uri;
    std::string url;
    unsigned int method : 8;
};

struct HttpResponse : HttpExchange {
    unsigned int status_code : 16;
};

#endif

