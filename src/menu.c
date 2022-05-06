#include "menu.h"

int mostrar_opciones(){
    printf("\n\t%s\n\n","Buscador Solarpunk");
    printf("\t\t%s\n\n","Menu:");
    printf("\n%s\n","**********************************");
    printf("%s\n","1. Mostrar categorias existentes");
    printf("%s\n","2. Buscar por categoria y nombre");
    printf("%s\n","3. Busqueda por nombre");
    printf("%s\n","4. Agregar categoria");
    printf("%s\n","5. Agregar entrada");
    printf("%s\n","6. Salir");
    printf("%s\n","**********************************");
    return 0;
}

int opcion_mostrar_categorias(struct HashMap* hash_main){
    // Muestra las categorias con indice del hash
    imprimir_categorias_hash(hash_main);

    // Espera la entrada del usuario
    printf("Ingrese el numero de la categoria: \n");
    char mi_entrada[1024];
    fgets(mi_entrada,1024,stdin);
    int indice_hash = atoi(mi_entrada);
    printf("Asi se convirtio el indice: %d \n", indice_hash );
    // Hay que validar que sea un numero 
    //int largoT = strlen(miTexto);
    //int resultado = obtener_hash_ajustado(hash_main, miTexto, largoT);
    struct Categoria* buscado = buscar_hash_indice(hash_main, indice_hash);
    printf("\n");
    if(buscado){
        imprimir_categoria(buscado);
    }
    else{
        printf("Ingrese un numero valido. \n");
    }
    return 0;
}

