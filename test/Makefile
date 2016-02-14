INC_DIR=../include
LIB_DIR=../lib
SRC_DIR=../src
TEST_LIB_DIR=lib

CC=g++
LD=$(CC)

CFLAGS=-I$(INC_DIR) -std=c++11
LDFLAGS=-L$(LIB_DIR) -L$(SRC_DIR) -L$(TEST_LIB_DIR) -lttd -ljsoncpp -lcurl -lcurlpp -lgtest

tests: MapsDataTest

MapsDataTest: MapsDataTest.o libttd.a
	$(LD) MapsDataTest.o $(LDFLAGS) -o MapsDataTest

MapsDataTest.o: MapsDataTest.cpp
	$(CC) $(CFLAGS) -c MapsDataTest.cpp

libttd.a:
	$(MAKE) -C $(SRC_DIR) libttd.a
