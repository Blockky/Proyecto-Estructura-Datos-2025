#include "Pila.hpp"

Pila::Pila()
{
	ultimo = NULL;
    longitud = 0;
}
void Pila::insertar(Aficionado* a)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(a,ultimo);
	ultimo = nuevo;
    this->longitud++;
}
Aficionado* Pila::extraer()
{
    if(!ultimo) return NULL;
	pnodoPila nodo;
	nodo = ultimo;
	Aficionado* a = nodo->aficionado;
	ultimo = nodo->siguiente;
	delete nodo;
    this->longitud--;
	return a;
}
void Pila::mostrar()
{
	pnodoPila aux = this->ultimo;
	cout << "\tLa pila de aficionados es:" << endl;
	while(aux)
	{
		cout << "\t->  ";
		aux->aficionado->mostrar();
		aux = aux->siguiente;
	}
	cout<<endl;
}
bool Pila::idInPila(int i)
{
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
int Pila::getLongitud()
{
    return this->longitud;
}
Pila::~Pila()
{
    Aficionado* a;
	while(ultimo)
	{
		a = extraer();
        delete(a);
        this->longitud--;
	}
}
