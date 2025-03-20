#ifndef CLASS_H
#define CLASS_H
#include <string>

class Coche {
private: // 3. Private member fields
    std::string marca;
    std::string modelo;
    int velocidad;

    // 4. Private member function
    void acelerar();

public:
    // 1. Custom constructor
    Coche(const std::string &marca, const std::string &modelo, int velocidad);

    // 2. Default (parameterless) constructor (i.e. constructor overloading)
    Coche();

    // 5. Public getter function
    std::string getMarca() const;
    std::string getModelo() const;
    int getVelocidad() const;

    // 6. Public setter function
    void setMarca(const std::string &marca);
    void setModelo(const std::string &modelo);
    void setVelocidad(int velocidad);

};

#endif
