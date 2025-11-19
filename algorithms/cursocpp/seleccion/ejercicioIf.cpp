
#include <iostream>
using namespace std;

int main() {

  char seleccion;
  int base;
  int altura;

  const float pi = 3.14159;
  float radio;

  cout << "Este Programa te permite seleccionar si deseas calcular el area y "
          "perimetro de un circulo o de un rectangulo"
       << endl;

  cout << "Entonces que vas a calcular? \n"
          "\t Circulo (0) o Rectangulo(1): ";
  cin >> seleccion;

  // realizamos operaciones con assci;
  if (seleccion - '0') { // '1' - '0' == 49 - 48 = 1; por lo tanto es true
    // Rectangulo
    cout << "Usted selecciono Rectangulo" << endl;

    cout << "Por favor digite la Altura del rectangulo: ";
    cin >> altura;

    cout << "Ahora digite la base del rectangulo: ";
    cin >> base;

    int area = base * altura;
    int perimetro = 2 * (base + altura);

    cout << "El area del rectangulo es: " << area << endl;
    cout << "El perimetro del rectangulo es: " << perimetro << endl;

  } else { // '0' - '0' == 48 - 48 = 0; por lo tanto es False;
    // circulo
    cout << "Usted selecciono circulo" << endl;

    cout << "Porfavor digite el Radio del circulo: ";
    cin >> radio;

    float area = pi * (radio * radio);
    float perimetro = 2 * (pi * radio);

    cout << "El area del circulo es: " << area << endl;
    cout << "El perimetro del circulo es: " << perimetro << endl;
  }
}
