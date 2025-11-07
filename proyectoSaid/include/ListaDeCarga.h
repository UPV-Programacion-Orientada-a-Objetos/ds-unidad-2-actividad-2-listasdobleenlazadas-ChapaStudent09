// ListaDeCarga.h
#ifndef LISTADECARGA_H
#define LISTADECARGA_H

#include "Primitivas.h"
#include <iostream>

/**
 * @brief Implementa la Lista Doblemente Enlazada Manual para ensamblar el mensaje.
 * * Almacena los caracteres decodificados en el orden de llegada.
 */
class ListaDeCarga {
private:
    NodoCarga* cabeza; ///< Puntero al primer nodo de la lista.
    NodoCarga* cola;   ///< Puntero al último nodo de la lista.

public:
    ListaDeCarga();
    ~ListaDeCarga();

    /**
     * @brief Inserta un nuevo carácter decodificado al final de la lista.
     * * Se usa para mantener el orden cronológico del mensaje ensamblado.
     * @param dato El carácter decodificado a almacenar.
     */
    void insertarAlFinal(char dato);

    /**
     * @brief Imprime el mensaje ensamblado completo en una sola línea.
     */
    void imprimirMensaje();
};

#endif // LISTADECARGA_H
