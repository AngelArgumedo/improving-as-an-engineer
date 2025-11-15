#include <iostream>

int main() {

  // acomulacion
  int numero = 10;

  numero += 5;

  std::cout << "El valor es: " << numero << std::endl;

  // concatenacion
  std::string texto, entrada1, entrada2;

  std::cout << "ingresa una palabra: ";
  std::cin >> entrada1;

  std::cout << "Ingresa otra palabra: ";
  std::cin >> entrada2;

  texto = entrada1 + entrada2;

  std::cout << texto;
}
