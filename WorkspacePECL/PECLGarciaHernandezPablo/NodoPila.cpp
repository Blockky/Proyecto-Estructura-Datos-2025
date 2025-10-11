#include "NodoPila.hpp"
//hay que definirlo como constante la referencia porque si no no compila ya que no relaciona 
//la declaracion en hpp y cpp
NodoPila::NodoPila(const Aficionado& a, NodoPila* sig):aficionado(a),siguiente(sig){}

NodoPila::~NodoPila()//alt + 126 para la tilde
{
	
}