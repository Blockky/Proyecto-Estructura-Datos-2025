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
	void buscarAficionados();   // I
    void reiniciar();           // J
	int AficionadosEnPila();
	int SociosEnCola();
	int SimpatizantesEnCola();
    int AficionadosEnLista();
    ~Gestor();
    
private:
	Pila pila_aficionados;
	Cola cola_simpatizantes;
	Cola cola_socios;
	Lista lista_aficionados;
};

#endif // GESTOR_HPP
