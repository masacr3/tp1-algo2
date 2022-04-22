EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = fixcol.c utils.c procesar_archivo.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	echo "esto es un ejemplo" | ./$(EXEC) 5

valgrind: all
	valgrind $(VFLAGS) echo "esto es un ejemplo" | ./$(EXEC) 5

zipping:
	rm tp1.zip
	zip tp1.zip fixcol.c procesar_archivo.* utils.* deps.mk 