#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Aficionado.hpp"
#include <algorithm>
using namespace std;

class Gestor
{
public:
    Gestor();
    
    void genera10Aficionados();
    void muestraAficionados();
    
    ~Gestor();

    Pila pila_aficionados = Pila();
    
};

#endif // GESTOR_HPP
