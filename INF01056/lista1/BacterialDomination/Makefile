BIN = bacdom

OBJ = bacdom.o

SRC = bacdom.cpp

FLAGS = -g -w -std=c++17

CC = g++

test5: grid.cpp test5.cpp
	$(CC) $(FLAGS) grid.cpp test5.cpp -o test5

test4: grid.cpp test4.cpp
	$(CC) $(FLAGS) grid.cpp test4.cpp -o test4

test3: test3.cpp
	$(CC) $(FLAGS) test3.cpp -o test3

test2: test2.cpp
	$(CC) $(FLAGS) test2.cpp -o test2

test1: test1.cpp
	$(CC) $(FLAGS) test1.cpp -o test1

all: bacdom.cpp
	$(CC) $(FLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf $(BIN) $(OBJ) *~ test1 test2 test3 test4 test5
	clear
