
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  std::srand(time(0));

  std::cout << "generar numeros aleatorios con srand" << std::endl;

  std::cout << "adivina un numero entre 1 y 10, tienes 3 intentos."
            << std::endl;

  int numeroAdivinar =
      std::rand() % 10 + 1; // para generar numeros entre 1 y 10;
  const int MAX_INTENTOS = 3;

  int numeroUsuario;
  bool gane = false;

  for (int i; i <= MAX_INTENTOS; i++) {
    std::cout << "Ingresa un numero: ";
    std::cin >> numeroUsuario;

    if (numeroUsuario == numeroAdivinar) {
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
}
