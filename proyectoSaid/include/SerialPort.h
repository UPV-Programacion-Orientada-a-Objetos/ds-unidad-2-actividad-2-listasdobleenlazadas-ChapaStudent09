// SerialPort.h
#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <iostream>

class SerialPort {
public:
    // En un proyecto real, se usaría una librería (Serialib/Boost Asio) o APIs nativas (Win32/POSIX)
    bool open(const char* portName, int baudRate);
    int readLine(char* buffer, int maxLen);
    void close();
    
    // En este caso de estudio, la lectura será SIMULADA en main.cpp,
    // pero se mantiene la interfaz para la futura integración.
    
    SerialPort() {}
    ~SerialPort() {}
};

#endif // SERIALPORT_H
