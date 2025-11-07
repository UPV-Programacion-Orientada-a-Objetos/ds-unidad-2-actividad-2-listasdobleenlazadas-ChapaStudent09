// ListaDeCarga.cpp
/**
 * @file ListaDeCarga.cpp
 * @brief Implementación de la Lista Doblemente Enlazada Manual.
 */
#include "ListaDeCarga.h"

ListaDeCarga::ListaDeCarga() : cabeza(nullptr), cola(nullptr) {}

ListaDeCarga::~ListaDeCarga() {
    NodoCarga* actual = cabeza;
    while (actual != nullptr) {
        NodoCarga* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza = nullptr;
    cola = nullptr;
}

void ListaDeCarga::insertarAlFinal(char dato) {
    NodoCarga* nuevoNodo = new NodoCarga(dato);

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }

    // Muestra el estado actual del mensaje (requisito del caso de estudio)
    std::cout << "-> Fragmento '" << dato << "' decodificado. Mensaje: [";
    NodoCarga* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->dato << (temp->siguiente == nullptr ? "" : "][");
        temp = temp->siguiente;
    }
    std::cout << "]\n";
}

void ListaDeCarga::imprimirMensaje() {
    std::cout << "MENSAJE OCULTO ENSAMBLADO:\n";
    NodoCarga* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato;
        actual = actual->siguiente;
    }
    std::cout << "\n";
}
