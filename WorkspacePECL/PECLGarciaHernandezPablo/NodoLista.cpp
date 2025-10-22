#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado* a, NodoLista* sig)
{
	aficionado = a;
	siguiente = sig;
}
NodoLista::~NodoLista()
{
}