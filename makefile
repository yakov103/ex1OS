CC = gcc
FLAGS = -Wall -g
SOURCES = main.c

all: main

main:main.o
	$(CC) $(FLAGS) -o main main.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

clean: 
	rm -f *.o *.out main