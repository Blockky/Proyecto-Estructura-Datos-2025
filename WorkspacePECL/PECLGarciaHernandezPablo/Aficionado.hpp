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
	void generarID();
	
    
public:
	Aficionado(int llegada);   
 
    ~Aficionado();
	void setID(int ID);
	void mostrar();
	bool esSocio();
	int getID();
};

#endif // AFICIONADO_HPP
