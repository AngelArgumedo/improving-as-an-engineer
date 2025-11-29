
#include <iostream>
#include <string>

int main() {

  std::cout << "Este programa te permite jugar Tic tac de una forma basica."
            << std::endl;

  std::cout << "Como jugar? \n"
               "se jugaran por turnos para dos jugadores \n"
               "se puede colocar unicamente \"X\" o \"O\" \n"
               "Se debe ingresar las coordenadas de la siguiente forma B2X"
            << std::endl;

  char A1 = '#', A2 = '#', A3 = '#';
  char B1 = '#', B2 = '#', B3 = '#';
  char C1 = '#', C2 = '#', C3 = '#';

  std::string eleccionJ1;
  std::string eleccionJ2;

  std::cout << A1 << " " << A2 << " " << A3 << std::endl;
  std::cout << B1 << " " << B2 << " " << B3 << std::endl;
  std::cout << C1 << " " << C2 << " " << C3 << std::endl;

  std::cout << "jugador 1 \n"
               "Marca con X al final:";
  std::cin >> eleccionJ1;

  // operador ternario
  if (eleccionJ1.length() != 3) {
    std::cout << "Formato incorrecto";
    return 0;
  }

  if (eleccionJ1 != "") {

    char fila = eleccionJ1[0];
    char columna = eleccionJ1[1];
    char letra = eleccionJ1[2];

    if (fila != 'A' || fila != 'B' || fila != 'C') {
      if (columna != '1' || columna != '2' || columna != '3') {
        std::cout << "la columna y la fila son validas" << std::endl;
        if (letra == 'X') {
          // aqui ya viene la logica para asignar en la casilla correspondiente.
          std::string entrada = "";
          entrada += fila;
          entrada += columna;

          if (entrada == "A1") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "A2") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "A3") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "B1") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "B2") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "B3") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "C1") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "C2") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
          if (entrada == "C3") {
            A1 = letra;
            std::cout << A1 << " " << A2 << " " << A3 << std::endl;
            std::cout << B1 << " " << B2 << " " << B3 << std::endl;
            std::cout << C1 << " " << C2 << " " << C3 << std::endl;
          }
        } else {
          std::cout << "no escribiste tu correspondiente X" << std::endl;
        }
      } else {
        std::cout << "No escribiste una columna valida." << std::endl;
      }
    } else {
      std::cout << "no escribiste una fila valida." << std::endl;
    }
  } else {
    std::cout << "no seleccionaste nada" << std::endl;
  }

  return 0;
}
