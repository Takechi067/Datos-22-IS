#ifndef lista_doble_h
#define lista_doble_h
#include "librerias.h"
#include "entrada.h"

struct NodoEntrada;
struct NodoEntrada{
	struct Entrada* entrada;
	struct NodoEntrada* siguiente;
	struct NodoEntrada* anterior;
};

struct ListaDoble{
    struct NodoEntrada* inicio;
};

struct ListaDoble* nueva_lista_doble(struct NodoEntrada* pInicio);
struct Entrada* nueva_entrada(char* pCategoria, char* pNombre, char* pInfo);
int insertar_final(struct ListaDoble* plista , struct Entrada* pEntrada);
int imprimir_lista_doble(struct ListaDoble* lista);
int insertar_ordenado(struct ListaDoble* plista, struct Entrada* pEntrada);
int eliminar(struct ListaDoble* plista, char* pEntrada);

#endif