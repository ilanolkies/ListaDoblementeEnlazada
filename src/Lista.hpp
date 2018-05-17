#include "Lista.h"

template<typename T>
Lista<T>::Lista() {
    reiniciar();
}

template<typename T>
void Lista<T>::reiniciar() {
    primero = nullptr;
    ultimo = nullptr;
    _longitud = 0;
}

template<typename T>
Lista<T>::Lista(const Lista<T> &l) : Lista() {
    *this = l;
}

template<typename T>
Lista<T>::~Lista() {
    limpiar();
}

template<typename T>
void Lista<T>::limpiar() const {
    Nodo *siguiente_eliminar = primero;
    while (siguiente_eliminar != nullptr) {
        Nodo *a_eliminar = siguiente_eliminar;
        siguiente_eliminar = siguiente_eliminar->siguiente;
        delete a_eliminar;
    }
}

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l) {
    limpiar();
    reiniciar();

    Nodo *nodo = l.primero;
    while (nodo != nullptr) {
        agregarAtras(nodo->valor);
        nodo = nodo->siguiente;
    }

    return *this;
}

template<typename T>
void Lista<T>::agregarAdelante(const T &elem) {
    Nodo *nodo = new Nodo(elem, nullptr, primero);
    if (primero != nullptr)primero->anterior = nodo;
    primero = nodo;
    if (ultimo == nullptr) ultimo = nodo;
    _longitud++;
}

template<typename T>
void Lista<T>::agregarAtras(const T &elem) {
    Nodo *nodo = new Nodo(elem, ultimo, nullptr);
    if (ultimo != nullptr)ultimo->siguiente = nodo;
    ultimo = nodo;
    if (primero == nullptr) primero = nodo;
    _longitud++;
}

template<typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo *nodo = identificar(i);
    if (nodo != primero) nodo->anterior->siguiente = nodo->siguiente;
    else primero = nodo->siguiente;
    if (nodo != ultimo) nodo->siguiente->anterior = nodo->anterior;
    else ultimo = nodo->anterior;
    delete nodo;
    _longitud--;
}

template<typename T>
int Lista<T>::longitud() const {
    return _longitud;
}

template<typename T>
const T &Lista<T>::iesimo(Nat i) const {
    return iesimo(i);
}

template<typename T>
T &Lista<T>::iesimo(Nat i) {
    Nodo *nodo = identificar(i);
    return nodo->valor;
}

template<typename T>
void Lista<T>::mostrar(std::ostream &o) {
    o << "[";
    Nodo *nodo = primero;
    while (nodo != nullptr) {
        o << nodo->valor << ", ";
        nodo = nodo->siguiente;
    }
    o << "]";
}

template<typename T>
typename Lista<T>::Nodo *Lista<T>::identificar(Nat i) const {
    bool enLaPrimermitad = i <= _longitud / 2;
    Nodo *nodo = enLaPrimermitad ? primero : ultimo;
    if (enLaPrimermitad)
        for (int j = 0; j < i; ++j)
            nodo = nodo->siguiente;
    else
        for (int k = _longitud - 1; k > i; --k)
            nodo = nodo->anterior;

    return nodo;
}