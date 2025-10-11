#include "Cola.hpp"

Cola::Cola()
{
	primero = NULL;
	ultimo = NULL;
	
}

void Cola::insertar(Aficionado a)
{
	pnodoCola nuevo;
	nuevo = new NodoCola(a);
	if (ultimo)
		ultimo->siguiente = nuevo;
	ultimo = nuevo;
	
	if(!primero)
		primero = nuevo;
}

void Cola::mostrar()
{
	pnodoCola aux = primero;
	cout <<"\tLos aficionados en la cola son: ";
	while(aux){
		cout <<"->";
		aux->aficionado.mostrar();
		aux = aux->siguiente;
	}
	
	cout<<endl;
		
}

Aficionado Cola::eliminar()
{
	pnodoCola nodo;
	nodo = primero;
	Aficionado a = nodo->aficionado;
	if(!nodo)
		throw runtime_error("Cola vacia");
	primero = nodo->siguiente;
	delete nodo;
	if(!primero)
		ultimo  =NULL;
	return a;
}
Aficionado Cola::verPrimero()
{
	return primero->aficionado;
}
Cola::~Cola()
{
	while(primero)
		eliminar();
}

