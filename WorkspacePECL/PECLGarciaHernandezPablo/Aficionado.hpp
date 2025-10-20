#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP
#include <iostream>
#include <iomanip>
using namespace std;
class Aficionado
{
private:
    int ID;
    bool socio; // 1: Socio, 0: Simpatizante
    int llegada;	
	friend class Pila;

public:
	Aficionado(int id);   
 
    ~Aficionado();
	void setLlegada(int llegada);
	void mostrar();
	bool esSocio();
	int getLlegada();
};

#endif // AFICIONADO_HPP
