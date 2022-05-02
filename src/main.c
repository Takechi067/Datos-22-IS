#include "hash.h"

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