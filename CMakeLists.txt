cmake_minimum_required(VERSION 3.30)
project(GestorTorneo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GestorTorneo
        main.cpp
        Jugador.h
        Pila.h
        ListaJugadores.h
        ListaJugadores.cpp
        GestorTorneo.h
        GestorTorneo.cpp
)