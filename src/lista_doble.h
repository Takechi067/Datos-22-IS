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
struct ListaDoble* nueva_lista_doble();
//struct ListaDoble* nueva_lista_doble(struct NodoEntrada* pInicio);
struct NodoEntrada* nuevo_nodo_entrada();
struct Entrada* nueva_entrada(char* titulo, char* referencia, char* descripcion);
int insertar_final(struct ListaDoble* plista , struct Entrada* pEntrada);
int imprimir_lista_doble(struct ListaDoble* lista);
int insertar_ordenado(struct ListaDoble* plista, struct Entrada* pEntrada);
struct NodoEntrada* eliminar(struct ListaDoble* plista, char* pEntrada);
struct NodoEntrada* buscar_entrada(struct ListaDoble* pLista, char* pEntrada);
int imprimir_entrada(struct Entrada*);
#endif