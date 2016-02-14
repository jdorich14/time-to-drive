INC_DIR=../include
LIB_DIR=../lib
SRC_DIR=../src
TEST_INC_DIR=include
TEST_LIB_DIR=lib

CC=g++
LD=$(CC)

CFLAGS=-I$(INC_DIR) -I$(TEST_INC_DIR) -std=c++11
LDFLAGS=-L$(LIB_DIR) -L$(SRC_DIR) -L$(TEST_LIB_DIR) -lttd -ljsoncpp -lcurl -lcurlpp -lgtest

tests: bindir MapsDataTest

MapsDataTest: MapsDataTest.o libttd.a
	$(LD) MapsDataTest.o $(LDFLAGS) -o bin/MapsDataTest

MapsDataTest.o: MapsDataTest.cpp
	$(CC) $(CFLAGS) -c MapsDataTest.cpp

clean:
	$(MAKE) -C $(SRC_DIR) clean
	rm -rf *.o bin

bindir:
	mkdir -p bin

libttd.a:
	$(MAKE) -C $(SRC_DIR) libttd.a
