#include "Aficionado.hpp"

#include <iostream>

class NodoPila
{
public:
    NodoPila(const Aficionado& a, NodoPila* sig = NULL);
    ~NodoPila();

private:
	Aficionado aficionado;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;
