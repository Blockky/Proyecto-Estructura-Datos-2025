#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Aficionado.hpp"
#include <algorithm>
using namespace std;

class Gestor
{
private:
	Pila pila_aficionados;
	Cola cola_simpatizantes;
	Cola cola_socios;
	int afiEnPila;
	int socEnCola;
	int simEnCola;
	
public:
    Gestor();
    void genera10Aficionados(); // A
    void muestraAficionados();	// B
    void borraAficionadosPila();	// C
	void encolarAficionados();	// D
	void muestraSociosCola();	// E
	void muestraSimpatizantesCola(); // F
	void borraAficionadosColas(); // G
	int AficionadosEnPila();
	int SociosEnCola();
	int SimpatizantesEnCola();
    ~Gestor();
};

#endif // GESTOR_HPP
