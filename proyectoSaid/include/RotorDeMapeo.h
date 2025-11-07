// RotorDeMapeo.h
#ifndef ROTORDEMAPEO_H
#define ROTORDEMAPEO_H

#include "Primitivas.h"
#include <iostream>

/**
 * @brief Implementa el Rotor de Mapeo como una Lista Circular Doblemente Enlazada Manual.
 * * Actúa como un "disco de cifrado" rotatorio que contiene el alfabeto (A-Z, ' ').
 */
class RotorDeMapeo {
private:
    NodoRotor* cabeza; ///< Puntero al inicio lógico del rotor (determina el desplazamiento actual).

    NodoRotor* buscarNodo(char in); ///< Método auxiliar para encontrar un carácter en la lista.

public:
    RotorDeMapeo();
    ~RotorDeMapeo();
    void inicializar(); ///< Carga los 27 caracteres ('A'-'Z' y ' ') y configura la circularidad.

    /**
     * @brief Rota el puntero cabeza N posiciones de forma circular.
     * * Mueve el puntero cabeza sin mover los datos, implementando la rotación eficiente.
     * @param N Número de posiciones a rotar (positivo: adelante, negativo: atrás).
     */
    void rotar(int N);

    /**
     * @brief Realiza la lógica de decodificación (mapeo) basada en la rotación actual.
     * * Calcula el carácter decodificado tomando la posición relativa del fragmento 'in'
     * respecto al inicio original ('A') y aplicando el desplazamiento actual de 'cabeza'.
     * @param in Carácter a decodificar (fragmento de la TramaLoad).
     * @return char Carácter decodificado.
     */
    char getMapeo(char in);
};

#endif // ROTORDEMAPEO_H
