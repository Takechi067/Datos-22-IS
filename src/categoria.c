#include "categoria.h"

struct Categoria* nueva_categoria(char* nombre_categoria){
    struct Categoria* miNuevaCategoria = calloc(1, sizeof(struct Categoria));
    miNuevaCategoria->nombre = nombre_categoria;
    miNuevaCategoria->lista_entradas = nueva_lista_doble();
    return miNuevaCategoria;
}
int imprimir_categoria(struct Categoria* categoria){
    if(categoria!= NULL){
    printf("Categoria: %s\n",categoria->nombre);
    printf("Entradas:\n");
    imprimir_lista_doble(categoria->lista_entradas);
    }
    else{
        printf("La categoria no existe\n");
    }

}