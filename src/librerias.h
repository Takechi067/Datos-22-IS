#ifndef librerias_h
#define librerias_h
#include <stdio.h>  // fgets
#include <stdlib.h> // calloc
#include <string.h> // strlen
#include <ctype.h> // tolower

int a_minuscula(char* str);

int comparar_strings(char* c1, char* c2);

int texto_salida(char*);
int eliminar_nueva_linea(char * string);
int validar_largo_texto(char*, int minimo, int maximo);
char* leer_consola(int);
int flush_buffer();
#endif