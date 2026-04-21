#pragma once

#include "Pila.h"
#include "ListaJugadores.h"
#include "Jugador.h"

class GestorTorneo {
private:
    Pila<Jugador> inscripciones;
    ListaJugadores ranking;

public:
    GestorTorneo() = default;

    void agregarInscripcion(Jugador& jug);

    void crearRegistroOrdenado();

    void mostrarRanking() const;

    double calcularPorcentajeBaneados() const;
};
