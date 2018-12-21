cmake_minimum_required(VERSION 3.12)
project(proxy)

set(CMAKE_CXX_STANDARD 98)

add_executable(proxy main.cpp Selector.cpp Selector.h CacheEntry.cpp CacheEntry.h MyProxy.cpp MyProxy.h Client.cpp Client.h constants.h Server.cpp Server.h http_parser.h http_parser.c http_structs.h parser.h parser.cpp)