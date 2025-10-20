#include "Gestor.hpp"

Gestor::Gestor()
{
   
}
void Gestor::genera10Aficionados(){
    int n = pila_aficionados.contador;
    int lista[10];
    for(int i = 1; i < 11; ++i) {
        lista[i-1] = i+n;
    }
    random_shuffle(lista, lista + 10);
	for(int i = 0; i<10; ++i){
        Aficionado* a = new Aficionado(lista[i]);
        pila_aficionados.insertar(a);
    }
    pila_aficionados.acutualizarCuenta(10);
}
void Gestor::muestraAficionados(){
    pila_aficionados.mostrar();
}
void Gestor::borraAficionadosPila(){
	int n_aficionados = pila_aficionados.contador;
	while(n_aficionados>0)
	pila_aficionados.extraer();
}
void Gestor::encolarAficionados()
{
	
}
Gestor::~Gestor()
{
}
