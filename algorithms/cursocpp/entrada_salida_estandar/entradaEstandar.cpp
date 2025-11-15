
#include <iostream>
#include <string>

int main() {
  std::string nombre;
  int edad;

  int sumaEdad = 2;

  std::cout << "Ingresa tu nombre: ";
  std::cin >> nombre;

  std::cout << "Ahora ingresa tu edad: ";
  std::cin >> edad;

  std::cout << "Te llamas " << nombre << " y tienes una edad de: " << edad
            << std::endl;

  std::cout << "dentro de 2 years vas a tener: " << edad + sumaEdad
            << std::endl;

  return 0;
}
