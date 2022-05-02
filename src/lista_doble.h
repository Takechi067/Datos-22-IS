#ifndef lista_doble_h
#define lista_doble_h
#include "librerias.h"
#include "entrada.h"


struct ListaDoble{
    struct NodoEntrada* inicio;
};

struct ListaDoble* nueva_lista_doble();
struct Entrada* nueva_entrada(char* pCategoria, char* pNombre, char* pInfo);
int insertar_final(struct ListaDoble* plista , struct Entrada* nEntrada);
int imprimir_lista_doble(struct ListaDoble* lista);

#endif