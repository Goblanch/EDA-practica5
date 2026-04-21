#include "GestorTorneo.h"
#include "ListaJugadores.h"
#include <iostream>

void GestorTorneo::agregarInscripcion(Jugador &jug) {
    inscripciones.push(jug);
}

void GestorTorneo::crearRegistroOrdenado() {
    while (!inscripciones.isEmpty()) {
        Jugador jug = inscripciones.top();
        inscripciones.pop();
        ranking.insertarJugadorEnOrden(jug);
    }
}

void GestorTorneo::mostrarRanking() const {
    if (ranking.estaVacia()) {
        std::cout << "No hay jugadores en el ranking." << std::endl;
        return;
    }
    ranking.mostrarRanking();
}

double GestorTorneo::calcularPorcentajeBaneados() const {
    int total = ranking.contarJugadores();
    if (total == 0) return 0.0;
    int baneados = ranking.contarJugadores();

    return (static_cast<double>(baneados) / total) * 100.0;
}
