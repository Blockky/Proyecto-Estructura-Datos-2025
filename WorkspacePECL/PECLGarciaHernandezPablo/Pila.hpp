#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"
class Pila
{
public:
    Pila();
    ~Pila();
	void insertar(Aficionado a);
	Aficionado extraer();
	Aficionado cima();
	void mostrar();
	
private:
	pnodoPila ultimo;

};

#endif // PILA_HPP
