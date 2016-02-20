CC=g++
LD=$(CC)
AR=ar

CFLAGS=-I../include -std=c++11
LDFLAGS=-L../lib -ljsoncpp -lcurl -lcurlpp
ARFLAGS=rcs

libttd.a: MapsData.o mapsapi.o
	$(AR) $(ARFLAGS) libttd.a MapsData.o mapsapi.o

MapsData.o: MapsData.cpp
	$(CC) $(CFLAGS) -c MapsData.cpp

mapsapi.o: mapsapi.cpp
	$(CC) $(CFLAGS) -c mapsapi.cpp

clean:
	rm -f *.o *.a
