#include <iostream>
#include <cmath>

int main() {
  std::cout << "=== VERIFICADOR DE LINEA RECTA ===" << std::endl;
  std::cout << "Dados tres puntos A, B, C, determina si forman una linea recta"
            << std::endl;
  std::cout << "y calcula la distancia total.\n" << std::endl;

  // Punto A
  double xA, yA;
  std::cout << "Ingrese las coordenadas del punto A (x y): ";
  std::cin >> xA >> yA;

  // Punto B
  double xB, yB;
  std::cout << "Ingrese las coordenadas del punto B (x y): ";
  std::cin >> xB >> yB;

  // Punto C
  double xC, yC;
  std::cout << "Ingrese las coordenadas del punto C (x y): ";
  std::cin >> xC >> yC;

  // TODO: Calcular si los tres puntos forman una línea recta
  // PISTA 1: Usa el concepto de PENDIENTE (slope)
  // PISTA 2: Si A-B-C están en línea recta, la pendiente de A-B debe ser
  //          IGUAL a la pendiente de B-C

  // TODO: Calcular la distancia total si están en línea recta
  // PISTA: Usa la fórmula de distancia euclidiana
  // distancia = sqrt((x2-x1)^2 + (y2-y1)^2)

  return 0;
}
