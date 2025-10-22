#include "Lista.hpp"

Lista::Lista()
{
	primero = NULL;
	ultimo = NULL;
}
void Lista::insertar(Aficionado* a){
	pnodoLista nuevo;
	nuevo = new NodoLista(a);
	if (ultimo)
		ultimo->siguiente = nuevo;
	ultimo = nuevo;
	
	if(!primero)
		primero = nuevo;
}
/* Aficionado Lista::buscar(){
	
} */
Lista::~Lista()
{
}

