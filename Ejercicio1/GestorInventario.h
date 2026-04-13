#pragma once
#include <memory>
#include <vector>
#include "IArbol.h"
#include "Producto.h"

class GestorInventario {
public:
    GestorInventario(std::shared_ptr<IArbol> arbol);

    void crearInventarioABB(const std::vector<Producto>& productos);

    void mostrarInventario() const;

    void consultarNivel(const std::string& codigo) const;

    void mostrarEspejo() const;

private:
    std::shared_ptr<IArbol> arbol_;
};