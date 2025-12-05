#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Aficionado.hpp"
#include "Arbol.hpp"
#include <algorithm>
#include <time.h>
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
	void crearArbol();			// K
	void mostrarSociosOrdenados(); //L
	void mostrarSimpatizantesOrdenados(); //M
	void mostrarInorden(); //N
	//void mostrarAficionadosArbol(); //O
	//int aficionadoIDPar(); //P
	void mostrarAficionadosNodoHoja(); //Q
	void borrarAficionadoPorId(); //R
	int AficionadosEnPila();
	int SociosEnCola();
	int SimpatizantesEnCola();
    int AficionadosEnLista();
	int AficionadosEnArbol();
    ~Gestor();
    
private:
	Pila pila_aficionados;
	Cola cola_simpatizantes;
	Cola cola_socios;
	Lista lista_aficionados;
	Arbol arbol_aficionados;
};

#endif // GESTOR_HPP
