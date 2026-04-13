#include "Arbol.h"
#include <iostream>
#include <iomanip>

Arbol::Arbol() : raiz(nullptr) {}

std::shared_ptr<NodoArbol<Producto>> Arbol::getRaiz() const {
    return raiz;
}

void Arbol::setRaiz(const std::shared_ptr<NodoArbol<Producto>>& nodo) {
    raiz = nodo;
}

void Arbol::insertarNodoABBIter(const Producto& producto) {
    auto nuevo = std::make_shared<NodoArbol<Producto>>(producto);

    if (estaVacio()) {
        raiz = nuevo;
        return;
    }

    std::shared_ptr<NodoArbol<Producto>> actual = raiz;
    std::shared_ptr<NodoArbol<Producto>> padre;

    while (actual != nullptr) {
        padre = actual;
        if (producto < actual->getData()) {
            actual = actual->getIzq();
        } else if (producto > actual->getData()) {
            actual = actual->getDer();
        } else {
            return;
        }
    }

    if (producto < padre->getData()) {
        padre->setIzq(nuevo);
    } else {
        padre->setDer(nuevo);
    }
}

void Arbol::recorrerInOrder() const {
    if (estaVacio()) {
        std::cout << "[ERROR] El arbol esta vacio. No hay contenido que mostrar.\n";
        return;
    }

    std::cout << std::left
              << std::setw(14) << "Codigo"
              << std::setw(28) << "Nombre"
              << std::setw(16) << "Categoria"
              << std::setw(10) << "Precio"
              << std::setw(8)  << "Stock"
              << "\n";
    std::cout << std::string(76, '-') << "\n";

    recorrerInOrdenRec(raiz);
}

bool Arbol::estaVacio() const {
    return raiz == nullptr;
}

int Arbol::calcularNivelProductoITER(const std::string& codigo) const {
    if (estaVacio()) return -1;

    std::shared_ptr<NodoArbol<Producto>> actual = raiz;
    int nivel = 0;

    while (actual != nullptr) {
        const std::string& codigoActual = actual->getData().getCodigoProducto();
        if (codigo == codigoActual) {
            return nivel;
        } else if (codigo < codigoActual) {
            actual = actual->getIzq();
        } else {
            actual = actual->getDer();
        }
        ++nivel;
    }

    return -1;
}

std::shared_ptr<IArbol> Arbol::crearEspejoABB_Rec() const {
    auto espejo = std::make_shared<Arbol>();
    espejo->raiz = copiarEspejoNodoRec(raiz);
    return espejo;
}

void Arbol::recorrerInOrdenRec(const std::shared_ptr<NodoArbol<Producto>>& nodo) const {
    if (nodo == nullptr) return;

    recorrerInOrdenRec(nodo->getIzq());

    std::cout << std::left
              << std::setw(14) << nodo->getData().getCodigoProducto()
              << std::setw(28) << nodo->getData().getNombreProducto()
              << std::setw(16) << nodo->getData().getCategoria()
              << std::fixed << std::setprecision(2)
              << std::setw(10) << nodo->getData().getPrecioUnitario()
              << std::setw(8)  << nodo->getData().getStock()
              << "\n";

    recorrerInOrdenRec(nodo->getDer());  // <- visita subárbol derecho
}

std::shared_ptr<NodoArbol<Producto>> Arbol::copiarEspejoNodoRec(std::shared_ptr<NodoArbol<Producto>> origen) {
    if (origen == nullptr) return nullptr;

    auto nuevo = std::make_shared<NodoArbol<Producto>>(origen->getData());
    nuevo->setIzq(copiarEspejoNodoRec(origen->getDer()));
    nuevo->setDer(copiarEspejoNodoRec(origen->getIzq()));
    return nuevo;
}