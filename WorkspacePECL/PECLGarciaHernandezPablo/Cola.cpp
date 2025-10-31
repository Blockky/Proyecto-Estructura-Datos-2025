#include "Cola.hpp"

Cola::Cola()
{
	primero = NULL;
	ultimo = NULL;
}
void Cola::insertar(Aficionado* a)
{
	pnodoCola nuevo;
	nuevo = new NodoCola(a);
	if (ultimo)
		ultimo->siguiente = nuevo;
	ultimo = nuevo;
	
	if(!primero)
		primero = nuevo;
    longitud++;
}
void Cola::mostrar()
{
	pnodoCola aux = primero;
	cout <<"\tLos aficionados en la cola son: " << endl;
	while(aux)
    {
		cout <<"-> ";
		aux->aficionado->mostrar();
		aux = aux->siguiente;
	}
	cout<<endl;
}
Aficionado* Cola::extraer()
{
	if(!primero)
		return NULL;
	pnodoCola nodo;
	nodo = primero;
	Aficionado* a = nodo->aficionado;
	primero = nodo->siguiente;
	delete nodo;
	if(!primero)
		ultimo = NULL;
	return a;
    longitud--;
}
bool Cola::idInCola(int i)
{
    int n;
	pnodoCola aux = this->primero;
	while(aux)
	{
		n = aux->aficionado->getID();
		if(n==i) return 1;
		aux=aux->siguiente;
	}
	return 0;
}
Cola::~Cola()
{
	while(primero)
		extraer();
}