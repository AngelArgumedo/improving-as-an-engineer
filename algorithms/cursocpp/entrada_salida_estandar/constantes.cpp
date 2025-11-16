#include <iostream>

int main() {

  // este programa sirve para calcular el perimetro y el area de un circulo
  const float PI = 3.14159;
  float radio;

  std::cout << "Ingrese el radio del circulo: " << std::endl;
  std::cin >> radio;

  float perimetro = radio * 2 * PI;
  float area = radio * radio * PI;

  std::cout << "El perimetro del circulo es: " << perimetro << std::endl;

  std::cout << "El area del circulo es: " << area << std::endl;

  return 0;
}
