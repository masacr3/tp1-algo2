#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv){

    //chequeo cantidad parametros
    if ( !(argc == 2 || argc == 3 ) ){
        fprintf(stdin, "%s\n","Error: Cantidad erronea de parametros.");
        return 0;
    }

    char* linea = NULL;
    size_t capacidad = 0;

    for(int i=0; getline(&linea, &capacidad, stdin) > 0; i++){
        char* linea_actual = linea;

        fprintf(stdout, "%s\n", linea_actual);
    }

    free(linea);

    return 0;
}