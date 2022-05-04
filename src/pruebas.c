#include "pruebas.h"

int pruebas_listas(){
    printf("INICIO DEL PROGRAMA\n");
    struct NodoEntrada* mi_nodo_entrada ; //calloc(1, sizeof(struct NodoEntrada));
    // nueva_entrada hace el calloc
    mi_nodo_entrada = nuevo_nodo_entrada();
    mi_nodo_entrada ->entrada = nueva_entrada("ARCANE", "la serie muestra elementos de solarpunk");

    struct NodoEntrada* mi_nodo_entrada2  = nuevo_nodo_entrada();;// = calloc(1, sizeof(struct NodoEntrada));
    mi_nodo_entrada2 ->entrada = nueva_entrada("arquitectura solarpunk", "creacion de edificios de bajo impacto ambiental");
    printf("llego hasta aqui \n");
    struct ListaDoble* lista1;// = calloc(1, sizeof(struct ListaDoble));
    lista1= nueva_lista_doble();
    imprimir_lista_doble(lista1);
    printf("1\n");
    insertar_final(lista1, mi_nodo_entrada ->entrada);
    imprimir_lista_doble(lista1);
    printf("2\n");
    insertar_final(lista1, mi_nodo_entrada2 ->entrada);
    insertar_final(lista1, nueva_entrada("POKEMON", "los juegos de pokemon son solarpunk"));
    imprimir_lista_doble(lista1);
    printf("ANTES DE ELIMINAR\n");

    eliminar(lista1, "POKEMON");
    imprimir_lista_doble(lista1);
    eliminar(lista1, "ARCANE");
    //eliminar(lista1, "arquitectura solarpunk");

    imprimir_lista_doble(lista1);
    eliminar(lista1, "arquitectura solarpunk");
    imprimir_lista_doble(lista1);

    insertar_ordenado(lista1, nueva_entrada("Arboles", "los juegos de Arboles son Arboles"));
    imprimir_lista_doble(lista1);
    insertar_ordenado(lista1, nueva_entrada("Aazucaaa", "las peliculas de Aazucaaa son Aazucaaa"));
    imprimir_lista_doble(lista1);
    insertar_ordenado(lista1, nueva_entrada("ZEBRAS", "los ZEBRAS de ZEBRAS son ZEBRAS"));
    imprimir_lista_doble(lista1);
    insertar_ordenado(lista1, nueva_entrada("Zamba", "los Zamba de Zamba son Zamba"));
    imprimir_lista_doble(lista1);
    insertar_ordenado(lista1, nueva_entrada("Zaaa", "los Zaaa de Zaaa son Zaaa"));
    imprimir_lista_doble(lista1);

    
    eliminar(lista1, "Arboles");
    imprimir_lista_doble(lista1);
    eliminar(lista1, "Aazucaaa");
    imprimir_lista_doble(lista1);
    eliminar(lista1, "ZEBRAS");
    
    imprimir_lista_doble(lista1);
    eliminar(lista1, "EL PROYECTO");
    
    imprimir_lista_doble(lista1);
}

int pruebas_hash(){
    struct HashMap* mi_hash =  nuevo_hashmap(13);
    struct Categoria* mi_cat1 = nueva_categoria("Entrenimiento");
    insertar_categoria_hash(mi_hash, mi_cat1);

    struct Categoria* mi_cat2 = nueva_categoria("Estado");
    insertar_categoria_hash(mi_hash, mi_cat2);
    imprimir_hash(mi_hash);

    struct Categoria* mi_cat3 = nueva_categoria("Linux es mejor para esto");
    insertar_categoria_hash(mi_hash, mi_cat3);
    imprimir_hash(mi_hash);
    
}