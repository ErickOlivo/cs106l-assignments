#include "class.h"
#include <string>
#include <iostream>


// Default constructor
Coche::Coche() {
    marca = "Desconocida";
    modelo = "Desconocido";
    velocidad = 0;  // Inicializamos la velocidad
}

// Custom constructor (los parámetros ahora se reciben como const reference)
Coche::Coche(const std::string &marca, const std::string &modelo, int velocidad) {
    this->marca = marca;
    this->modelo = modelo;
    this->velocidad = velocidad;
}

// Getter functions
std::string Coche::getMarca() const {
    return marca;
}

std::string Coche::getModelo() const {
    return modelo;
}

int Coche::getVelocidad() const {
    return velocidad;
}

// Setter functions (ahora usando const reference)
void Coche::setMarca(const std::string &marca) {
    this->marca = marca;
}

void Coche::setModelo(const std::string &modelo) {
    this->modelo = modelo;
}

void Coche::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

// Private member function (nota: el nombre debe coincidir exactamente con el declarado en el header)
void Coche::acelerar() {
    velocidad += 10;
}
