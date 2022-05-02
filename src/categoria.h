#ifndef categoria_h
#define categoria_h
#include "librerias.h"
struct Categoria{
    char* nombre;
    struct Lista* lista_entradas;
};
struct Categoria* nueva_categoria(char* nombre_categoria);
#endif