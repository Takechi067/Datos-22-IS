#include "hash.h"
struct HashMap*nuevo_hashmap(int maximo_elementos){
    struct HashMap* n_hash = calloc(1, sizeof(struct HashMap));
    n_hash->cantidad_elementos = 0;
    n_hash->maximo = maximo_elementos;
    // Aloja la memoria para los punteros de Categoria en cada posicion del arreglo
    n_hash->arreglo_categorias = calloc(maximo_elementos, sizeof(struct Categoria*));


    // No inicializa los elementos. Los deja en NULL.


    return n_hash;
}
int obtener_hash (char* string, int largo){
    // Devuelve un entero entre 0 y M - 1  
    // El algoritmo usado es el Polynomial Rolling Hash

    // El hash para las mayusculas y minusculas es el mismo
    char* minus_string = calloc(strlen(string)+1, sizeof(char));
    strcpy(minus_string, string);
    a_minuscula(minus_string);
    //printf("Este el el texto a evaluar: %s\n", minus_string);
    int hash = 0;
    int p = 31; // Puede ser cualquier valor, 31 es recomendado
    long multiplicador = 1; // Si uso int podria hacer overflow
    int M = 10000009; // 10^7 + 9

    // Caracter por caracter hasta el final
    for(int i=0; i<largo; i++){
        hash= hash+(minus_string[i]*multiplicador); // Suma el acumulado con el char actual*multiplicador
        hash=hash%M; // Aplica la operacion de modulo con el M
        multiplicador=multiplicador * p; // Sube el grado del multiplicador
        multiplicador= multiplicador%M;    
    }
    free(minus_string);
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

int obtener_hash_ajustado(struct HashMap* hash, char* string){
    return obtener_hash(string, strlen(string))%hash->maximo;
}

int insertar_categoria_hash(struct HashMap* hash, struct Categoria* nueva_categoria){
    // Agrega la categoria la posicion que le corresponda segun la funcion
    // de hash.

    // valida que no sean nulos
    int insertado = 0;
    if(hash!=NULL & nueva_categoria!=NULL){
        
        int indice = obtener_hash_categoria(nueva_categoria)%hash->maximo;
        // Si el indice ya contiene un elemento, insertelo en el siguiente que est?? vac??o
        if(hash->arreglo_categorias[indice] == NULL){
            hash->arreglo_categorias[indice]=nueva_categoria;
            hash->cantidad_elementos++;
            insertado = 1;
        }
        // Ya existe un elemento. Colisi??n.
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
             redimensionar_hash(hash, hash->maximo*2);
             return insertar_categoria_hash(hash, nueva_categoria);
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
    int indice_buscado = buscar_indice_nombre(hash, nombre_categoria);
    // si lo encontr??, devuelva el elemento en esa posicion
    if(indice_buscado!=-1){
         return hash->arreglo_categorias[indice_buscado];
    }
    else{
        return NULL;
    }
}
struct Categoria* buscar_hash_indice(struct HashMap* hash, int indice){
    
    if(indice>=0  &&  indice < hash->maximo){
        return hash->arreglo_categorias[indice];
    }
    else{
        return NULL;
    }
}
int buscar_indice_nombre(struct HashMap* hash, char* nombre_categoria){
    // Devuelve el indice con la ubicacion en el arreglo del hash de la categoria ingresada
    // si no la encuentra devuelve -1
    int largo = strlen(nombre_categoria);
                 // obtener hash me devuelve un numero muy grande, tengo que recortarlo

    // El hash lo hay que buscar en minuscula siempre

    int indice = obtener_hash(nombre_categoria, largo) % hash->maximo;
    int encontrado = 0;
    
    // Se sabe que hay algo pero no qu??
    if(hash->arreglo_categorias[indice]!=NULL){
        // comparar strings
        // Si es 0 son iguales, asi que se niega para que entre en el if
        if(!comparar_strings(hash->arreglo_categorias[indice]->nombre, nombre_categoria)){
            return indice;
        }
        // Algoritmo de colisiones, si ya esta encuentra el siguiente espacio vacio
        else{
            indice++; // Paso a comparar el que sigue
            while(indice < hash->maximo && hash->arreglo_categorias[indice]!=NULL &&!encontrado ){
                if(!comparar_strings(hash->arreglo_categorias[indice]->nombre, nombre_categoria)){
                    encontrado = 1;

                    return indice;
                }
                indice++;
            }
        }
    }
    return -1;
}
struct Categoria* eliminar_categoria_hash(struct HashMap* hash, char* nombre){
        int indice_eliminado = buscar_indice_nombre(hash, nombre);
        //printf("El indice es: %d\n",indice_eliminado );
        struct Categoria* eliminado = NULL;
        if(indice_eliminado!=-1){
            struct Categoria* eliminado = hash->arreglo_categorias[indice_eliminado];
            hash->arreglo_categorias[indice_eliminado]=NULL;
        }
        return eliminado;
}

int redimensionar_hash(struct HashMap* hash_parametro, int nuevo_largo){
    struct Categoria** nuevo_arreglo =  calloc(nuevo_largo, sizeof(struct Categoria*));
    struct HashMap* hash_tmp = nuevo_hashmap(nuevo_largo);
    free(hash_tmp->arreglo_categorias);
    hash_tmp->arreglo_categorias = nuevo_arreglo;
    for(int i = 0; i < hash_parametro->maximo; i++){
        if(hash_parametro->arreglo_categorias[i]!=NULL){
            insertar_categoria_hash(hash_tmp, hash_parametro->arreglo_categorias[i]);
        }
    }
    hash_parametro = hash_tmp;
    return 0;
}

int imprimir_categorias_hash(struct HashMap* hash){
    // Imprime los titulos de las categorias no nulas
    // del hash. 
    // Devuelve 0 si no tiene elementos, 1 si tiene, -1 si es nulo
    if(hash!=NULL){
        if(hash->cantidad_elementos<1){
            printf("\n No se han agredado categorias. \n");
            return 0;
        }
        else{
        printf("\n Categorias: \n");
        for(int i = 0; i < hash->maximo; i++){
            if(hash->arreglo_categorias[i]!=NULL){
                printf("%d: %s \n",i,hash->arreglo_categorias[i]->nombre);
            }
        }
        return 1;
        }
    }
    else{
    return -1;
    }
}