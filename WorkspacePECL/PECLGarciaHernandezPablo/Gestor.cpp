#include "Gestor.hpp"

Gestor::Gestor()
{
   	afiEnPila = 0;
	socEnCola = 0;
	simEnCola = 0;
}
void Gestor::genera10Aficionados(){
	int n = 1;
	while (pila_aficionados.idInPila(n) || cola_simpatizantes.idInCola(n) || cola_socios.idInCola(n)){
		n += 10;
	}
    int lista[10];
    for(int i = 0; i < 10; ++i) {
        lista[i] = i+n;
    }
    random_shuffle(lista, lista + 10);
	for(int i = 0; i<10; ++i){
        Aficionado* a = new Aficionado(lista[i]);
        pila_aficionados.insertar(a);
    }
    afiEnPila += 10;
}
void Gestor::muestraAficionados(){
    pila_aficionados.mostrar();
}
void Gestor::borraAficionadosPila(){
	while(afiEnPila){
		Aficionado* a = pila_aficionados.extraer();
		delete(a);
		afiEnPila--;
	}
}
void Gestor::encolarAficionados()
{
	while(afiEnPila){
		Aficionado* a = pila_aficionados.extraer();
		if (a->esSocio() == 1){
			cola_socios.insertar(a);
			socEnCola++;
		} else {
			cola_simpatizantes.insertar(a);
			simEnCola++;
		}
		afiEnPila--;
	}
}
void Gestor::muestraSociosCola()
{
	cola_socios.mostrar();
}
int Gestor::AficionadosEnPila(){
	return afiEnPila;
}
int Gestor::SociosEnCola(){
	return socEnCola;
}
int Gestor::SimpatizantesEnCola(){
	return simEnCola;
}
void Gestor::muestraSimpatizantesCola(){
	cola_simpatizantes.mostrar();
}
void Gestor::borraAficionadosColas(){
	while(socEnCola){
		Aficionado* a = cola_socios.eliminar();
		delete(a);
		socEnCola--;
	}
	while(simEnCola){
		Aficionado* a = cola_simpatizantes.eliminar();
		delete(a);
		simEnCola--;
	}
}
Gestor::~Gestor()
{
}
