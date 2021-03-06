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
    return numero == 0 ? false : len_numero(numero) == strlen(s);
}

void chequea_parametros(int cant_argumentos, char** array_argumentos, bool *ok){
    *ok = true;
    *ok &= !(cant_argumentos <MIN_PARAMETROS) && !(cant_argumentos>MAX_PARAMETROS) && es_numero(array_argumentos[TAM_BYTES]);
    if (!*ok) fprintf(stderr, "%s\n", ERROR_PARAMETROS);
}