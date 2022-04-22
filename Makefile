EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = fixcol.c utils.c procesar_archivo.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC) 5 l.txt > fixed.txt
	echo "\n"
	./$(EXEC) 5 < l.txt > fixed2.txt
	diff fixed.txt fixed2.txt | wc
	diff fixed.txt rta.txt | wc
	diff fixed2.txt rta.txt | wc

test: all
	./$(EXEC) 5 l.txt
	./$(EXEC) 5 < l.txt
	./$(EXEC) 5 rta.txt

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC) 5 l.txt

zipping:
	rm tp1.zip
	zip tp1.zip fixcol.c procesar_archivo.* utils.* deps.mk 