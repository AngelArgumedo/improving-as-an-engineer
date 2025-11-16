
#include <iostream>

int main() {
  int division = 10 / 3;

  std::cout << division;

  // ahora supongamos el tema de hay 10 habitaciones y 3 personas
  int habitaciones;
  int personas;

  std::cout
      << "Este programa te permite decidir cuantas personas entran a un hotel."
      << std::endl;

  std::cout << "Escribe cuantas habitaciones hay en el hotel: ";
  std::cin >> habitaciones;

  std::cout << "Escribe cuantas personas van a entrar al hotel: ";
  std::cin >> personas;

  int calculo = habitaciones / personas;
  int resto = habitaciones % personas;

  std::cout << "Entran " << calculo << " se quedan afuera " << resto
            << std::endl;

  return 0;
}
