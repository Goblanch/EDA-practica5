#pragma once

#include <memory>

template<typename T>
class NodoArbol {
private:
    T data;
    std::shared_ptr<NodoArbol<T>> izq_;
    std::shared_ptr<NodoArbol<T>> der_;

public:
    NodoArbol(const T& dato) : data(dato), izq_(nullptr), der_(nullptr) {}

    const T& getData() const { return data; }
    std::shared_ptr<NodoArbol<T>> getIzq() { return izq_; }
    std::shared_ptr<NodoArbol<T>> getDer() { return der_; }

    void setData(const T& dato) { data = dato; }
    void setIzq(std::shared_ptr<NodoArbol<T>> izq) { izq_ = izq; }
    void setDer(std::shared_ptr<NodoArbol<T>> der) { der_ = der; }
};