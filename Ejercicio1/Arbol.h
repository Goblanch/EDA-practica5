#pragma once

#include "Nodo.h"
#include "IArbol.h"
#include <memory>

class Arbol : public IArbol {
public:
    Arbol();

    std::shared_ptr<NodoArbol<Producto>> getRaiz() const;

    void setRaiz(const std::shared_ptr<NodoArbol<Producto>>& nodo);

    void insertarNodoABBIter(const Producto &producto) override;

    void recorrerInOrder() const override;

    bool estaVacio() const override;

    int calcularNivelProductoITER(const std::string &codigo) const override;

    std::shared_ptr<IArbol> crearEspejoABB_Rec() const override;

private:
    std::shared_ptr<NodoArbol<Producto>> raiz;

    void recorrerInOrdenRec(const std::shared_ptr<NodoArbol<Producto>>& nodo) const;

    static std::shared_ptr<NodoArbol<Producto>> copiarEspejoNodoRec(std::shared_ptr<NodoArbol<Producto>> origen);
};
