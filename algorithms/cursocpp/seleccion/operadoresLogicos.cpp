
#include <iostream>

int main() {

  bool valores[] = {false, true};

  std::cout << "Tabla de verdad para el operador AND" << std::endl;
  std::cout << "A\tB\tA && B\n";
  std::cout << "-------------------------\n";

  for (bool A : valores)
    for (bool B : valores)
      std::cout << A << "\t" << B << "\t" << ((A && B) ? "1" : "0")
                << std::endl;

  return 0;
}
