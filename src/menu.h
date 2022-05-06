#ifndef menu_h
#define menu_h
#include "librerias.h"
#include "hash.h"
int main_menu();
int mostrar_opciones();
int opcion_mostrar_categorias(struct HashMap*);
int buscar_entrada_categoria_nombre(struct HashMap*);
int buscar_entrada_nombre(struct HashMap*);
int opcion_agregar_categoria(struct HashMap*);
int opcion_agregar_entrada(struct HashMap*);
#endif 