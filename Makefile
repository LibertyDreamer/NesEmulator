CC=g++
CFLAGS=-c -Wall

all:
        $(CC) $(CFLAGS) main.cpp

clean:
        rm -rf *.o hello
