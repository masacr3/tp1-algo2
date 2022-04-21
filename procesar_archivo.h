#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Aplica un salto de linea al llegar a un "TAMANIO" dado de caracteres
 * el mismo se seguira aplicando tantas hasta llegar hasta un salto de linea en la linea a procesar
 * la visualizacion del mismo es por "stdout" (salida standart)
 */
void procesar_linea(char* linea, int tamanio);


/* Procesa un archivo que puede ser por: 
 * 
 *         stdin (entrada standart)
 *         archivo
 * 
 * y este procesara las lineas correspondientes
 * 
 *      corte_bytes = es el tamanio que deven tener las lineas para cortar
 *      stream_ = nombre del archivo
 *      es_stdin = si al procesar el archivo la fuente se tomara desde stdin o archivo
 * 
 * si al procesar un archivo no puede abrirlo , o es incaccesible o otro tipo de error
 * este sera reflejado por "stderr" (salida standart error) 
 */
void procesar_archivo(char* corte_bytes, char* stream_, bool es_stdin);