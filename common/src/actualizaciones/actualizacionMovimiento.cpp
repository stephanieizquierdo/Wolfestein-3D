#include "actualizaciones/actualizacionMovimiento.h"


ActualizacionMovimiento::ActualizacionMovimiento(Jugador* jugador) : jugador(jugador) {}


ActualizacionMovimiento::~ActualizacionMovimiento() {
    if (esCliente) delete jugador;
}

std::vector<char> ActualizacionMovimiento::serializar() {
    std::vector<char> informacion;
    std::vector<char> aux(4);
    aux = numberToCharArray(this->obtenerId());
    informacion.insert(informacion.end(), aux.begin(), aux.end());
    std::vector<char> jugadorSerializado = jugador->serializar();
    informacion.insert(informacion.end(), jugadorSerializado.begin(), jugadorSerializado.end());

    return informacion;
}

void ActualizacionMovimiento::deserializar(std::vector<char> &serializado) {
  this->jugador = new Jugador();
  this->esCliente = true;
  this->jugador->deserializar(serializado);
}
