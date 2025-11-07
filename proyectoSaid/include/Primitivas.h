// Primitivas.h
#ifndef PRITMITIVAS_H
#define PRITMITIVAS_H

// Declaración forward para evitar dependencias circulares
class ListaDeCarga;
class RotorDeMapeo;

/**
 * @brief Estructura de nodo para la Lista Doblemente Enlazada (ListaDeCarga).
 */
struct NodoCarga {
    char dato; ///< El carácter decodificado almacenado.
    NodoCarga* anterior; ///< Puntero al nodo previo.
    NodoCarga* siguiente; ///< Puntero al nodo siguiente.

    /**
     * @brief Constructor para NodoCarga.
     * @param d El carácter a almacenar.
     */
    NodoCarga(char d) : dato(d), anterior(nullptr), siguiente(nullptr) {}
};

/**
 * @brief Estructura de nodo para la Lista Circular Doblemente Enlazada (RotorDeMapeo).
 */
struct NodoRotor {
    char caracter; ///< El carácter del alfabeto (A-Z, ' ').
    NodoRotor* anterior; ///< Puntero al nodo previo en la lista circular.
    NodoRotor* siguiente; ///< Puntero al nodo siguiente en la lista circular.

    /**
     * @brief Constructor para NodoRotor.
     * @param c El carácter del alfabeto.
     */
    NodoRotor(char c) : caracter(c), anterior(nullptr), siguiente(nullptr) {}
};

#endif // PRITMITIVAS_H
