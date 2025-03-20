 /*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox() {
  // Instancia usando el constructor personalizado
  Coche miCoche {"Toyota", "Corolla", 20};

  std::cout << "Marca: " << miCoche.getMarca() << std::endl;
  std::cout << "Modelo: " << miCoche.getModelo() << std::endl;
  std::cout << "Velocidad: " << miCoche.getVelocidad() << std::endl;
}
