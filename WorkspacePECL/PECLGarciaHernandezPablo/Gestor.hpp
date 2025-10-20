#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Aficionado.hpp"
#include <algorithm>
using namespace std;

class Gestor
{
public:
    Gestor();
    
    void genera10Aficionados(); // A
    void muestraAficionados();	// B
    void borraAficionadosPila();	// C
	void encolarAficionados();	// D
	void muestraSociosCola();	// E
	int AficionadosEnPila();
	
    ~Gestor();

    Pila pila_aficionados = Pila();
	Cola cola_simpatizantes = Cola();
	Cola cola_socios = Cola();
    
};

#endif // GESTOR_HPP
