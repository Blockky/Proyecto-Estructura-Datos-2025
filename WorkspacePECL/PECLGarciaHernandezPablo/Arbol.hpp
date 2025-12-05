#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"

#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Aficionado* a);
    void pintar();
    void dibujar();
    int getLongitud();
	void mostrarInordenSocios();
	void mostrarInordenSimpatizantes();
	void mostrarInordenArbol();
	void mostrarHojas();
    void borrarPorID(int id);
	Aficionado* primerAficionado();
	Aficionado* ultimoSocio();
	Aficionado* primerSimpatizante();
	Aficionado* ultimoAficionado();
    ~Arbol();

private:
    pnodoAbb raiz;
    int longitud;

    pnodoAbb insertar(pnodoAbb, Aficionado*);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
	bool esNodoHoja(pnodoAbb nodo);
    void mostrarNodoInorden(pnodoAbb nodo);
	void mostrarNodoHoja(pnodoAbb nodo);
    pnodoAbb eliminarNodo(pnodoAbb nodo);
    pnodoAbb eliminarAficionado(int id, pnodoAbb nodo);
    Aficionado* maximo(pnodoAbb nodo);
	Aficionado* minimo(pnodoAbb nodo);
};

#endif // ARBOL_HPP
