#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
class Lista
{
public:
    Lista();
    ~Lista();
	void insertar(Aficionado* a);
	Aficionado* buscar();
	
	int aficionados_lista;
	
private:
	pnodoLista ultimo,primero;
};

#endif // LISTA_HPP
