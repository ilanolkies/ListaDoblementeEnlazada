#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <ostream>

typedef unsigned long Nat;

template<typename T>
class Lista {
public:
    Lista();

    Lista(const Lista &l);

    ~Lista();

    Lista &operator=(const Lista &aCopiar);

    void agregarAdelante(const T &elem);

    void agregarAtras(const T &elem);

    int longitud() const;

    const T &iesimo(Nat i) const;

    T &iesimo(Nat i);

    void eliminar(Nat i);

    void mostrar(std::ostream &o);

    friend std::ostream &operator<<(std::ostream &os, Lista &l) {
        l.mostrar(os);
        return os;
    }

private:

    struct Nodo {
        Nodo(T valor, Nodo *anterior, Nodo *siguiente)
                : valor(valor), anterior(anterior), siguiente(siguiente) {};

        T valor;
        Nodo *anterior;
        Nodo *siguiente;
    };

    Nodo *primero;
    Nodo *ultimo;

    int _longitud;

    Lista<T>::Nodo *identificar(Nat i) const;

    void limpiar() const;

    void reiniciar();
};

#include "Lista.hpp"

#endif
