#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ENTRADA_STANDART 2
#define LECTURA_ARCHIVO 3
#define TAM_BYTES 1

size_t len_numero(int n){
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
    int numero = atoi(s);
    return numero == 0 ? strcmp("0", s) == 0 : len_numero(numero) == strlen(s);
}

void checkea_parametros(int cant_argumentos, char** array_argumentos, bool *ok){
    *ok = ( cant_argumentos == ENTRADA_STANDART || cant_argumentos == LECTURA_ARCHIVO || es_numero(array_argumentos[TAM_BYTES]) );
    if (!*ok) fprintf(stderr, "%s\n","Error: Cantidad erronea de parametros.");
}

void procesar_linea(char* linea, int corte){
    char* linea_actual = linea;
        int k = 0;
        for(int i=0; linea_actual[i]; i++){
            if (k == corte){
                fprintf(stdout,"\n");
                k=0;
            }
            fprintf(stdout, "%c", linea_actual[i]);
            k++;
        }
}

void procesar_archivo(char* corte_bytes, char* stream_, bool es_stdin){
    FILE *stream = es_stdin ? stdin : fopen(stream_, "r");
    if(!stream){
        fprintf(stderr, "%s\n","Error: archivo fuente inaccesible.");
        return;
    }
    int corte = atoi(corte_bytes);
    char* linea = NULL;
    size_t capacidad = 0;
    while(getline(&linea, &capacidad, stream) > 0) procesar_linea(linea, corte);
    if(!es_stdin) fclose(stream);
    free(linea);
}

void fixcol(int cant_argumentos, char** argumentos ){
    bool ok;
    chequea_parametros(cant_argumentos, argumentos, &ok);
    if (ok) procesar_archivo(argumentos[TAM_BYTES], cant_argumentos == ENTRADA_STANDART ? NULL : argumentos[LECTURA_ARCHIVO], cant_argumentos == ENTRADA_STANDART);

}

int main(int argc, char** argv){
    fixcol(argc,argv);
    return 0;
}