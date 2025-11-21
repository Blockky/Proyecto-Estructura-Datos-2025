#include "Arbol.hpp"

Arbol::Arbol()
{
    raiz = nullptr;
    longitud = 0;
}

int Arbol::getLongitud() { return this->longitud; }

void Arbol::minimoSocio() { 
	raiz = raiz->izq;
	if(raiz->izq)
		raiz = raiz->izq;
		
	return raiz->aficionado->mostrar();
 }
void Arbol::minimoSimpatizante(){
	raiz = raiz->der;
	if(raiz->izq)
		raiz = raiz->izq;
	return raiz->aficionado->mostrar();
}


void Arbol::insertar(Aficionado* a)
{
    if(raiz == nullptr) {
        Aficionado* ficticio = new Aficionado(0);
        raiz = new NodoArbol(ficticio);
    }

    if(a->esSocio())
        raiz->izq = insertar(raiz->izq, a);
    else
        raiz->der = insertar(raiz->der, a);
}
pnodoAbb Arbol::insertar(pnodoAbb nodo, Aficionado* a)
{
    /* if(!nodo)
         return new NodoArbol(a);
     if(a->esSocio() && nodo->izq==nullptr)
         nodo->izq = insertar(nodo->izq, a);
     else if(!a->esSocio() && nodo->der==nullptr)
         nodo->der = insertar(nodo->der, a);
     else if(a->esSocio() && a->getID() < nodo->izq->aficionado->getID())
         nodo->izq->izq = insertar(nodo->izq->izq, a);
     else if(a->esSocio())
         nodo->izq->der = insertar(nodo->izq->der, a);
     else if(a->getID() < nodo->der->aficionado->getID())
         nodo->der->izq = insertar(nodo->der->izq, a);
     else
         nodo->der->der = insertar(nodo->der->der, a);
     return nodo;*/

    if(!nodo) {
        this->longitud++;
        return new NodoArbol(a);
    }

    if(a->getID() < nodo->aficionado->getID())

        nodo->izq = insertar(nodo->izq, a);

    else
        nodo->der = insertar(nodo->der, a);

    return nodo;
}

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->aficionado->getID() << " ";
    pintar(nodo->der);
}
int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->aficionado->getID(); // En vez de este valor, tenéis que cambiarlo en vuestra práctica.
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->aficionado->getID(); // En vez de este valor, tenéis que cambiarlo en vuestra práctica.
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

void Arbol::mostrarOrden(pnodoAbb nodo){
	if(!nodo) return;
	else{
		mostrarOrden(nodo->izq);
		nodo->aficionado->mostrar();
		mostrarOrden(nodo->der);
	}
}

void Arbol::mostrarOrdenSocios(){
	mostrarOrden(raiz->izq);
}

void Arbol::mostrarOrdenSimpatizantes(){
	mostrarOrden(raiz->der);
}

void Arbol::mostrarInorden(){
	mostrarOrden(raiz);
}

void Arbol::mostrarHojas(pnodoAbb nodo){
	if(!nodo) return;
	else{
		mostrarHojas(nodo->izq);
		if(esNodoHoja(nodo)) nodo->aficionado->mostrar();
		mostrarHojas(nodo->der);
	}
}
void Arbol::mostrarHojas2(){
	mostrarHojas(raiz);
}
bool Arbol::esNodoHoja(pnodoAbb nodo){
	if(!nodo->izq && !nodo->der) return 1;
	else return 0;
}
Arbol::~Arbol() {}
