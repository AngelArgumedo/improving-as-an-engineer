
#include <iostream>

int main() {
  int largo;
  int ancho;

  std::cout << "Este programa te permite calcular el Area y el perimetro de un "
               "cuadrado"
            << std::endl;

  std::cout << "porfavor ingrese el largo de un cuadrado: " << std::endl;
  std::cin >> largo;

  std::cout << "porfavor ingrese el ancho del cuadrado: " << std::endl;
  std::cin >> ancho;

  // calculamos el perimetro
  int perimetro = (largo * 2) + (ancho * 2);

  // calculamos el area
  int area = (largo * ancho);

  std::cout << "El Area el cuadrado es de: " << area << std::endl;

  std::cout << "El Area el cuadrado es de: " << perimetro << std::endl;

  return 0;
}
