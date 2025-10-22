#include "Pila.hpp"

Pila::Pila()
{
	ultimo = NULL;
}
void Pila::insertar(Aficionado* a)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(a,ultimo);
	ultimo = nuevo;
}
Aficionado* Pila::extraer()
{
	pnodoPila nodo;
	nodo = ultimo;
	Aficionado* a = nodo-> aficionado;
	ultimo = nodo->siguiente;
	delete nodo;
	return a;
}
Aficionado* Pila::cima()
{
	if(!ultimo)
		return 0;
	return ultimo->aficionado;
}
void Pila::mostrar()
{
	pnodoPila aux = this->ultimo;
	cout <<"\tLa pila de aficionados es: " << endl;
	while(aux)
	{
		cout << "-> ";
		aux->aficionado->mostrar();
		aux=aux->siguiente;
	}
	cout<<endl;
}
bool Pila::idInPila(int i){
	int n;
	pnodoPila aux = this->ultimo;
	while(aux)
	{
		n = aux->aficionado->getID();
		if(n==i) return 1;
		aux=aux->siguiente;
	}
	return 0;
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

