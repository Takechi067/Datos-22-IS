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