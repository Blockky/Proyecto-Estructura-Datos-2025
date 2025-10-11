#include "Pila.hpp"

Pila::Pila()
{
	ultimo = NULL;
	
}

void Pila::insertar(Aficionado a)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(a,ultimo);
	ultimo = nuevo;
}
Aficionado Pila::extraer()
{
	pnodoPila nodo;
	nodo = ultimo;
	Aficionado a = nodo-> aficionado;
	if(ultimo)
		throw runtime_error("Pila vacia");
	ultimo = nodo->siguiente;
	delete nodo;
	return a;
}
Aficionado Pila::cima()
{
	if(!ultimo)
		return 0;
	return ultimo->aficionado;
}

void Pila::mostrar()
{
	pnodoPila aux = ultimo;
	cout <<"\tLa pila de aficionados es: ";
	while(aux)
	{
		cout << "-> ";
		aux->aficionado.mostrar();
		aux=aux->siguiente;
	}
	
	cout<<endl;
}
Pila::~Pila()
{
	pnodoPila aux;
	while(!ultimo)
	{
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
	}
}

