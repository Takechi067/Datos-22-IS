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
int insertar_categoria_hash(struct HashMap*, struct Categoria*);
struct Categoria* buscar_categoria_nombre(struct HashMap*, char*);
#endif