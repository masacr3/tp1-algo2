#include "procesar_archivo.h"

void procesar_linea(char* linea, int tamanio){
    char* linea_actual = linea;
        int k = 0;
        for(int i=0; linea_actual[i] && linea_actual[i] != '\n'; i++){
            if (k == tamanio){
                fprintf(stdout,"\n");
                k=0;
            }
            fprintf(stdout, "%c", linea_actual[i]);
            k++;
        }
}

void evalua_salto_fin_linea(bool *primera_linea){
    if (primero){
            primero = !primero;
        }else{
            fprintf(stdout,"\n");
        }
}

void procesar_archivo(char* corte_bytes, char* stream_, bool es_stdin){
    FILE *stream = es_stdin ? stdin : fopen(stream_, "r");
    if(!stream){
        fprintf(stderr, "%s\n", ERROR_ARCHIVO);
        return;
    }
    int corte = atoi(corte_bytes);
    char* linea = NULL;
    size_t capacidad = 0;
    bool primero = true;
    while(getline(&linea, &capacidad, stream) > 0) {
        primero ? primero = !primero : fprintf(stdout,"\n");
        procesar_linea(linea, corte);
    }
    if(!es_stdin) fclose(stream);
    free(linea);
}