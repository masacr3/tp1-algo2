#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ERROR_PARAMETROS "Error: Cantidad erronea de parametros"
#define MAX_PARAMETROS 3
#define MIN_PARAMETROS 2
#define ENTRADA_STANDART 2
#define TAM_BYTES 1
#define RUTA_ARCHIVO 2

/* calcula la cantidad de caracteres de un numero
 * (obs) si el numero es negativo se tiene encuenta el menos como un caracter
 */ 
size_t len_numero(int n);

/* verifica que si la cadena es un numero*/
bool es_numero(char* s);

/* Evalua si los parametros ingresados por consola son validos
 * para ejecutar fixcol
 * 
 *      cant_argumentos = argc
 *      array_argumentos = argv
 * 
 *      en "ok" se va a cargar el resultado si paso el checkin 
 *      siendo 
 *              true -> Paso el checkin
 *              false -> Parametros invalidos
 */
void chequea_parametros(int cant_argumentos, char** array_argumentos, bool *ok);