#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include "Aficionado.hpp"

class NodoArbol
{
public:
    NodoArbol(Aficionado* aficionado);
    ~NodoArbol();

private:
    Aficionado* aficionado;
    NodoArbol* der;
    NodoArbol* izq;
    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
