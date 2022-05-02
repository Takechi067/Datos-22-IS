#ifndef categoria_h
#define categoria_h
#include "librerias.h"
#include "lista_doble.h"
struct Categoria{
    char* nombre;
    struct ListaDoble* lista_entradas;
};
struct Categoria* nueva_categoria(char* nombre_categoria);
#endif