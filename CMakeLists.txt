cmake_minimum_required(VERSION 3.13)
project(single_proxy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(single_proxy
        CacheEntry.cpp
        CacheEntry.h
        Client.cpp
        Client.h
        constants.h
        http_parser.c
        http_parser.h
        http_structs.h
        main.cpp
        MyProxy.cpp
        MyProxy.h
        parser.cpp
        parser.h
        Selector.cpp
        Selector.h
        Server.cpp
        Server.h)
