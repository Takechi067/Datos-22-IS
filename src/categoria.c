#include "categoria.h"

struct Categoria* nueva_categoria(char* nombre_categoria){
    struct Categoria* miNuevaCategoria = calloc(1, sizeof(struct Categoria));
    miNuevaCategoria->nombre = nombre_categoria;
    miNuevaCategoria->lista_entradas = nueva_lista_doble();
    return miNuevaCategoria;
}
