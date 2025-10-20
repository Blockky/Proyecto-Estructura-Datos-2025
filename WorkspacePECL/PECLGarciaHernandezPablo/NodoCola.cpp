#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado* a, NodoCola* sig)
{
	aficionado = a;
	siguiente = sig;
	}
NodoCola::~NodoCola(){}