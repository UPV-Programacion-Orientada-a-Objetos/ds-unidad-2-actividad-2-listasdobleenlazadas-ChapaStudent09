// TramaBase.h
#ifndef TRAMABASE_H
#define TRAMABASE_H

#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

/**
 * @brief Clase Base Abstracta (ABC) para todas las tramas del protocolo PRT-7.
 * * Define la interfaz polimórfica que todas las tramas (Load y Map) deben implementar.
 */
class TramaBase {
public:
    /**
     * @brief Procesa la trama, modificando el estado de la ListaDeCarga y/o el RotorDeMapeo.
     * @param carga Puntero a la ListaDeCarga donde se ensambla el mensaje.
     * @param rotor Puntero al RotorDeMapeo (Lista Circular) que gestiona el cifrado.
     * @return void
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) = 0;

    /**
     * @brief Destructor virtual obligatorio para la correcta liberación de memoria polimórfica.
     */
    virtual ~TramaBase() {}
};

/**
 * @brief Representa una Trama de Carga (LOAD).
 * * Contiene un fragmento de dato (un carácter) que debe ser decodificado usando la rotación actual.
 */
class TramaLoad : public TramaBase {
private:
    char datoFragmento; ///< Carácter de dato a decodificar (ej. 'H' en L,H).

public:
    /**
     * @brief Constructor de TramaLoad.
     * @param dato El carácter a almacenar y decodificar.
     */
    TramaLoad(char dato) : datoFragmento(dato) {}
    ~TramaLoad() override {}

    void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};

/**
 * @brief Representa una Trama de Mapeo (MAP).
 * * Contiene una instrucción de rotación que modifica dinámicamente el estado del RotorDeMapeo.
 */
class TramaMap : public TramaBase {
private:
    int rotacionN; ///< Cantidad de posiciones a rotar el rotor (entero positivo o negativo).

public:
    /**
     * @brief Constructor de TramaMap.
     * @param N El valor entero para la rotación (ej. 2 o -3).
     */
    TramaMap(int N) : rotacionN(N) {}
    ~TramaMap() override {}

    void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};

#endif // TRAMABASE_H
