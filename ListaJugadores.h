#pragma once
#include <iostream>
#include <memory>
#include "Jugador.h"

class ListaJugadores {
private:

    struct Nodo {
        Jugador dato;
        std::shared_ptr<Nodo> sig;

        Nodo(const Jugador& j) : dato(j), sig(nullptr) {}
    };

    std::shared_ptr<Nodo> cabeza;

public:

    ListaJugadores() : cabeza(nullptr) {}

    void insertarJugadorEnOrden(Jugador &jug) {

        auto nuevo = std::make_shared<Nodo>(jug);

        if (!cabeza || jug.getNickname() < cabeza->dato.getNickname()) {
            nuevo->sig = cabeza;
            cabeza = nuevo;
            // Cambiamos al primero de la lista por el nuevo que ha entrado y el anterior se va al puntero sig
            return;
        }

        // Puntero auxiliar para no perder el inicio de la lista
        std::shared_ptr<Nodo> actual = cabeza;

        while (actual->sig &&
               actual->sig->dato.getNickname() < jug.getNickname()) {
            actual = actual->sig;
            // Bajamos una posición constantemente hasta que el nodo que queremos introducir sea el nick mayor que el que comparamos en la lista
               }
        // Asignamos nuevas posiciones
        // Primero conectamos el nuevo y luego lo metemos a la lista
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
    }

    void mostrarRanking() const {

        auto auxiliar = cabeza;
        int contador = 1;
        while (auxiliar)
        {
            std::cout << "Jugador número " <<contador <<std::endl;
            std::cout<< "-------------------------------" <<std::endl;
            std::cout << "Nickname: " << auxiliar->dato.getNickname()<<std::endl;
            std::cout << " Equipo: " << auxiliar->dato.getEquipo()<<std::endl;
            std::cout << " Nivel: " << auxiliar->dato.getNivel() <<std::endl;
            std::cout << " Puntuación: " << auxiliar->dato.getPuntuacion() << std::endl;
            contador++;
            auxiliar = auxiliar->sig;
        }
    }

    int contarJugadores() {

        int contador = 0;
        auto auxiliar = cabeza;

        while (auxiliar) {
            contador++;
            auxiliar = auxiliar->sig;
        }
        return contador;
    }

    int contarBaneados() const {
        int contador = 0;
        auto auxiliar = cabeza;
        while (auxiliar) {
            if (auxiliar->dato.getPuntuacion() < 0) {
                contador++;
            }
            auxiliar = auxiliar->sig;
        }

        return contador;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }
};