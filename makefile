CC = gcc
FLAGS = -Wall -g
SOURCES = main.c

all: main

run:main
	./$^

main:main.o client.o server.o
	$(CC) $(FLAGS) -o main main.o client.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

server.o: server.c
	$(CC) $(FLAGS) server.c -o server

client.o: client.c
	$(CC) $(FLAGS) -c client.c

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

clean: 
	rm -f *.o *.out main server