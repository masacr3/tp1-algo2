EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = fixcol.c utils.c procesar_archivo.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC) 75 l.txt > fixed.txt
	./$(EXEC) 75 < l.txt > fixed2.txt
	diff fixed.txt fixed2.txt | wc

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC) 