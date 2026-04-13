#pragma once

#include <string>

class Producto {
private:
    std::string codigoProducto;
    std::string nombreProducto;
    std::string categoria;
    double precioUnitario;
    int stock;

public:
    Producto();

    Producto(const std::string& codigo,
        const std::string& nombre,
        const std::string& categoria,
        double precioUnitario,
        int stock);

    const std::string getCodigoProducto() const;
    const std::string getNombreProducto() const;
    const std::string getCategoria() const;
    const double getPrecioUnitario() const;
    int getStock() const;

    void setNombreProducto(const std::string& InNombre);
    void setCategoria(const std::string& InCategoria);
    void setPrecioUnitario(double InPrecioUnitario);
    void setStock(int InStock);

    // Operadores de comparación (para el ABB)
    bool operator<(const Producto& otro) const;
    bool operator>(const Producto& otro) const;
    bool operator==(const Producto& otro) const;
    bool operator!=(const Producto& otro) const;
};