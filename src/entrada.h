struct Entrada{
	char* categoria;
	char* nombre;
	char* informacion;
};

struct NodoEntrada;
struct NodoEntrada{
	struct Entrada* entrada;
	struct NodoEntrada* siguiente;
	struct NodoEntrada* anterior;
};
