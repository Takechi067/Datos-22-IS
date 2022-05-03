#include "lista_doble.h"


struct ListaDoble* nueva_lista_doble(){
    struct ListaDoble* n_lista = calloc(1, sizeof(struct ListaDoble));
    n_lista->inicio = calloc(1, sizeof(struct NodoEntrada));
    return n_lista;
}
struct Entrada* nueva_entrada(char* pCategoria, char* pNombre, char* pInfo){
    struct Entrada* nEntrada = calloc(1, sizeof(struct Entrada));

    nEntrada -> categoria = pCategoria;
    nEntrada -> nombre = pNombre;
    nEntrada -> informacion = pInfo;

    return nEntrada;
}


int insertar_final(struct ListaDoble* plista , struct Entrada* nEntrada){
    if(plista == NULL){
        return -1;

    }
    if(plista -> inicio == NULL){
        struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));

        nNodo -> entrada = nEntrada;

        plista -> inicio = nNodo;

        return 0;

    }else{
        struct NodoEntrada* actual = calloc(1, sizeof(struct NodoEntrada));

        actual = plista -> inicio;

        while(actual != NULL){
            if(actual -> siguiente == NULL){
                struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));

                nNodo -> entrada = nEntrada;

                actual -> siguiente = nNodo;

                nNodo -> anterior = actual;

                return 0;

            }
            actual = actual -> siguiente;
        }

    }

}

int imprimir_lista_doble(struct ListaDoble* lista){
    if(lista == NULL){
        printf("Vacia");
        
        return 0;

    }else{
        struct NodoEntrada* actual = calloc(1, sizeof(struct NodoEntrada));
        actual = lista -> inicio;

        while(actual != NULL){
            // salto de linea
            printf("%s\n", actual -> entrada -> nombre);

            actual = actual -> siguiente;
        }
    }
}

