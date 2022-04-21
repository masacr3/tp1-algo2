#include "utils.h"

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

void chequea_parametros(int cant_argumentos, char** array_argumentos, bool *ok){
    *ok = ( cant_argumentos == ENTRADA_STANDART || cant_argumentos == LECTURA_ARCHIVO || es_numero(array_argumentos[TAM_BYTES]) );
    if (!*ok) fprintf(stderr, "%s\n","Error: Cantidad erronea de parametros.");
}