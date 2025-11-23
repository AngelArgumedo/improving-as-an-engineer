
#include <iostream>

int main() {

  float radio;

  std::cout << "Radio = ";
  std::cin >> radio;

  std::cout << ((radio > 0) ? "el radio es mayor" : "el radio es menor")
            << std::endl;

  // el operador ternario tambien sirve para asignar valores a una variable
  return 0;
}
