#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"

class Pila
{
public:
    Pila();
	void insertar(Aficionado* a);
	Aficionado* extraer();
	void mostrar();
	bool idInPila(int i);
    int getLongitud();
    ~Pila();

private:
	pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP
