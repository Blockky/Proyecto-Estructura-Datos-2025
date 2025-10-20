#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
class Cola
{
	
public:
    Cola();
    ~Cola();
	
	void insertar(Aficionado* a);
	Aficionado* eliminar();
	void mostrar();
	Aficionado* verPrimero();
	
private:
	pnodoCola primero,ultimo;

};

#endif // COLA_HPP
