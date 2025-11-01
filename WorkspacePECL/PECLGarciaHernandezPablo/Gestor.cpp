#include "Gestor.hpp"

Gestor::Gestor(){}

void Gestor::genera10Aficionados()
{
    int n = 1;
    while(pila_aficionados.idInPila(n) || cola_simpatizantes.idInCola(n) || cola_socios.idInCola(n) || 
    lista_aficionados.idInLista(n)) {
        n += 10;
    }
    int lista[10];
    for(int i = 0; i < 10; ++i) {
        lista[i] = i + n;
    }
    random_shuffle(lista, lista + 10);
    for(int i = 0; i < 10; ++i) {
        Aficionado* a = new Aficionado(lista[i]);
        pila_aficionados.insertar(a);
    }
}
void Gestor::muestraAficionados()
{
    pila_aficionados.mostrar();
}
void Gestor::borraAficionadosPila()
{
    while(pila_aficionados.getLongitud()) {
        Aficionado* a = pila_aficionados.extraer();
        delete(a);
    }
}
void Gestor::encolarAficionados()
{
    while(pila_aficionados.getLongitud()) {
        Aficionado* a = pila_aficionados.extraer();
        if(a->esSocio() == 1) {
            cola_socios.insertar(a);
        } else {
            cola_simpatizantes.insertar(a);
        }
    }
}
void Gestor::muestraSociosCola()
{
    cola_socios.mostrar();
}
void Gestor::muestraSimpatizantesCola()
{
    cola_simpatizantes.mostrar();
}
void Gestor::borraAficionadosColas()
{
    while(cola_socios.getLongitud()) {
        Aficionado* a = cola_socios.extraer();
        delete(a);
    }
    while(cola_simpatizantes.getLongitud()) {
        Aficionado* a = cola_simpatizantes.extraer();
        delete(a);
    }
}
void Gestor::enlistarAficionados()
{
    while(cola_socios.getLongitud()) {
        Aficionado* a = cola_socios.extraer();
        lista_aficionados.insertar_orden(a);
    }
    while(cola_simpatizantes.getLongitud()) {
        Aficionado* a = cola_simpatizantes.extraer();
        lista_aficionados.insertar_orden(a);
    }
}
void Gestor::buscarAficionados()
{
    lista_aficionados.mostrar();
	lista_aficionados.buscar();
}
void Gestor::reiniciar()
{
    while(pila_aficionados.getLongitud()) {
        Aficionado* a = pila_aficionados.extraer();
        delete(a);
    }
    while(cola_socios.getLongitud()) {
        Aficionado* a = cola_socios.extraer();
        delete(a);
    }
    while(cola_simpatizantes.getLongitud()) {
        Aficionado* a = cola_simpatizantes.extraer();
        delete(a);
    }
    while(lista_aficionados.getLongitud()) {
        Aficionado* a = lista_aficionados.extraerIzq();
        delete(a);
    }
}
int Gestor::AficionadosEnPila(){return pila_aficionados.getLongitud();}
int Gestor::SociosEnCola(){return cola_socios.getLongitud();}
int Gestor::SimpatizantesEnCola(){return cola_simpatizantes.getLongitud();}
int Gestor::AficionadosEnLista(){return lista_aficionados.getLongitud();}

Gestor::~Gestor(){}
