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
	int socios_cola;
	int simpatizantes_cola;
	
private:
	pnodoCola primero,ultimo;

};

#endif // COLA_HPP
