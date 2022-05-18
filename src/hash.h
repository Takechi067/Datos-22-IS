#ifndef hash_h
#define hash_h

#include "librerias.h"
#include "categoria.h"
struct HashMap{
    int maximo; // largo del arreglo
    int cantidad_elementos; // elementos ingresados en el arreglo
    struct Categoria** arreglo_categorias; // 
};
struct HashMap* nuevo_hashmap(int);
int obtener_hash(char*, int);
int obtener_hash_categoria(struct Categoria*);
int obtener_hash_ajustado(struct HashMap* hash, char* string);
int insertar_categoria_hash(struct HashMap*, struct Categoria*);
struct Categoria* buscar_categoria_nombre(struct HashMap*, char*);
int buscar_indice_nombre(struct HashMap*, char*);
struct Categoria* eliminar_categoria_hash(struct HashMap*, char*);
int redimensionar_hash(struct HashMap* hash_parametro, int nuevo_largo);
int imprimir_categorias_hash(struct HashMap*);
struct Categoria* buscar_hash_indice(struct HashMap*, int);
#endif