cmake_minimum_required(VERSION 3.10)
project(PRT7_Decodificador LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definir las carpetas para las fuentes
set(SOURCE_DIR src)
set(INCLUDE_DIR include)

# 1. Definir la lista de ARCHIVOS FUENTE (.cpp) - Usando rutas relativas a la carpeta 'src'
set(SOURCE_FILES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/RotorDeMapeo.cpp
    ${SOURCE_DIR}/ListaDeCarga.cpp
    ${SOURCE_DIR}/TramaBase.cpp
    # El archivo SerialPort.cpp se omite, ya que no existe en tu proyecto.
)

# 2. Crear el ejecutable
add_executable(prt7_decoder ${SOURCE_FILES})

# 3. Indicarle a CMake dónde buscar los archivos .h (cabeceras)
# Esto es crucial para que los archivos .cpp puedan usar #include "MiClase.h"
target_include_directories(prt7_decoder PUBLIC
    ${INCLUDE_DIR}
)
