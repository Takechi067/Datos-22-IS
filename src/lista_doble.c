#include "lista_doble.h"

struct ListaDoble* nueva_lista_doble(){
    struct ListaDoble* n_lista = calloc(1, sizeof(struct ListaDoble));
    return n_lista;
}
/*
struct ListaDoble* nueva_lista_doble(struct NodoEntrada* pInicio){
    struct ListaDoble* n_lista = calloc(1, sizeof(struct ListaDoble));
    n_lista->inicio = pInicio;
    return n_lista;
}
*/
struct NodoEntrada* nuevo_nodo_entrada(){
    struct NodoEntrada* nuevo = calloc(1, sizeof(struct NodoEntrada));
    return nuevo;
}
struct Entrada* nueva_entrada(char* titulo, char* referencia, char* descripcion){
    struct Entrada* n_entrada = calloc(1, sizeof(struct Entrada));

    //nEntrada -> categoria = pCategoria;
    n_entrada -> titulo = titulo;
    n_entrada -> referencia = referencia;
    n_entrada -> descripcion = descripcion; 

    return n_entrada;
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
    // Aloja memoria en un Nodo para la Entrada
    struct NodoEntrada* nNodo = calloc(1, sizeof(struct NodoEntrada));
    nNodo -> entrada = pEntrada;

    if(plista -> inicio == NULL){

        plista -> inicio = nNodo;

        return 0;
    }

    else{
        
        // el primero
                    // el de la lista
        if(comparar_strings(plista-> inicio -> entrada ->titulo,  pEntrada->titulo) >= 0){
            // Se tiene que poner la nueva entrada en el inicio
            struct NodoEntrada* inicio_previo = plista->inicio;
            inicio_previo->anterior = nNodo;
            nNodo->siguiente = inicio_previo;
            plista->inicio = nNodo;
            return 0;
        }
        struct NodoEntrada* actual = plista -> inicio;
        //Recorre la lista 
        int insertado = 0;
        while(actual->siguiente != NULL && !insertado){
            
            if(comparar_strings(actual -> entrada -> titulo, pEntrada->titulo ) >= 0){
                printf("Comparacion en while %s y %s\n",actual -> entrada -> titulo,pEntrada->titulo);
                struct NodoEntrada* temporal =  actual -> anterior;

                actual -> anterior = nNodo;
                temporal -> siguiente = nNodo;
                nNodo -> anterior = temporal;
                nNodo -> siguiente = actual;
                insertado=1;
            }
            else{
            //Estando en la posicion actaual pasa a la siguiente posicion
            actual = actual -> siguiente;
            }
        }
        // Caso ultimo elemento
        if(actual->siguiente==NULL){
            if(comparar_strings(actual -> entrada -> titulo, pEntrada->titulo ) >= 0){
                    printf("Entre aqui con %s y %s\n",actual -> entrada -> titulo,pEntrada->titulo);
                    struct NodoEntrada* temporal =  actual -> anterior;
                    actual -> anterior = nNodo;
                    temporal -> siguiente = nNodo;
                    nNodo -> anterior = temporal;
                    nNodo -> siguiente = actual;

            }
            else{
            actual->siguiente = nNodo;
            nNodo->anterior = actual;
            }
        }
        return 0;
    }
}

struct NodoEntrada* eliminar(struct ListaDoble* pLista, char* titulo_entrada){
    if(pLista == NULL){
        return NULL;
    }
    if(pLista -> inicio == NULL){
        return NULL;
    }
    else{
        struct NodoEntrada* eliminado;
        // el primero
        if(comparar_strings(pLista-> inicio -> entrada ->titulo, titulo_entrada) == 0){
            eliminado = pLista-> inicio;
            pLista-> inicio = eliminado->siguiente;
            eliminado->siguiente = NULL;
            return eliminado;
        }
        struct NodoEntrada* actual = pLista-> inicio->siguiente;
        // Despues del primero
        
        while(actual != NULL){
            if(comparar_strings(actual -> entrada ->titulo, titulo_entrada) == 0){
                // Lo encontré
                struct NodoEntrada* anterior = actual -> anterior;
                struct NodoEntrada* siguiente = actual -> siguiente;
                anterior ->siguiente = siguiente;
                // puede que el actual no tenga siguiente
                if(siguiente!=NULL){
                    siguiente ->anterior = anterior;
                }
                eliminado=actual;
                actual->anterior = NULL;
                actual->siguiente = NULL;
                return eliminado;
            }
            else{
            actual = actual ->siguiente;
            }
        }
       // No encontrado 
    }
    return NULL;
}

int imprimir_lista_doble(struct ListaDoble* lista){
    if(lista == NULL){
        printf("La lista esta vacia. \n");
        return -1;

    }
    else{
        struct NodoEntrada* actual; // no hace falta alojar memoria
        actual = lista -> inicio;
        if(actual==NULL){
            printf("La lista esta vacia. \n");
            return 0;
        }
        else{
            while(actual != NULL){
                // salto de linea
                printf("%s\n", actual -> entrada -> titulo);

                actual = actual -> siguiente;
            }
            printf("***\n");

            return 0;
        }
    }
}

