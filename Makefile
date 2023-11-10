CC=g++
CFLAGS=-lcpr

all: test.cpp
	$(CC) test.cpp -o meow $(CFLAGS)
