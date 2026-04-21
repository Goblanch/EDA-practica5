#include <iostream>
#include "GestorTorneo.h"

int main() {

    GestorTorneo gestor;

    // Inscripciones.
    Jugador j1("Zephyr", "TeamAlpha", 10, 3200.0);
    Jugador j2("Artemis", "NightOwls", 5, -150.0); // Baneado
    Jugador j3("Kronos", "IronFist", 22, 4800.0);
    Jugador j4("Blaze", "TeamAlpha", 8, -50.0); // Baneado
    Jugador j5("Nova", "ShadowWolves", 15, 2100.0);
    Jugador j6("Aegis", "NightOwls", 3, 900.0);
    Jugador j7("Phantom", "IronFist", 30, -300.0); // Baneado
    Jugador j8("Titan", "ShadowWolves", 18, 4100.0);

    gestor.agregarInscripcion(j1);
    gestor.agregarInscripcion(j2);
    gestor.agregarInscripcion(j3);
    gestor.agregarInscripcion(j4);
    gestor.agregarInscripcion(j5);
    gestor.agregarInscripcion(j6);
    gestor.agregarInscripcion(j7);
    gestor.agregarInscripcion(j8);

    std::cout << "================================================" << std::endl;
    std::cout << "          GESTOR DE TORNEO DE E-SPORTS          "  << std::endl;
    std::cout << "================================================" << std::endl;

    // 1. Crear registro ordenado a partir de la pila
    std::cout << "\n[TAREA 1] Creando registro ordenado..." << std::endl;
    gestor.crearRegistroOrdenado();
    std::cout << "Registro creado correctamente." << std::endl;

    // 2. Mostrar el ranking ordenado alfabéticamente
    std::cout << "\n[TAREA 2] Ranking ordenado por nickname:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    gestor.mostrarRanking();

    // 3. Calcular porcentaje de jugadores baneados
    std::cout << "\n[TAREA 3] Porcentaje de jugadores baneados:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    double porcentaje = gestor.calcularPorcentajeBaneados();
    std::cout << "Baneados: " << porcentaje << "% del total de inscritos." << std::endl;

    return 0;
}