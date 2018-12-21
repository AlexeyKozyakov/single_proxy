//
// Created by alex on 16.12.18.
//

#ifndef PROXY_PARSER_H
#define PROXY_PARSER_H

#include "http_parser.h"
#include "http_structs.h"


static int uriCallback(http_parser *parser, const char *at, size_t length);

static int headerNameCallback(http_parser * parser, const char * at, size_t length);

static int headerValueCallback(http_parser * parser, const char * at, size_t length);

static int headerCompleteRequestCallback(http_parser * parser);

static int headerCompleteResponseCallback(http_parser * parser);

void initRequestParser(http_parser * requestParser);

void initResponseParser(http_parser * responseParser);

void setupRequestSettings(http_parser_settings * requestSettings);

void setupResponseSettings(http_parser_settings * responseSettings);

#endif //PROXY_PARSER_H
