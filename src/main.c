#include "hash.h"
#include "lista_doble.h"

/*
int main(){
    int bandera = 1;
    while(bandera){
    char miTexto[512];
    printf("Ingrese el texto a evaluar: \n");
    fgets(miTexto,512,stdin);
    int largoT = strlen(miTexto);
    int resultado = obtener_hash(miTexto, largoT)%13;
    printf("El hash del texto es: %d\n",resultado);
    if(miTexto[0]=='Z'){
        bandera = 0;
    }
    }
    return 0;
}
*/
int main(){
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


    eliminar(lista1, "Arboles");
    imprimir_lista_doble(lista1);
    eliminar(lista1, "Aazucaaa");
    imprimir_lista_doble(lista1);
    eliminar(lista1, "ZEBRAS");

    imprimir_lista_doble(lista1);

    return 0;
}