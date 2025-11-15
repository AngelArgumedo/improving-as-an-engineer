
#include <cmath>
#include <iostream>

int main() {

  std::cout << "Este programa sirve para calcular el area y perimetro de un "
               "Triangulo teniendo los tres lados."
            << std::endl;

  float lado1, lado2, lado3;

  std::cout << "Porfavor ingrese el primer lado del triangulo: ";
  std::cin >> lado1;

  std::cout << "Por favor ingrese el segundo lado del triangulo: ";
  std::cin >> lado2;

  std::cout << "Por favor ingrese el ultimo lado del triangulo: ";
  std::cin >> lado3;

  // Vamos a usar la formula de Heron
  // La formula se basa en un proceso de dos pasos:

  // 1: calculamos el semiperimetro
  float semiperimetro = (lado1 + lado2 + lado3) / 2;

  // 2; Calcuamos el area

  // precalculo antes de la raiz cuadrada
  float precalculo = semiperimetro * (semiperimetro - lado1) *
                     (semiperimetro - lado2) * (semiperimetro - lado3);

  double area = std::sqrt(precalculo);

  // alculamos el perimetro
  float perimetro = lado1 + lado2 + lado3;

  std::cout << "El area del triangulo es de: " << area << std::endl;
  std::cout << "El perimetro del triangulo es de: " << perimetro << std::endl;

  return 0;
}
