#include "class.h"
#include <string>

int main void() {
    // Default constructor
    Coche::Coche() {
        marca = "Desconocida";
        modelo = "Desconocido";
    }

    // Custom consturctor
    Coche::Coche(std::string marca, std::string modelo) {
        this->marca = marca;
        this->modelo = modelo;
    }

    // Getter function
    std::string Coche::getMarca() const {
        return marca;
    }

    std::string Coche::getModelo() const {
        return modelo;
    }

    int getVelocidad() const {
        return velocidad;
    }

    // Setter function
    void setMarca(std::string marca) {
        marca = marca;
    }
    void setModelo(std::string modelo) {
        modelo = modelo;
    }
    void setVelocidad(int velocidad) {
        velocidad = velocidad;
    }

    // Private member function (Solo puede ser llamada desde dentro de la clase)
    void Coche::Acelerar() {
        velocidad += 10;
    }

    return 0;
}
