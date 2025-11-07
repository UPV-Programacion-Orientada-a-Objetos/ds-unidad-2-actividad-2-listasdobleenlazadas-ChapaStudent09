// TramaBase.cpp
/**
 * @file TramaBase.cpp
 * @brief Implementación de la lógica de procesamiento polimórfico de las tramas.
 */
#include "TramaBase.h"

// Implementación de TramaLoad::procesar
void TramaLoad::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    std::cout << "\n--- Trama recibida: [L," << datoFragmento << "] -> Procesando TramaLoad...\n";

    // 1. Preguntar al rotor por el carácter decodificado (aplica el mapeo)
    char decodificado = rotor->getMapeo(datoFragmento);

    // 2. Insertar el resultado en la ListaDeCarga
    carga->insertarAlFinal(decodificado);
}

// Implementación de TramaMap::procesar
void TramaMap::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    std::cout << "\n--- Trama recibida: [M," << (rotacionN > 0 ? "+" : "") << rotacionN << "] -> Procesando TramaMap...\n";

    // 1. Simplemente llama al método rotar del RotorDeMapeo
    rotor->rotar(rotacionN);
}
