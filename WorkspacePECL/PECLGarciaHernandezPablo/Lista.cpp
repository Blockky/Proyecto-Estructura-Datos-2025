#include "Lista.hpp"

Lista::Lista()
{
	primero = NULL;
	ultimo = NULL;
}
void Lista::insertar_orden(Aficionado* a){
	int llegada = a->getLlegada();
	pnodoLista ptr;
	
	ptr = new NodoLista(a);
	if(!primero){
		primero = ptr;
		ultimo = ptr;
		return;
	} else {
		if (llegada < primero->aficionado->getLlegada()){
			ptr->siguiente = primero;
			primero = ptr;
			return;
		} else {
			pnodoLista aux = primero;
			while (aux->siguiente && 
				   aux->siguiente->aficionado->getLlegada() < llegada){
				 aux = aux->siguiente;
		}
		 ptr->siguiente = aux->siguiente;
		aux->siguiente = ptr;
		}
		
		if (ptr->siguiente == NULL) ultimo = ptr;
		
	}
}
void Lista::mostrar()
{
	pnodoLista aux = primero;
	cout <<"\tLos aficionados en la lista son: ";
	while(aux){
		cout <<"->";
		aux->aficionado->mostrar();
		aux = aux->siguiente;
	}
	cout<<endl;
}
Lista::~Lista()
{
}

