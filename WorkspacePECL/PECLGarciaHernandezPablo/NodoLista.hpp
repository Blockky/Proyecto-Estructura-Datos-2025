#include "Aficionado.hpp"

class NodoLista
{
public:
	NodoLista(Aficionado* a = NULL, NodoLista* sig = NULL);
	~NodoLista();
	
private:
	Aficionado* aficionado;
	NodoLista* siguiente;
	friend class Lista;
};

typedef NodoLista* pnodoLista;
