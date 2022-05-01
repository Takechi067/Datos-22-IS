
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
struct Lista{
    struct NodoEntrada* inicio;
};

int crearEntrada(char* pCategoria, char* pNombre, char* pInfo){
    struct Entrada* nEntrada = calloc(1, sizeof(struct Entrada));

    nEntrada -> categoria = pCategoria;
    nEntrada -> nombre = pNombre;
    nEntrada -> informacion = pInfo;

    return 0;
}


int insertarFin(struct Lista* plista , struct Entrada* nEntrada){
    if(plista == NULL){
        return -1;

    }if(plista -> inicio == NULL){
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

int imprimirLista(struct Lista* lista){
    if(lista == NULL){
        printf("Vacia");
        
        return 0;

    }else{
        struct NodoEntrada* actual = calloc(1, sizeof(struct NodoEntrada));
        actual = lista -> inicio;

        while(actual != NULL){
            printf("%s", actual -> entrada -> nombre);

            actual = actual -> siguiente;
        }
    }
}

int main(){
    crearEntrada("Entretenimiento solarpunk", "peliculas", "algunas peliculas solar punk son pokemon");


    return 0;
    
}

/*
int main(){
    char* Entretenmiento = calloc(80, sizeof(char));
    strcpy(Entretenmiento, "Entretenimiento Solarpunk");

    char* peliculas = calloc(80, sizeof(char));
    strcpy(peliculas, "peliculas");

    char* info = calloc(80, sizeof(char));
    strcpy(info, "estudio ghibli ");

    struct Entrada* entrada1 = calloc(1, sizeof(struct Entrada));

    entrada1 -> nombre = Entretenmiento;
    entrada1 -> categoria = peliculas;
    entrada1 -> informacion = info;
    return 0;
}*/