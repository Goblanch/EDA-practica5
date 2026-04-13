#include "Producto.h"

Producto::Producto() : codigoProducto(""), nombreProducto(""), categoria(""), precioUnitario(0.0), stock(0)
{}

Producto::Producto(const std::string &codigo, const std::string &nombre, const std::string &categoria,
    double precioUnitario, int stock)
        : codigoProducto(codigo), nombreProducto(nombre), categoria(categoria), precioUnitario(precioUnitario), stock(stock)
{}

const std::string Producto::getCodigoProducto() const { return codigoProducto; }

const std::string Producto::getNombreProducto() const { return nombreProducto; }

const std::string Producto::getCategoria() const { return categoria; }

const double Producto::getPrecioUnitario() const { return precioUnitario; }

int Producto::getStock() const { return stock; }

void Producto::setNombreProducto(const std::string &InNombre) { nombreProducto = InNombre; }

void Producto::setCategoria(const std::string &InCategoria) { categoria = InCategoria; }

void Producto::setPrecioUnitario(double InPrecioUnitario) { precioUnitario = InPrecioUnitario; }

void Producto::setStock(int InStock) { stock = InStock; }

bool Producto::operator<(const Producto &otro) const {
    return codigoProducto < otro.codigoProducto;
}

bool Producto::operator>(const Producto &otro) const {
    return codigoProducto > otro.codigoProducto;
}

bool Producto::operator==(const Producto &otro) const {
    return codigoProducto == otro.codigoProducto;
}

bool Producto::operator!=(const Producto &otro) const {
    return !(*this == otro);
}
