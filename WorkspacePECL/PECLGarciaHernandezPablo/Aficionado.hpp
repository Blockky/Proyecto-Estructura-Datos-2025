#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP
#include <iostream>
#include <iomanip>
using namespace std;

class Aficionado
{
public:
	Aficionado(int id);   
    ~Aficionado();
	void mostrar();
	bool esSocio();
	int getLlegada();
	int getID();
    
private:
    int ID;
    bool socio; // 1: Socio, 0: Simpatizante
    int llegada;	
	friend class Pila;
};

#endif // AFICIONADO_HPP
