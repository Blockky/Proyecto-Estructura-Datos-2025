#include "Aficionado.hpp"

class NodoPila
{
public:
    NodoPila(Aficionado* a = NULL, NodoPila* sig = NULL);
    ~NodoPila();

private:
	Aficionado* aficionado;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;
