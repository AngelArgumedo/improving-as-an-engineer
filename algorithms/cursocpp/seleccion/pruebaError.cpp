#include <iostream>
using namespace std;

int main() {
  string corto = "AB";     // 2 caracteres
  string correcto = "ABC"; // 3 caracteres

  cout << "String corto: '" << corto << "'" << endl;
  cout << "Tamaño: " << corto.length() << endl;
  cout << "corto[0] = " << corto[0] << endl;
  cout << "corto[1] = " << corto[1] << endl;
  cout << "corto[2] = " << corto[2] << " (¿qué es esto?)" << endl;

  cout << "\nString correcto: '" << correcto << "'" << endl;
  cout << "Tamaño: " << correcto.length() << endl;
  cout << "correcto[2] = " << correcto[2] << endl;

  return 0;
}
