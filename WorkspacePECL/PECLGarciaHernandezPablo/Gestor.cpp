#include "Gestor.hpp"

Gestor::Gestor()
{
   
}
void Gestor::genera10Aficionados(){
    int nEnPila = pila_aficionados.aficiEnPila;
	int nEnColas = pila_aficionados.aficiEnColas;
	int n = nEnPila + nEnColas;
    int lista[10];
    for(int i = 1; i < 11; ++i) {
        lista[i-1] = i+n;
    }
    random_shuffle(lista, lista + 10);
	for(int i = 0; i<10; ++i){
        Aficionado* a = new Aficionado(lista[i]);
        pila_aficionados.insertar(a);
    }
    pila_aficionados.aficiEnPila += 10;
}
void Gestor::muestraAficionados(){
    pila_aficionados.mostrar();
}
void Gestor::borraAficionadosPila(){
	int n = pila_aficionados.aficiEnPila;
	while(n){
		pila_aficionados.extraer();
		n--;
	}
	pila_aficionados.aficiEnPila = 0;	
}
void Gestor::encolarAficionados()
{
	int n = pila_aficionados.aficiEnPila;
	int m = pila_aficionados.aficiEnColas;
	while(n){
		Aficionado* a = pila_aficionados.extraer();
		if (a->esSocio() == 1){
			cola_socios.insertar(a);
		} else {
			cola_simpatizantes.insertar(a);
		}
		n--;
		m++;
	}
	pila_aficionados.aficiEnPila = n;
	pila_aficionados.aficiEnColas = m;
}
void Gestor::muestraSociosCola()
{
	cola_socios.mostrar();
}
int Gestor::AficionadosEnPila(){
	return pila_aficionados.aficiEnPila;
}
Gestor::~Gestor()
{
}
