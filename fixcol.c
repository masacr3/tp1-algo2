#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

size_t lenn(int n){
    if (n == 0) return 1;
    size_t cont = n < 0 ? 1 : 0;
    n = n < 0 ? n*-1 : n;
    size_t l = 1; 
    while ( n >= l) { 
        l *= 10;
        cont++;
    }
    return cont;
}

bool es_numero(char* s){
    int a = atoi(s);
    return a == 0 ? strcmp("0", s) == 0 : lenn(a) == strlen(s);
}

int main(int argc, char** argv){

    //chequeo cantidad parametros
    if ( !(argc == 2 || argc == 3 ) ){
        fprintf(stderr, "%s\n","Error: Cantidad erronea de parametros.");
        return 0;
    }

    //chequeo que el 2 parametro sea numero
    if ( !es_numero(argv[1]) ){
        fprintf(stderr, "%s\n","Error: Cantidad erronea de parametros.");
        return 0;
    }

    int corte = atoi(argv[1]);
    char* linea = NULL;
    size_t capacidad = 0;

    while(getline(&linea, &capacidad, stdin) > 0){
        char* linea_actual = linea;
        int k = 0;
        for(int i=0; linea_actual[i]; i++){
            k = i;
            if (k < corte){
                fprintf(stdout,"\n");
                k=0;
            }
            fprintf(stdout, "%c", linea_actual[i]);
        }
    }

    free(linea);

    return 0;
}