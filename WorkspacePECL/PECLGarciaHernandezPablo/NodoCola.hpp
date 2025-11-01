#include "Aficionado.hpp"

class NodoCola
{
public:
	NodoCola(Aficionado* a = NULL, NodoCola* sig = NULL);
	~NodoCola();
	
private:
	Aficionado* aficionado;
	NodoCola* siguiente;
	friend class Cola;
};

typedef NodoCola* pnodoCola;
