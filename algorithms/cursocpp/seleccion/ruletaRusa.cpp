
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

  char aceptaJugar;
  char vidaJugador = '1';

  cout << "vamos a jugar a la ruleta rusa" << endl;

  cout << "aceptas? Y/N";
  cin >> aceptaJugar;

  if (aceptaJugar == 'Y') {
    cout << "Veo que te gustan los riesgos, JUGEMOS!!!" << endl;
    cout << "Juguemos con esta Revolver con 6 balas" << endl;

    cout << "Vamos a tirar una moneda." << endl;
    int moneda = rand() % 2;
    int bala = rand() % 6;

    cout << "Tu seras Cara y yo Cruz" << endl;

    while (vidaJugador - '0') {
      switch (bala) {
      case 1:
        cout << "" << endl;
        break;

      case 2:
        cout << "" << endl;
        break;

      case 3:
        cout << "" << endl;
        break;

      case 4:
        cout << "" << endl;
        break;

      case 5:
        cout << "" << endl;
        break;

      case 6:
        cout << "" << endl;
        break;
      }
    };

  } else if (aceptaJugar == 'N') {
    cout << "Tremenda Flor regresa cuando tengas valor." << endl;
  } else {
    cout << "Acaso eres tonto? si sigues asi te daran un balaso por lento \n"
            "Es una simple eleccion de Y/N"
         << endl;
  };
};
