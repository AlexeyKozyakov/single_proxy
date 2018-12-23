all:
	g++ -lsocket -lnsl -lresolv CacheEntry.cpp CacheEntry.h Client.cpp Client.h MyProxy.cpp MyProxy.h Selector.cpp Selector.h Server.cpp Server.h constants.h http_parser.c http_parser.h http_structs.h main.cpp parser.cpp parser.h -o proxy

