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
	void minimoSocio();
	void minimoSimpatizante();
    int getLongitud();
	void mostrarOrden(pnodoAbb nodo);
	void mostrarOrdenSocios();
	void mostrarOrdenSimpatizantes();
	void mostrarInorden();
	void mostrarHojas(pnodoAbb);
	void mostrarHojas2();
    ~Arbol();
	

private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Aficionado*);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
	bool esNodoHoja(pnodoAbb nodo);
    int longitud;
};

#endif // ARBOL_HPP
