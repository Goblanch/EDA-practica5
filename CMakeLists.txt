cmake_minimum_required(VERSION 3.20)
project(EDA_P5GA1_E1_26 LANGUAGES CXX)

# ── Estándar C++11 obligatorio ─────────────────────────────────
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++11, no -std=gnu++11

# ── Warnings equivalentes al Makefile original ─────────────────
add_compile_options(-Wall -Wextra -pedantic)

# ── Ejecutable ─────────────────────────────────────────────────
add_executable(${PROJECT_NAME}
        Ejercicio1/mainE1.cpp
        Ejercicio1/Producto.h
        Ejercicio1/Producto.cpp
        Ejercicio1/Nodo.h
        Ejercicio1/IArbol.h
        Ejercicio1/Arbol.h
        Ejercicio1/Arbol.cpp
        Ejercicio1/GestorInventario.h
        Ejercicio1/GestorInventario.cpp
)

# ── Directorio de includes ─────────────────────────────────────
# Permite que los #include entre archivos de Ejercicio1 se resuelvan
# correctamente sin necesidad de rutas relativas en el código fuente.
target_include_directories(${PROJECT_NAME} PRIVATE Ejercicio1)