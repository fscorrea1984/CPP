BIN = dijkstra

OBJ = fheap.o dijkstra.o

SRC = fheap.cpp dijkstra.cpp

FLAGS = -ggdb3 -std=c++17 -w

CC = g++

all: fheap.cpp dijkstra.cpp
	$(CC) $(FLAGS) $(SRC) -o $(BIN) -lm
clean:
	rm -f $(BIN) $(OBJ) *~
	clear
