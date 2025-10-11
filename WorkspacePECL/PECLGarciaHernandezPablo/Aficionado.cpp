#include <Aficionado.hpp>

Aficionado::Aficionado(int ID)
{
		this->ID = ID;
		this->socio = (rand()%2);
		this->generarID();
}

int Aficionado::getID()
{
	return this->ID;
}

bool Aficionado::esSocio()
{
	return this->socio;
}

void Aficionado::setID(int ID)
{
	this->ID = ID;
}

void Aficionado::mostrar()
{
	string _socio = "El simpatizante";
	if(socio){
		_socio = "El socio";
		cout << "\t" << setw(10) << socio << " con ID " << ID << " entró en el minuto " << llegada << endl;
	}
}

void Aficionado::generarID()
{
	for (int i = 0; i < 10; i++) {
        int num = rand() % 10;
        this->ID = ID + num;
    }
        
}
Aficionado::~Aficionado()
{
}

