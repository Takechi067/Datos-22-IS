struct Entrada{
	char* categoria;
	char* nombre;
	char* informacion;
};


struct NodoEntrada{
	Entrada* entrada;
	NodoEntrada* siguiente;
	NodoEntrada* anterior;
};
