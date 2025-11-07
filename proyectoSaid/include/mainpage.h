/**
 * @mainpage Decodificador de Protocolo PRT-7
 * * @section intro Introducción
 * * Este proyecto implementa un decodificador de protocolo industrial PRT-7, 
 * un mecanismo de ofuscación de telemetría que utiliza un protocolo de 
 * ensamblaje de mensajes. El sistema fue construido en C++ con estricta 
 * prohibición del uso de la Standard Template Library (STL).
 * * @section arquitectura Arquitectura y Componentes
 * * El decodificador se basa en principios de Programación Orientada a Objetos 
 * (POO) avanzada, utilizando punteros manuales para la gestión de memoria 
 * y las estructuras de datos.
 * * Los componentes clave son:
 * * - **TramaBase / TramaLoad / TramaMap:** Jerarquía polimórfica para procesar instrucciones.
 * - **RotorDeMapeo:** Implementado como una Lista Circular Doblemente Enlazada que actúa como un disco de cifrado rotatorio.
 * - **ListaDeCarga:** Implementado como una Lista Doblemente Enlazada para ensamblar el mensaje final decodificado.
 * * @section ejecucion Ejecución (Simulada)
 * * El programa espera tramas de texto desde la entrada estándar (simulando un puerto serial):
 * 1.  **Tramas LOAD (L,X):** Almacenan un fragmento de dato 'X' después de ser mapeado por el Rotor.
 * 2.  **Tramas MAP (M,N):** Rotan el Rotor 'N' posiciones, cambiando el estado de decodificación.
 * * **Requisitos de Compilación:** CMake y Doxygen.
 */

