#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "procesar_archivo.h"
#define ENTRADA_STANDART 2
#define LECTURA_ARCHIVO 3
#define TAM_BYTES 1

void fixcol(int cant_argumentos, char** argumentos ){
    bool ok;
    chequea_parametros(cant_argumentos, argumentos, &ok);
    if (ok) procesar_archivo(argumentos[TAM_BYTES], cant_argumentos == ENTRADA_STANDART ? NULL : argumentos[LECTURA_ARCHIVO], cant_argumentos == ENTRADA_STANDART);

}

int main(int argc, char** argv){
    fixcol(argc,argv);
    return 0;
}