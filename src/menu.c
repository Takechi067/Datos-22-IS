#include "menu.h"
int main_menu(){
    struct HashMap* hash_main = nuevo_hashmap(31);
    
    // Cuando se inserta devuelve 0.
    insertar_categoria_hash(hash_main, nueva_categoria("Estado de la emergencia climatica"));
    insertar_categoria_hash(hash_main, nueva_categoria("Soluciones desde el Anarquismo solarpunk"));
    insertar_categoria_hash(hash_main, nueva_categoria("Entretenimiento solarpunk"));

    int continuar = 1;

    while(continuar){
            mostrar_opciones();
            printf("Elija una opcion (1-6): \n");
            char mi_entrada[2];
            
            fgets(mi_entrada,2,stdin);
            //printf("Mi entrada es: %s", mi_entrada);
            flush_buffer();           
            //getchar(); // Limpia la entrada estandar para evitar problemas
            int indice_opcion = atoi(mi_entrada);
            //printf("Mi entrada es: %d", indice_opcion);
            // Valida la opcion
            if(indice_opcion>0 && indice_opcion<7){
                if(indice_opcion==1){
                    opcion_mostrar_categorias(hash_main);
                }
                else if(indice_opcion==2){
                    buscar_entrada_categoria_nombre(hash_main);
                }
                else if(indice_opcion==3){
                    buscar_entrada_nombre(hash_main);
                }
                else if(indice_opcion==4){
                    opcion_agregar_categoria(hash_main);
                }
                else if(indice_opcion==5){
                    opcion_agregar_entrada(hash_main);
                }
                else if(indice_opcion==6){
                    continuar=0;
                } 
            }
            else{
                printf("Ingrese una opcion valida: \n");
            }
            

    }
}
int mostrar_opciones(){
    printf("\n\t%s\n\n","Buscador Solarpunk");
    printf("\t\t%s\n\n","Menu:");
    printf("\n%s\n","**********************************");
    printf("%s\n","1. Mostrar categorias existentes");
    printf("%s\n","2. Buscar entrada por categoria y nombre");
    printf("%s\n","3. Buscar entrada por nombre");
    printf("%s\n","4. Agregar categoria");
    printf("%s\n","5. Agregar entrada");
    printf("%s\n","6. Salir");
    printf("%s\n","**********************************");
    return 0;
}

int opcion_mostrar_categorias(struct HashMap* hash_main){
    // Muestra las categorias con indice del hash
    if(imprimir_categorias_hash(hash_main)){

        // Espera la entrada del usuario
        printf("Ingrese el numero de la categoria: \n");
        int indice_hash = atoi(leer_consola(5));
        //printf("Asi se convirtio el indice: %d \n", indice_hash );
        // Hay que validar que sea un numero 

        struct Categoria* buscado = buscar_hash_indice(hash_main, indice_hash);
        printf("\n");
        if(buscado){
            imprimir_categoria(buscado);
        }
        else{
            printf("Ingrese un numero valido. \n");
        }
    }
    return 0;
}
int buscar_entrada_categoria_nombre(struct HashMap* hash_main){
    printf("Ingrese el nombre de la categoria a buscar: \n");
    char* nombre_categoria = leer_consola(100);
    printf("\n");
    struct Categoria* categoria_buscada = buscar_categoria_nombre(hash_main,nombre_categoria);
    if(categoria_buscada){
        printf("Ingrese el titulo de la entrada a buscar: \n");
        char* nombre_entrada = leer_consola(100);
        printf("\n");
        struct NodoEntrada* entrada_buscada = buscar_entrada(categoria_buscada->lista_entradas,nombre_entrada);
        if(entrada_buscada){
            imprimir_entrada( entrada_buscada->entrada);
        }
        else{
            printf("No se encontro la entrada. \n");
        }
    }
    else{
        printf("Ingrese una categoria valida. \n");
    }
    return 0;
}
int buscar_entrada_nombre(struct HashMap* hash_main){
    printf("Ingrese el titulo de la entrada a buscar entre todas las categorias: \n");
    char* nombre_entrada = leer_consola(100);
    printf("\n");
    int encontrado = 0;
    int indice = 0;
    struct NodoEntrada* entrada_buscada;
    while(indice<hash_main->maximo&&!encontrado){
        // si no es nulo, lo reviso
        if(hash_main->arreglo_categorias[indice]){
            entrada_buscada = buscar_entrada(hash_main->arreglo_categorias[indice]->lista_entradas, nombre_entrada);
            if(entrada_buscada){
                encontrado = 1;
            }
        }
        else{
        indice++;
        }
    }
    if(encontrado){
        imprimir_entrada( entrada_buscada->entrada);
    }
    else{
        printf("No se encontro la entrada.");
        printf("\n");
    }
    return 0;
}

int opcion_agregar_categoria(struct HashMap* hash_main){
    printf("Ingrese el nombre de la categoria a agregar: \n");
    printf("Debe contener entre 5 y 99 caracteres. \n");

    char* nombre_categoria = leer_consola(100);
    printf("\n");
    
    int largo_valido = validar_largo_texto(nombre_categoria, 6,127);
    if(largo_valido){
        eliminar_nueva_linea(nombre_categoria);
        struct Categoria* categoria_agregar = nueva_categoria(nombre_categoria);
        // Cuando se inserta devuelve 0.
        if(!insertar_categoria_hash(hash_main, categoria_agregar)){
            printf("Categoria agregada. \n");
        }
        else{
            printf("Se produjo un error al agregar. \n");
        }
        return -1;
    }
    else{
        printf("Ingrese una entrada entre 5 y 100 caracteres \n");
        return -1;
    }
}

int opcion_agregar_entrada(struct HashMap* hash_main){
    printf("Ingrese el nombre de la categoria en la que desea agregar su entrada: \n");
    char* nombre_categoria = leer_consola(100);
    printf("\n");
    struct Categoria* categoria_buscada = buscar_categoria_nombre(hash_main,nombre_categoria);
    // Si no es nulo entra al if.
    if(categoria_buscada){
        printf("\nIngrese los datos de la entrada: \n");
        printf("Titulo: \n");
        char* titulo_entrada = leer_consola(100);
        printf("Referencia: \n");
        char* referencia_entrada = leer_consola(220);
        printf("Descripcion: \n");
        char* descripcion_entrada = leer_consola(1200);
        struct Entrada* entrada_agregar = nueva_entrada(titulo_entrada,
        referencia_entrada, descripcion_entrada);
        insertar_ordenado(categoria_buscada->lista_entradas, entrada_agregar);
        printf("Se agrego la entrada a la categoria. \n");
    }
    else{
        printf("Ingrese una categoria valida. \n");
    }

    return 0;
}