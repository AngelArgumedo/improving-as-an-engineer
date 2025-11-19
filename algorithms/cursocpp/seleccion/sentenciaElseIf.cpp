
#include <iostream>
using namespace std;

int main() {
  int edad;

  cout << "Este programa valida diferentes rangos de edad" << endl;

  cout << "Ingresa tu edad porfavor: ";
  cin >> edad;

  if (edad < 40) {
    cout << "Eres joven." << endl;
  } else if (edad == 40) {
    cout << "Estas en la mitad de la vida" << endl;
  } else {
    cout << "eres viejo" << endl;
  };

  cout << "Gracias por ingresar tu edad" << endl;
};
