
#include <iostream>
#include <string>

int main() {
  std::string nombre;
  float herederos;
  float fortuna;
  const float impuesto = 0.125;

  std::cout << "Ingresa tu nombre: ";
  std::cin >> nombre;

  std::cout << nombre
            << ", este es tu testamento. \n"
               "Solo hace falta que indiques la division de tu fortuna."
            << std::endl;

  std::cout << nombre << ", Indica la cantidad de herederos: ";
  std::cin >> herederos;

  std::cout << "Ahora indica tu fortuna total: ";
  std::cin >> fortuna;

  int divisionHerencia = fortuna / herederos;
  int caridad = static_cast<int>(fortuna) % static_cast<int>(herederos);

  std::cout << "El total de " << fortuna
            << " se distribuira como sigue: \n"
               "\t HEREDEROS: "
            << herederos
            << "\n"
               "\t C/U RECIBE: "
            << divisionHerencia
            << "\n"
               "\t A CARIDAD: "
            << caridad << std::endl;

  float calculoImpuesto = divisionHerencia * impuesto;
  float aCobrar = divisionHerencia - calculoImpuesto;
  float aCobrarCaridad = caridad - impuesto;

  std::cout
      << "Se ha de grabar todo con el impuesto a la ganancia del 12.5%: \n"
         "\t Por HERENCIA: "
      << divisionHerencia << "\t Impuesto: " << calculoImpuesto
      << "\t A cobrar: " << aCobrar << "\n"
      << "\t A caridad: " << caridad << "\t Impuesto: " << impuesto
      << "\t A Cobrar: " << aCobrarCaridad << std::endl;

  return 0;
}
