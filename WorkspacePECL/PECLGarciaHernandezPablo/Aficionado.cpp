#include <Aficionado.hpp>

Aficionado::Aficionado(int id)
{
		this->llegada = (rand()%60);
		this->socio = 1-(id%2);
		this->ID = id;
}

int Aficionado::getLlegada()
{
	return this->llegada;
}

bool Aficionado::esSocio()
{
	return this->socio;
}

void Aficionado::mostrar()
{
	string _socio = "El simpatizante";
	if(socio){
		_socio = "El socio";
	}
    cout << "\t" << setw(20) << _socio << " con ID " << this->ID << " entró en el minuto " << this->llegada << endl;
}

Aficionado::~Aficionado()
{
}
