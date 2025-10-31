#include "Gestor.hpp"

Gestor::Gestor()
{
    afiEnPila = 0;
    socEnCola = 0;
    simEnCola = 0;
    afiEnLista = 0;
}
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
    afiEnPila += 10;
}
void Gestor::muestraAficionados()
{
    pila_aficionados.mostrar();
}
void Gestor::borraAficionadosPila()
{
    while(afiEnPila) {
        Aficionado* a = pila_aficionados.extraer();
        delete(a);
        afiEnPila--;
    }
}
void Gestor::encolarAficionados()
{
    while(afiEnPila) {
        Aficionado* a = pila_aficionados.extraer();
        if(a->esSocio() == 1) {
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
void Gestor::muestraSimpatizantesCola()
{
    cola_simpatizantes.mostrar();
}
void Gestor::borraAficionadosColas()
{
    while(socEnCola) {
        Aficionado* a = cola_socios.extraer();
        delete(a);
        socEnCola--;
    }
    while(simEnCola) {
        Aficionado* a = cola_simpatizantes.extraer();
        delete(a);
        simEnCola--;
    }
}
void Gestor::enlistarAficionados()
{
    while(socEnCola) {
        Aficionado* a = cola_socios.extraer();
        lista_aficionados.insertar_orden(a);
        socEnCola--;
        afiEnLista++;
    }
    while(simEnCola) {
        Aficionado* b = cola_simpatizantes.extraer();
        lista_aficionados.insertar_orden(b);
        simEnCola--;
        afiEnLista++;
    }
}
void Gestor::buscarAficionados()
{
    lista_aficionados.mostrar();
}

int Gestor::AficionadosEnPila(){return afiEnPila;}
int Gestor::SociosEnCola(){return socEnCola;}
int Gestor::SimpatizantesEnCola(){return simEnCola;}
int Gestor::AficionadosEnLista(){return afiEnLista;}

Gestor::~Gestor(){}
