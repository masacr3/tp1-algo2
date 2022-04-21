EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = fixcol.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	echo "mati pedazo de gato" | ./$(EXEC) 3

valgrind: all
	valgrind $(VFLAGS) echo "mati pedazo de gato" | ./$(EXEC) 3