#include "NodoCola.hpp"

NodoCola::NodoCola(const Aficionado& a, NodoCola* sig):aficionado(a),siguiente(sig){}
NodoCola::~NodoCola(){}