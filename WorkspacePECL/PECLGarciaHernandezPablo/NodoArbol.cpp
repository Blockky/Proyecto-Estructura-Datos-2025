#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado* a)
{
    this->aficionado = a;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}

