#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
void Lista::insertar_orden(Aficionado* a)
{
    int llegada = a->getLlegada();
    bool socio = a->esSocio();
    pnodoLista ptr = new NodoLista(a);
    if(!primero){
        primero = ptr;
        ultimo = ptr;
    } else if(socio && llegada < primero->aficionado->getLlegada()) {
        ptr->siguiente = primero;
        primero = ptr;
    } else if(socio) {
        pnodoLista aux = primero;
        while(aux->siguiente && aux->siguiente->aficionado->esSocio() &&
        llegada > aux->siguiente->aficionado->getLlegada()){
            aux = aux->siguiente;
        }
        ptr->siguiente = aux->siguiente;
        aux->siguiente = ptr;
    } else {
        pnodoLista aux = primero;
        while(aux->siguiente && aux->siguiente->aficionado->esSocio()){
            aux = aux->siguiente;
        }
        while(aux->siguiente && llegada > aux->siguiente->aficionado->getLlegada()){
            aux = aux->siguiente;
        }
        ptr->siguiente = aux->siguiente;
        aux->siguiente = ptr;
    }
    if(!ptr->siguiente)
        ultimo = ptr;
    this->longitud++;
}
void Lista::buscar()
{
    if(primero){
        pnodoLista nodopri;
        nodopri = primero;
        int idpri = nodopri->aficionado->getID();
        cout << "\tEl aficionado con ID " << idpri << " es el primero en entrar" << endl;

        pnodoLista nodoult;
        nodoult = ultimo;
        int idult = nodoult->aficionado->getID();
        cout << "\tEl aficionado con ID " << idult << " es el ultimo en entrar" << endl;

        pnodoLista nodo;
        pnodoLista ultimoSocio;
        nodo = primero;

        while(nodo && nodo->aficionado->esSocio()) {
            ultimoSocio = nodo;
            nodo = nodo->siguiente;
        }
        int idUltimoSocio = ultimoSocio->aficionado->getID();
        if(ultimoSocio)
            cout << "\tEl ultimo socio en entrar tiene ID " << idUltimoSocio << endl;

        int idPrimerSimpatizante = nodo->aficionado->getID();
        if(nodo)
            cout << "\tEl primer simpatizante en entrar tiene ID " << idPrimerSimpatizante << endl;
    }
}
void Lista::mostrar()
{
    pnodoLista aux = primero;
    cout << "\tLos aficionados en la lista son:" << endl;
    while(aux) {
        cout << "\t->  ";
        aux->aficionado->mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}
bool Lista::idInLista(int i)
{
    int n;
	pnodoLista aux = this->primero;
	while(aux)
	{
		n = aux->aficionado->getID();
		if(n==i) return 1;
		aux=aux->siguiente;
	}
	return 0;
}
int Lista::getLongitud()
{
    return this->longitud;
}
Aficionado* Lista::extraerIzq()
{
	if(!primero) return NULL;
	pnodoLista nodo;
	nodo = primero;
	Aficionado* a = nodo->aficionado;
	primero = nodo->siguiente;
	delete nodo;
    if(!primero) ultimo = NULL;
    this->longitud--;
	return a;
}
Lista::~Lista()
{
    Aficionado* a;
	while(primero)
	{
		a = extraerIzq();
        delete(a);
        this->longitud--;
	}
}
