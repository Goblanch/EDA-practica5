#pragma once

#include <string>
#include "Producto.h"

class IArbol {
public:
    virtual ~IArbol() = default;

    virtual void insertarNodoABBIter(const Producto& producto) = 0;

    virtual void recorrerInOrder() const = 0;

    virtual bool estaVacio() const = 0;

    virtual int calcularNivelProductoITER(const std::string& codigo) const = 0;

    virtual std::shared_ptr<IArbol> crearEspejoABB_Rec() const = 0;
};