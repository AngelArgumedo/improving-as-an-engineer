
#include <iostream>
using namespace std;

int main() {

  cout << "sentencia switch" << endl;
  int eleccion;

  cout << "escriba un numero del 1 al 3";
  cin >> eleccion;

  switch (eleccion) {
  case 1:
    cout << "usted escribio el 1" << endl;
    break;

  case 2:
    cout << "usted escribio el 2" << endl;
    break;

  case 3:
    cout << "usted escribio el 3" << endl;
    break;

  default:
    cout << "solo puede escribir un numero del 1 al 3" << endl;
    break;
  }
}
