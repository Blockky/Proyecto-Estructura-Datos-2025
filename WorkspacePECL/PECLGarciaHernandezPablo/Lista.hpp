#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
#include <iostream>

class Lista
{
public:
    Lista();
    void insertar_orden(Aficionado* a);
    void mostrar();
    void buscar();
    bool idInLista(int i);
    int getLongitud();
    Aficionado* extraerIzq();
    ~Lista();

private:
    pnodoLista ultimo, primero;
    int longitud;
};

#endif // LISTA_HPP
