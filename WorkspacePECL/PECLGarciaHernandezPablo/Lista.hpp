#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
class Lista
{
public:
    Lista();
    ~Lista();
	void insertar_orden(Aficionado* a);
	Aficionado* buscar();
	void mostrar();
	
private:
	pnodoLista ultimo,primero;
};

#endif // LISTA_HPP
