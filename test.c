#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


int main(){
    char* data[6] = { "hola", "23", "-23", "0", "-23a", "2a3"};

    for(int i=0; i<6; i++){
        if ( ! es_numero(data[i]) ){
            fprintf(stdout, "%s\n","Error: Cantidad erronea de parametros.");
        }
    }
    return 0;
}