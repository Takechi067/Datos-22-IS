#ifndef hash_h
#define hash_h
#include "librerias.h"
#include "categoria.h"
struct HashMap{
    int maximo;
    int cantidad_elementos;
    struct Categoria** arreglo_categorias;
};
struct HashMap* nuevo_hashmap(int);
int obtener_hash(char*, int);
int obtener_hash_categoria(struct Categoria*);
int agregar_categoria(struct HashMap*, struct Categoria*);
#endif