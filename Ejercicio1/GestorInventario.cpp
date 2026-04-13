#include "GestorInventario.h"
#include <iostream>

GestorInventario::GestorInventario(std::shared_ptr<IArbol> arbol) : arbol_(arbol) {}

void GestorInventario::crearInventarioABB(const std::vector<Producto> &productos) {
    for (const Producto &p : productos) {
        arbol_->insertarNodoABBIter(p);
    }
}

void GestorInventario::mostrarInventario() const {
    std::cout << "\n+============================================================================+\n";
    std::cout << "|        INVENTARIO ABB - Recorrido InOrden (Asc. por Codigo)               |\n";
    std::cout << "+============================================================================+\n";

    if (arbol_->estaVacio()) {
        std::cout << "[ERROR] El arbol esta vacio. No hay productos que mostrar.\n";
        return;
    }

    arbol_->recorrerInOrder();
}

void GestorInventario::consultarNivel(const std::string &codigo) const {
    int nivel = arbol_->calcularNivelProductoITER(codigo);

    std::cout << "\n-- Consulta de Nivel --------------------------------------------------------\n";
    if (nivel == -1) {
        std::cout << "  Codigo \"" << codigo << "\": NO encontrado en el ABB.\n";
    } else {
        std::cout << "  Codigo \"" << codigo << "\": encontrado en el nivel " << nivel << ".\n";
        if (nivel == 0) std::cout << "  (Es la raiz del arbol)\n";
    }
}

void GestorInventario::mostrarEspejo() const {
    std::cout << "\n+============================================================================+\n";
    std::cout << "|         ARBOL ESPEJO - Recorrido InOrden (Desc. por Codigo)               |\n";
    std::cout << "+============================================================================+\n";

    // El espejo se destruye automaticamente al salir de este scope
    std::shared_ptr<IArbol> espejo = arbol_->crearEspejoABB_Rec();
    espejo->recorrerInOrder();
}