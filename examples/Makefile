
mapstest: mapstest.o
	g++ mapstest.o -L../lib -ljsoncpp -lcurl -lcurlpp -o mapstest

mapstest.o: mapstest.cpp
	g++ -I../include -std=c++11 -c mapstest.cpp
