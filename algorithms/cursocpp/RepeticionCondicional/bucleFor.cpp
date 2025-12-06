
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

  // ejercicio de intentos adivinar un numero con 3 intentos.
  const int MAX_INTENTOS = 3;

  int numeroAdivinar = 5;
  int numeroUsuario;
  bool gane = false;

  for (int i; i <= MAX_INTENTOS; i++) {
    std::cout << "Ingresa un numero: ";
    std::cin >> numeroUsuario;

    if (numeroUsuario == numeroAdivinar) {
      std::cout << "ganaste!!" << std::endl;
      gane = true;
      break;
    }
  }

  if (gane) {
    std::cout << "ganaste!!" << std::endl;
  } else {
    std::cout << "Perdiste!" << std::endl;
  }

  return 0;
};
