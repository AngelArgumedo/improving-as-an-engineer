
#include <iostream>

int main() {
  std::cout << "el bucle for" << std::endl;

  // vamos a preguntarle a un usuario cuantos alteriscos imprimir
  int repeticion;

  std::cout << "Cuantos alteriscos quieres iprimir?: ";
  std::cin >> repeticion;

  for (int i = 1; i <= repeticion; i++) {
    std::cout << "*";
  }

  std::cout << "" << std::endl;
  return 0;
};
