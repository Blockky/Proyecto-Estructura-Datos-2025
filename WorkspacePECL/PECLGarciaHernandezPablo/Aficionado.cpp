#include "Aficionado.hpp"

Aficionado::Aficionado(int id)
{
    this->llegada = (rand() % 60);
    this->socio = 1 - (id % 2);
    this->ID = id;
}
int Aficionado::getLlegada() 
{
    return this->llegada;
}
int Aficionado::getID()
{
    return this->ID;
}
bool Aficionado::esSocio()
{
    return this->socio;
}
void Aficionado::mostrar()
{
    string _socio = "El simpatizante";
    if(socio) {
        _socio = "El socio";
    }
    cout << setw(15) << _socio << " con ID " << setw(2) << this->ID << " entro en el minuto " << setw(2)
         << this->llegada << endl;
}
Aficionado::~Aficionado(){}
