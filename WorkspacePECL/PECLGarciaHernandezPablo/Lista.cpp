#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
}
void Lista::insertar_orden(Aficionado* a)
{
    int llegada = a->getLlegada();
    bool socio = a->esSocio();
    pnodoLista ptr = new NodoLista();
    ptr = new NodoLista(a);
    if(!primero) {
        primero = ptr;
        ultimo = ptr;
    } else if(socio && llegada < primero->aficionado->getLlegada()){
        ptr->siguiente = primero;
        primero = ptr;
    } else if(socio){
        pnodoLista aux = primero;
        while(aux->siguiente && aux->siguiente->aficionado->esSocio() && llegada > aux->siguiente->aficionado->getLlegada()){
            aux = aux->siguiente;
        }
        ptr->siguiente = aux->siguiente;
        aux->siguiente = ptr;
    } else {
        pnodoLista aux = primero;
        while(aux->siguiente && aux->siguiente->aficionado->esSocio()){
            aux = aux->siguiente;
        }
        while(aux->siguiente && llegada > aux->siguiente->aficionado->getLlegada()){
            aux = aux->siguiente;
        }
        ptr->siguiente = aux->siguiente;
        aux->siguiente = ptr;
    }
}
void Lista::mostrar()
{
    pnodoLista aux = primero;
    cout << "\tLos aficionados en la lista son: ";
    while(aux) {
        cout << "->";
        aux->aficionado->mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}
bool Lista::idInLista(int i)
{
    int n;
	pnodoLista aux = this->primero;
	while(aux)
	{
		n = aux->aficionado->getID();
		if(n==i) return 1;
		aux=aux->siguiente;
	}
	return 0;
}
Lista::~Lista() {}
