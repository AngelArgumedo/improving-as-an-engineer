
#include <iostream>
using namespace std;

int main() {

  /*
  los tipos de datos primitivos son aquellos que representan un valor simple e
  inmutable.
  */

  // tipos numericos

  // el tipo char
  /*
   * es un tipo de dato un tanto peculiar: ocupa 1 byte (8 bits) de memoria RAM,
   * por lo que puede representar 256 valores diferentes, y sirve tanto para
   * numeros como para caracteres. puede contener valores positivos entre 0 y
   * 255. puede contener valores entre -127 y 127. puede contener caracteres
   * entre comillas simples (por ejemplo 'A') representando simbolos, siempre
   * que esten dentro de la tabla ASCII.
   */

  char numero = 127;
  std::cout << numero << std::endl;

  // Diferentes tipos primitivos
  char letra = 'A';
  int edad = 25;
  float precio = 9.99;
  double pi = 3.14159265359;
  long long grande = 9223372036854775807;

  cout << "=== TAMAÑOS EN MEMORIA ===" << endl;
  cout << "char:      " << sizeof(letra) << " bytes" << endl;
  cout << "int:       " << sizeof(edad) << " bytes" << endl;
  cout << "float:     " << sizeof(precio) << " bytes" << endl;
  cout << "double:    " << sizeof(pi) << " bytes" << endl;
  cout << "long long: " << sizeof(grande) << " bytes" << endl;

  cout << "\n=== DIRECCIONES EN RAM ===" << endl;
  cout << "Dirección de letra: " << (void *)&letra << endl;
  cout << "Dirección de edad:  " << (void *)&edad << endl;
  cout << "Dirección de precio:" << (void *)&precio << endl;

  cout << "\n=== VALORES ===" << endl;
  cout << "letra (char):    " << letra << " = " << (int)letra << " en ASCII"
       << endl;
  cout << "edad (int):      " << edad << endl;
  cout << "precio (float):  " << precio << endl;

  return 0;
}
