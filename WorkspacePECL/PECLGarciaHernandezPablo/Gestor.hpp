#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Aficionado.hpp"
#include <algorithm>
using namespace std;

class Gestor
{
private:
	Pila pila_aficionados;
	Cola cola_simpatizantes;
	Cola cola_socios;
	Lista lista_aficionados;
	
	int afiEnPila;
	int socEnCola;
	int simEnCola;
	int afiEnLista;
	
public:
    Gestor();
    void genera10Aficionados(); // A
    void muestraAficionados();	// B
    void borraAficionadosPila();	// C
	void encolarAficionados();	// D
	void muestraSociosCola();	// E
	void muestraSimpatizantesCola(); // F
	void borraAficionadosColas(); // G
	void enlistarAficionados();	// H
	void buscarAficionados();
	int AficionadosEnPila();
	int SociosEnCola();
	int SimpatizantesEnCola();
    ~Gestor();
};

#endif // GESTOR_HPP
