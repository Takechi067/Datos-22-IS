#include "lista_doble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include <string.h>

struct ListaDoble{
    struct NodoEntrada* inicio;
};

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

int insertar_final(struct ListaDoble* plista , struct Entrada* pEntrada){
    if(plista == NULL){
        return -1;
    }
    if(plista -> inicio == NULL){
        struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));
        nNodo -> entrada = pEntrada;
        plista -> inicio = nNodo;

        return 0;
    }

    else{
        struct NodoEntrada* actual;

        actual = plista -> inicio;

        while(actual != NULL){
            if(actual -> siguiente == NULL){
                struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));
                nNodo -> entrada = pEntrada;
                actual -> siguiente = nNodo;
                nNodo -> anterior = actual;
                return 0;

            }
            actual = actual -> siguiente;
        }
    }
}

int insertar_ordenado(struct ListaDoble* plista, struct Entrada* pEntrada){
    if(plista == NULL){
        return -1;
    }

    if(plista -> inicio == NULL){
        struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));
        nNodo -> entrada = pEntrada;
        plista -> inicio = nNodo;

        return 0;
    }

    else{

        struct NodoEntrada* actual = plista -> inicio;
        //Recorre la lista 
        while(actual != NULL){
            
            pEntrada -> nombre;

            if(strcmp(pEntrada -> nombre, actual -> entrada -> nombre) <= 0){

                struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));
                nNodo -> entrada = pEntrada;

                struct NodoEntrada* temporal =  actual -> anterior;

                actual -> anterior = nNodo;
                temporal -> siguiente = nNodo;
                nNodo -> anterior = temporal;
                nNodo -> siguiente = actual;

            }

            //Estando en la posicion actaual pasa a la siguiente posicion
            actual = actual -> siguiente;
        }

    }
}

int eliminar(struct ListaDoble* pLista, struct Entrada* pEntrada){
    if(plista == NULL){
        return -1;
    }
    if(plista -> inicio == NULL){
        return -1;
    }
    else{
        struct NodoEntrada* actual = pLista-> inicio;

        while(actual != NULL){
            if(actual -> siguiente -> entrada == pEntrada){
                struct NodoEntrada* temp = actual ->siguiente;

                actual -> siguiente = temp -> siguiente;
                temp ->siguiente->anterior = actual;

                return 0;
            }
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

