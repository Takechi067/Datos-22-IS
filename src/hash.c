#include "hash.h"
struct HashMap*nuevo_hashmap(int maximo_elementos){
    struct HashMap* n_hash = calloc(1, sizeof(struct HashMap));
    n_hash->cantidad_elementos = 0;
    n_hash->maximo = maximo_elementos;
    // Aloja la memoria para los punteros de Categoria en cada posicion del arreglo
    n_hash->arreglo_categorias = calloc(maximo_elementos, sizeof(struct Categoria*));


    // No inicializa los elementos. Los deja en NULL.

    // Aloja la memoria para las Categoria en cada indice.
    /*
    for(int i =0; i <maximo_elementos; i++){
        n_hash->arreglo_categorias[i]=calloc(1,sizeof(struct Categoria));
    }
    */
    return n_hash;
}
int obtener_hash (char* string, int largo){
    // Devuelve un entero entre 0 y M - 1  
    // El algoritmo usado es el Polynomial Rolling Hash
    int hash = 0;
    int p = 31; // Puede ser cualquier valor, 31 es recomendado
    long multiplicador = 1; // Si uso int podria hacer overflow
    int M = 10000009; // 10^7 + 9

    // Caracter por caracter hasta el final
    for(int i=0; i<largo; i++){
        hash= hash+(string[i]*multiplicador); // Suma el acumulado con el char actual*multiplicador
        hash=hash%M; // Aplica la operacion de modulo con el M
        multiplicador=multiplicador * p; // Sube el grado del multiplicador
        multiplicador= multiplicador%M;    
    }
    return hash;
}
int obtener_hash_categoria(struct Categoria* categoria){
    // Devuelve el valor de hash de la categoria.
    if(categoria==NULL){
        return -1;
    }
    char* nombre = categoria->nombre;
    int indice = obtener_hash (nombre, strlen( nombre));

    return indice;
}
int insertar_categoria_hash(struct HashMap* hash, struct Categoria* nueva_categoria){
    // Agrega la categoria la posicion que le corresponda segun la funcion
    // de hash.

    // valida que no sean nulos
    int insertado = 0;
    if(hash!=NULL & nueva_categoria!=NULL){
        
        int indice = obtener_hash_categoria(nueva_categoria)%hash->maximo;
        // Si el indice ya contiene un elemento, insertelo en el siguiente que esté vacío
        if(hash->arreglo_categorias[indice] == NULL){
            hash->arreglo_categorias[indice]=nueva_categoria;
            hash->cantidad_elementos++;
            insertado = 1;
        }
        // Ya existe un elemento. Colisión.
        else{
            
            while(indice < hash->maximo && !insertado){
                if(hash->arreglo_categorias[indice] == NULL){
                    hash->arreglo_categorias[indice]=nueva_categoria;
                    insertado = 1;
                    hash->cantidad_elementos++;
                }
                indice++;
            }
            if(!insertado){
            // redimensionar(struct HashMap* hash);
            // insertar_categoria_hash(struct HashMap* hash, struct Categoria* nueva_categoria);
            }
        }
        return 0;
    }
    // cuando insertado sea 0, la condicion es verdadera
    // no fue insertado por un error
    if(!insertado){
        return -1;
    }

}

struct Categoria* buscar_categoria_nombre(struct HashMap* hash, char* nombre_categoria){
    int largo = strlen(nombre_categoria);
    int indice = obtener_hash(nombre_categoria, largo);
    int encontrado = 0;
    struct Categoria* categoria_buscada = NULL;

    // Se sabe que hay algo pero no qué
    if(hash->arreglo_categorias[indice]!=NULL){
        // comparar strings
        if(strcmp(hash->arreglo_categorias[indice]->nombre, nombre_categoria)){
            categoria_buscada = hash->arreglo_categorias[indice];
        }

        else{
            indice++; // Paso a comparar el que sigue
            while(indice < hash->maximo && hash->arreglo_categorias[indice]!=NULL &&!encontrado ){
                if(strcmp(hash->arreglo_categorias[indice]->nombre, nombre_categoria)){
                    encontrado = 1;
                    categoria_buscada = hash->arreglo_categorias[indice];
                }
                indice++;
            }
        }
    }
    return categoria_buscada;
}