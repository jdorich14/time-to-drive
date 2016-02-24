OBJ_DIR=build
BIN_DIR=bin

CC=g++
CFLAGS=-I../include -std=c++11
LDFLAGS=-L../lib -ljsoncpp -lcurl -lcurlpp

examples: dirs mapstest

mapstest: $(OBJ_DIR)/mapstest.o
	$(CC) $(OBJ_DIR)/mapstest.o $(LDFLAGS) -o $(BIN_DIR)/mapstest

$(OBJ_DIR)/mapstest.o: mapstest.cpp
	$(CC) $(CFLAGS) -c mapstest.cpp -o $(OBJ_DIR)/mapstest.o

dirs:
	mkdir -p bin build

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)