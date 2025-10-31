#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
	void insertar(Aficionado* a);
	Aficionado* extraer();
	void mostrar();
	bool idInCola(int i);
	
private:
	pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP
