#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    char* linea = NULL;
    size_t capacidad = 0;

    for(int i=0; getline(&linea, &capacidad, stdin) > 0; i++){
        char* linea_actual = linea;

        fprintf(stdout, "%s\n", linea_actual);
    }

    free(linea);

    return 0;
}