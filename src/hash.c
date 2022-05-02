#include "hash.h"
struct HashMap*nuevo_hashmap(int maximo_elementos){
    struct HashMap* n_hash = calloc(1, sizeof(struct HashMap));
    n_hash->cantidad_elementos = 0;
    n_hash->maximo = maximo_elementos;
    // Aloja la memoria para los punteros de Categoria en cada posicion del arreglo
    n_hash->arreglo_categorias = calloc(maximo_elementos, sizeof(struct Categoria*));

    // Aloja la memoria para las Categoria en cada indice.
    for(int i =0; i <maximo_elementos; i++){
        n_hash->arreglo_categorias[i]=calloc(1,sizeof(struct Categoria));
    }
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
int agregar_categoria(struct HashMap* hash, struct Categoria* nueva_categoria){
    // Agrega la categoria la posicion que le corresponda segun la funcion
    // de hash.

    // valida que no sean nulos
    if(hash!=NULL & nueva_categoria!=NULL){

    int indice = obtener_hash_categoria(nueva_categoria)%hash->maximo;
    hash->arreglo_categorias[indice] = nueva_categoria;
    hash->cantidad_elementos++;

    return 0;
    }
    else{
        // error
        return -1;
    }
}