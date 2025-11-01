#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado* a, NodoPila* sig)
{
    aficionado = a;
    siguiente = sig;
}
NodoPila::~NodoPila(){}
