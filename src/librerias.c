#include "librerias.h"
int a_minuscula(char* str){
    // Modifica un str para que este todo en mayuscula
    // Basado en: https://stackoverflow.com/a/2661788
    if(strlen(str)){
        for(int i = 0; i<strlen(str); i++){
            str[i] = tolower(str[i]);
        }
        return 0;
    }
    return 1;
}

int comparar_strings(char* c1, char* c2){
    // Compara dos caracteres sin importar las mayusculas y minusculas
    // Devuelve 0 si son iguales
    // >0 si c1>c2
    // <0 si c1<c2
                    // el +1 es para el 0
    char* minus_c1 = calloc(strlen(c1)+1, sizeof(char));
    strcpy(minus_c1, c1);

    a_minuscula(minus_c1);
    char* minus_c2 = calloc(strlen(c2)+1, sizeof(char));
    strcpy(minus_c2, c2);
    a_minuscula(minus_c2);

    //printf("Comparando: %s con \n%s\n", minus_c1, minus_c2);
    //printf("Comparando: %d con \n%d\n", strlen(minus_c1), strlen(minus_c2));
    int resultado_cmp = strcmp(minus_c1, minus_c2);
    //printf("El resultado es: %d\n", resultado_cmp);
    free(minus_c1);
    free(minus_c2);
    return resultado_cmp;
}
int eliminar_nueva_linea(char * string){
    // Tomado de: https://stackoverflow.com/a/17386177
    
    int nueva_linea = strlen(string)-1;
    if(nueva_linea>0){                       
        if (string[nueva_linea] == '\n')
            string[nueva_linea] = '\0';
    }
}

int validar_largo_texto(char* string, int minimo, int maximo){
    // Valida si el largo de un texto esta entre el minimo y el
    // maximo, ambos inclusivos.

    // Devuelve 1 si es valido, 0 sino.
    int largo = strlen(string);
    if(largo<minimo || largo>maximo){
        return 0;
    }
    else{
        return 1;
    }

}
/*
char* leer_consola(int cantidad_caracteres){
    char mi_entrada[2048];
    // Recibe la entrada desde la consola
    fgets(mi_entrada,cantidad_caracteres,stdin);
    flush_buffer();  

    //getchar();// Limpia la entrada estandar para evitar problemas
    // se necesita asignar memoria porque mi_entrada es un buffer
    char* entrada_string = calloc(strlen(mi_entrada)+1, sizeof(char)); 
    strcpy(entrada_string, mi_entrada);
    //printf("La entrada es: %s \n", entrada_string);
    eliminar_nueva_linea( entrada_string);
    //printf("La entrada es: %s \n", entrada_string);
    return entrada_string;
}
*/
char* leer_consola(int cantidad_caracteres){
    int ch;
    char str[200];
    scanf("%[^\n]",str);

    //printf("%s\n", str);
    char* entrada_string = calloc(strlen(str)+1, sizeof(char)); 
    strcpy(entrada_string, str);
    eliminar_nueva_linea( entrada_string);
    //printf("%s\n", entrada_string);
    flush_buffer();
    return entrada_string;
}
int flush_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    return 0;
}