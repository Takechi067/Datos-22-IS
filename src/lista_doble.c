#include "lista_doble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

struct ListaDoble* nueva_lista_doble(struct NodoEntrada* pInicio){
    struct ListaDoble* n_lista = calloc(1, sizeof(struct ListaDoble));
    n_lista->inicio = pInicio;
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
        return 0;
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
        return 0;
    }
}

int eliminar(struct ListaDoble* pLista, char* pEntrada){
    if(pLista == NULL){
        return -1;
    }
    if(pLista -> inicio == NULL){
        return -1;
    }
    else{
        struct NodoEntrada* actual = pLista-> inicio;

        while(actual != NULL){
            if(strcmp(actual -> entrada ->categoria, pEntrada) == 0){
                struct NodoEntrada* anterior = actual -> anterior;
                struct NodoEntrada* siguiente = actual -> siguiente;
                anterior ->siguiente = siguiente;
                siguiente ->anterior = anterior;
                free(actual);
                actual = NULL;
                return 0;
            }
            actual = actual ->siguiente;
        }

    }

}

int imprimir_lista_doble(struct ListaDoble* lista){
    if(lista == NULL){
        printf("Vacia");
        
        return -1;

    }else{
        struct NodoEntrada* actual = calloc(1, sizeof(struct NodoEntrada));
        actual = lista -> inicio;

        while(actual != NULL){
            // salto de linea
            printf("%s\n", actual -> entrada -> nombre);

            actual = actual -> siguiente;
        }
        return 0;
    }
}

int main(){
    struct NodoEntrada* entrada1 = calloc(1, sizeof(struct NodoEntrada));
    entrada1 ->entrada = nueva_entrada("Entretenimiento solarpunk", "Peliculas", "peliculas como pokemon y series como arkane");

    struct NodoEntrada* entrada2 = calloc(1, sizeof(struct NodoEntrada));
    entrada2 ->entrada = nueva_entrada("soluciones desde el anarquismo solarpunk", "arquitectura solarpunk", "creacion de edificios de bajo impacto ambiental");

    struct ListaDoble* lista1 = calloc(1, sizeof(struct ListaDoble));
    insertar_final(lista1, nueva_entrada("soluciones desde el anarquismo solarpunk", "arquitectura solarpunk", "creacion de edificios de bajo impacto ambiental"));
    insertar_final(lista1, nueva_entrada("estado de la emergencia", "desplazados climaticos", "psersonas que se ven obligadas a abandonar su hogar"));
    insertar_final(lista1, nueva_entrada("entretenimiento", "Peliculas", "pokemon"));
    eliminar(lista1, "entretenimiento");
    imprimir_lista_doble(lista1);

    return 0;
}