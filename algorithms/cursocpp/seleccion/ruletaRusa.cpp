
#include <cstdlib>
#include <iostream>
using namespace std;
#include <ctime>

int main() {
  srand(time(0));
  char aceptaJugar;
  char vidaJugador = '1';
  char vidaMaquina = '1';
  int moneda;
  cout << "vamos a jugar a la ruleta rusa" << endl;

  cout << "aceptas? Y/N";
  cin >> aceptaJugar;

  if (aceptaJugar == 'Y') {
    cout << "Veo que te gustan los riesgos, JUGEMOS!!!" << endl;
    cout << "Juguemos con esta Revolver con 6 balas" << endl;

    cout << "Vamos a tirar una moneda." << endl;
    int bala = 1 + rand() % 6;

    cout << "Tu seras Cara y yo Cruz" << endl;
    // 1: Cara / 2: Cruz
    while (vidaJugador - '0' && vidaMaquina - '0') {

      switch (bala) {
      case 1:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }
        break;

      case 2:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }
        break;

      case 3:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }

        break;

      case 4:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }

        break;

      case 5:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }

        break;

      case 6:
        moneda = 1 + rand() % 2;
        cout << "Tirando moneda...";
        if (moneda == 1) {
          cout << "Salio Cara." << endl;
          cout << "Banggg!!! Estas muerto..." << endl;
          vidaJugador = '0';
        } else {
          cout << "Salio Cruz." << endl;
          cout << "Banggg!!! Haz ganado, la IA ha muerto." << endl;
          vidaMaquina = '0';
        }

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
