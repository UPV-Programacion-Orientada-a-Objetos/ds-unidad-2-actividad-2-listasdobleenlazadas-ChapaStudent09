// main.cpp
/**
 * @file main.cpp
 * @brief Implementación del Decodificador PRT-7 para Ciberseguridad Industrial.
 * * Este programa lee un flujo de tramas (LOAD y MAP) desde la entrada estándar (simulando
 * el puerto serial) y ensambla un mensaje oculto utilizando POO polimórfica y estructuras
 * de datos manuales (Lista Doble y Lista Circular).
 * @author Gemini (AI Assistant)
 */

#include "TramaBase.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

#include <iostream>
#include <cstring> // Para funciones C-style: strtok, strncpy
#include <cstdlib> // Para funciones C-style: atoi

using namespace std;

/**
 * @brief Parsea una línea de texto de la trama y crea el objeto TramaBase* polimórfico.
 * @param linea La línea de texto leída (ej. "L,H" o "M,-2").
 * @return TramaBase* Un puntero a TramaLoad o TramaMap, o nullptr si el parsing falla.
 */
TramaBase* parsearYCrearTrama(char* linea) {
    // Nota: Se usa una copia interna de la línea si strtok va a modificar el buffer original,
    // pero en este caso, el buffer de entrada es temporal.

    // Separa el tipo de trama (L o M) del valor (char o int)
    char* tipo = strtok(linea, ",");
    char* valor = strtok(nullptr, ",");

    if (tipo == nullptr || valor == nullptr) {
        cerr << "\nERROR: Trama mal formada o incompleta. Ignorando.\n";
        return nullptr;
    }

    TramaBase* nuevaTrama = nullptr;

    // Trama LOAD
    if (tipo[0] == 'L' && tipo[1] == '\0') {
        if (strlen(valor) == 1) {
            nuevaTrama = new TramaLoad(valor[0]);
        } else if (strcmp(valor, "Space") == 0) {
            nuevaTrama = new TramaLoad(' ');
        } else {
            cerr << "\nERROR: Trama L mal formada (valor incorrecto): " << valor << ". Ignorando.\n";
        }
    }
    // Trama MAP
    else if (tipo[0] == 'M' && tipo[1] == '\0') {
        int N = atoi(valor); // Uso de C-style para convertir string a int
        nuevaTrama = new TramaMap(N);
    }
    // Trama Desconocida
    else {
        cerr << "\nERROR: Tipo de trama desconocido: " << tipo << ". Ignorando.\n";
    }

    return nuevaTrama;
}


/**
 * @brief Función principal del decodificador PRT-7.
 * @return int Código de salida del programa.
 */
int main() {
    // 1. Inicialización de Estructuras
    ListaDeCarga listaCarga;
    RotorDeMapeo rotorMapeo;
    rotorMapeo.inicializar();

    cout << "Iniciando Decodificador PRT-7. Conectando a fuente de datos (Arduino/stdin)...\n";
    cout << "Rotor de Mapeo inicializado.\n";
    cout << "Conexión establecida. ESPERANDO ENTRADA DE TRAMAS REALES:\n";

    // 2. Bucle de Procesamiento: Lectura desde STDIN
    // NOTA: Se ha eliminado la simulación interna de datos. El programa se bloqueará esperando
    // entrada del teclado o una redirección de archivo/pipe, simulando la lectura serial.
    const int MAX_LEN = 20;
    char buffer[MAX_LEN];

    // El bucle lee línea por línea hasta que el usuario envíe EOF (Ctrl+D) o la lectura falle.
    while (cin.getline(buffer, MAX_LEN)) {

        if (cin.fail() || buffer[0] == '\0') {
            break;
        }

        // Se usa una copia para el parsing si el buffer necesita ser reutilizado
        char lineaParaParseo[MAX_LEN];
        strncpy(lineaParaParseo, buffer, MAX_LEN - 1);
        lineaParaParseo[MAX_LEN - 1] = '\0';

        TramaBase* trama = parsearYCrearTrama(lineaParaParseo);

        if (trama != nullptr) {
            // Ejecución polimórfica: TramaBase::procesar() llama a la implementación correcta
            trama->procesar(&listaCarga, &rotorMapeo);

            // 3. Limpieza de Memoria: delete en el puntero de la clase base llama al destructor virtual
            delete trama;
        }
    }

    cout << "\n---\nFlujo de datos terminado.\n";

    // 4. Resultado Final
    listaCarga.imprimirMensaje();

    // 5. Liberación de memoria (realizada automáticamente por los destructores de las clases)
    cout << "---\nLiberando memoria... Sistema apagado.\n";

    return 0;
}
