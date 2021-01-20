#include "items/balas.h"

#define BALAS 5
#define MAX_BALAS 25


Balas::Balas(Posicion &posicion) : Item(posicion), cant_balas(BALAS) {}

Balas::~Balas() {}

void Balas::obtenerBeneficio(ContenedorDeElementos &contenedor,Jugador *jugador) {
    if (jugador->cantidad_balas() != MAX_BALAS) {
        jugador->agregar_balas(this->cant_balas);
    }
}
