#include "Lista.hpp"

Lista::Lista()
{
	primero = NULL;
	ultimo = NULL;
}
void Lista::insertar_orden(Aficionado* a){
	int llegada = a->getLlegada();
	pnodoLista ptr, aux;
	aux = new NodoLista(NULL);
	ptr = new NodoLista(a);
	if(!primero){
		primero = ptr;
		ultimo = ptr;
	} else {
		if (llegada < primero->aficionado->getLlegada()){
			ptr->siguiente = primero;
			primero = ptr;
		} else {
			primero = aux;
			while (aux->siguiente && 
				   aux->siguiente->aficionado->getLlegada() < llegada){
				aux->siguiente = aux;
		}
		aux->siguiente = ptr->siguiente;
		ptr = aux->siguiente;
		}
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

