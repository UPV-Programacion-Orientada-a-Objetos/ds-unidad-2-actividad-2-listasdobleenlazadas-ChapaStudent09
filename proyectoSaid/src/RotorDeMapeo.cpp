// RotorDeMapeo.cpp
/**
 * @file RotorDeMapeo.cpp
 * @brief Implementación de la Lista Circular Doblemente Enlazada (RotorDeMapeo).
 */
#include "RotorDeMapeo.h"
#include <cstdlib> // Para abs si fuera necesario (aunque se evita con el módulo)
#include <cstring> // Para lógica de caracteres

RotorDeMapeo::RotorDeMapeo() : cabeza(nullptr) {}

RotorDeMapeo::~RotorDeMapeo() {
    if (cabeza == nullptr) return;

    NodoRotor* actual = cabeza->siguiente;
    while (actual != cabeza) {
        NodoRotor* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    delete cabeza;
    cabeza = nullptr;
}

void RotorDeMapeo::inicializar() {
    // Caracteres a usar: ' ' (Espacio) y 'A'-'Z' (27 elementos)
    const char caracteres[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int TAMANO_ROTOR = 27;

    NodoRotor* nuevoNodo = nullptr;
    NodoRotor* ultimo = nullptr;

    for (int i = 0; i < TAMANO_ROTOR; ++i) {
        nuevoNodo = new NodoRotor(caracteres[i]);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
            ultimo = cabeza;
        } else {
            // Conexión circular doble
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = ultimo;
            ultimo->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }
    std::cout << "Rotor de Mapeo inicializado con " << TAMANO_ROTOR << " elementos.\n";
}

void RotorDeMapeo::rotar(int N) {
    if (cabeza == nullptr) return;

    const int TAMANO_ROTOR = 27;
    // Normaliza la rotación para evitar vueltas innecesarias
    int rotaciones = N % TAMANO_ROTOR;

    if (rotaciones > 0) {
        for (int i = 0; i < rotaciones; ++i) {
            cabeza = cabeza->siguiente; // Rotar a la derecha (positivo)
        }
    } else if (rotaciones < 0) {
        for (int i = rotaciones; i < 0; ++i) {
            cabeza = cabeza->anterior; // Rotar a la izquierda (negativo)
        }
    }

    std::cout << "ROTANDO ROTOR " << (N > 0 ? "+" : "") << N
    << ". (Nueva cabeza: '" << cabeza->caracter << "')\n";
}

NodoRotor* RotorDeMapeo::buscarNodo(char in) {
    if (cabeza == nullptr) return nullptr;

    NodoRotor* actual = cabeza;
    // Búsqueda en la lista circular (máximo 27 nodos)
    for (int i = 0; i < 27; ++i) {
        if (actual->caracter == in) {
            return actual;
        }
        actual = actual->siguiente;
        // La lista circular debe garantizar que se visite 'cabeza' solo una vez más
        if (actual == cabeza) break;
    }
    return nullptr;
}

char RotorDeMapeo::getMapeo(char in) {
    if (cabeza == nullptr) return '?';

    // 1. Encontrar la posición del carácter de entrada 'in' con respecto a la posición ' ' (Espacio)
    // El carácter ' ' está en la posición 0 del rotor original, 'A' en 1, etc.
    // Esto requiere encontrar la 'posición absoluta' de 'in'

    NodoRotor* temp = cabeza;
    int pos_in_actual = 0;

    // Contar distancia desde la cabeza ACTUAL hasta 'in'
    while (temp->caracter != in) {
        temp = temp->siguiente;
        pos_in_actual++;
        if (pos_in_actual > 27) return '?'; // Carácter no encontrado o bucle
    }

    // El mapeo se basa en la posición relativa:
    // La posición '0' del rotor (el caracter mapeado) es siempre la 'cabeza'.
    // Si el fragmento es 'in', buscamos el caracter que está a 'pos_in_actual' posiciones
    // después de la cabeza actual. ESTA LÓGICA ES LA INVERSA A LA QUE SE NECESITA.

    // Lógica Correcta (César Inverso por Rotación del Rotor):
    // El decodificado es el carácter que está a 'pos_in_actual' posiciones después de la cabeza
    // Si L,A entra, y la cabeza está en C (+2), 'A' está a 2 posiciones de la 'A' original.
    // El carácter decodificado es el que está a 2 posiciones *después* de la cabeza actual.

    // En la estructura actual del rotor (Space, A, B, C...)
    // La 'A' original está en la posición 1. La 'H' en la 8.

    // Buscamos la posición absoluta de 'in' con respecto al inicio *original* (' ')
    NodoRotor* inicio_original = nullptr;
    temp = cabeza;
    for (int i = 0; i < 27; ++i) {
        if (temp->caracter == ' ') {
            inicio_original = temp;
            break;
        }
        temp = temp->siguiente;
    }
    if (inicio_original == nullptr) return '?';

    // 1. Contar distancia desde el inicio original (' ') hasta 'in'
    int pos_in_original = 0;
    temp = inicio_original;
    while (temp->caracter != in) {
        temp = temp->siguiente;
        pos_in_original++;
        if (pos_in_original > 27) return '?';
    }

    // 2. El carácter decodificado es el que está a 'pos_in_original' posiciones después de la cabeza ACTUAL.
    temp = cabeza;
    for (int i = 0; i < pos_in_original; ++i) {
        temp = temp->siguiente;
    }

    return temp->caracter;
}
