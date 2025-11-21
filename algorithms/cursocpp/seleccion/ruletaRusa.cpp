
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

    int moneda = rand() % 2;
    while (vidaJugador - '0') {
      switch () {}
    }

  } else if (aceptaJugar == 'N') {
    cout << "Tremenda Flor regresa cuando tengas valor." << endl;
  } else {
    cout << "Acaso eres tonto? si sigues asi te daran un balaso por lento \n"
            "Es una simple eleccion de Y/N"
         << endl;
  }
}
