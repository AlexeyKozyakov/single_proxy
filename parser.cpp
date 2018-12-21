//
// Created by alex on 16.12.18.
//

#include <cstdlib>
#include "parser.h"

int uriCallback(http_parser *parser, const char *at, size_t length) {
    HttpRequest * request = (HttpRequest *)parser->data;
    request->uri += std::string(at, 0, length);
    return 0;
}

int headerNameCallback(http_parser *parser, const char *at, size_t length) {
    HttpExchange * exchange = (HttpExchange *)parser->data;
    if (!exchange->previousHeader) {
        exchange->headers[exchange->lastHeaderName] = exchange->lastHeaderValue;
        exchange->lastHeaderName.clear();
        exchange->lastHeaderValue.clear();
    }
    exchange->lastHeaderName += std::string(at, 0, length);
    exchange->previousHeader = true;
    return 0;
}

int headerValueCallback(http_parser *parser, const char *at, size_t length) {
    HttpExchange * exchange = (HttpExchange *)parser->data;
    exchange->lastHeaderValue += std::string(at, 0, length);
    exchange->previousHeader = false;
    return 0;
}

int headerCompleteRequestCallback(http_parser *parser) {
    HttpRequest * request = (HttpRequest *)parser->data;
    if (!request->previousHeader) {
        request->headers[request->lastHeaderName] = request->lastHeaderValue;
        request->lastHeaderName.clear();
        request->lastHeaderValue.clear();
    }
    request->http_major = parser->http_major;
    request->http_minor = parser->http_minor;
    request->complete = true;
    request->method = parser->method;
    request->port = 80;
    std::map<std::string, std::string>::iterator iter = request->headers.find("Host");
    if (iter != request->headers.end()) {
        if (iter->second[0] == '/') {
            request->urn = iter->second + request->uri;
        } else {
            request->urn = request->uri;
        }
        request->url = iter->second;
        size_t index;
        if ((index = request->url.find(':')) != std::string::npos) {
            request->port = atoi(request->url.substr(index + 1, request->url.length() - index - 1).c_str());
        }
    }
    return 0;
}

int headerCompleteResponseCallback(http_parser *parser) {
    HttpResponse * response = (HttpResponse *)parser->data;
    if (!response->previousHeader) {
        response->headers[response->lastHeaderName] = response->lastHeaderValue;
        response->lastHeaderName.clear();
        response->lastHeaderValue.clear();
    }
    response->http_major = parser->http_major;
    response->http_minor = parser->http_minor;
    response->complete = true;
    response->status_code = parser->status_code;
    return 0;
}

void initRequestParser(http_parser *requestParser) {
    http_parser_init(requestParser, HTTP_REQUEST);
}

void initResponseParser(http_parser *responseParser) {
    http_parser_init(responseParser, HTTP_RESPONSE);
}

void setNotUsedCallbacks(http_parser_settings *requestSettings) {
    requestSettings->on_message_complete = NULL;
    requestSettings->on_body = NULL;
    requestSettings->on_chunk_complete = NULL;
    requestSettings->on_chunk_header = NULL;
    requestSettings->on_message_begin = NULL;
    requestSettings->on_status = NULL;
}

void setupRequestSettings(http_parser_settings *requestSettings) {
    requestSettings->on_url = uriCallback;
    requestSettings->on_header_field = headerNameCallback;
    requestSettings->on_header_value = headerValueCallback;
    requestSettings->on_headers_complete = headerCompleteRequestCallback;
    setNotUsedCallbacks(requestSettings);
}

void setupResponseSettings(http_parser_settings *responseSettings) {
    responseSettings->on_header_field = headerNameCallback;
    responseSettings->on_header_value = headerValueCallback;
    responseSettings->on_headers_complete = headerCompleteResponseCallback;
    setNotUsedCallbacks(responseSettings);
}
