#include <iostream>
#include <string>

int main() {

  char letra1, letra2;

  std::cin >> letra1;
  std::cin >> letra2;

  std::cout << letra1 << std::endl << letra2 << std::endl;

  // escape
  std::string frase = "Hola \"Fulano\", \nes un placer conocerte.";

  std::cout << frase << std::endl;

  std::cout << "Lista de precios: \n \t harina 20 \n \t azucar 13" << std::endl;
  return 0;
}
