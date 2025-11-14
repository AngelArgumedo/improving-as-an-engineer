
#include <iostream>
using namespace std;
#include <vector>

int main() {
  cout<< "Hello world" << endl;
  int edad = 20;
  float precio = 9.99;
  double pi = 3.14159;
  char letra = 'a';
  bool activo = true;
  string nombre = "angel";

  // operadores basicos
  // aritmeticos +, -, *, /, %
  // comparacion ==,!=, <, >, <=, >=
  // Logicos &&
  // asignacion =, +=, -=, *=, /=
  
  // estructuras de control
  // if
  if (int x = 1 > 10){
    cout  << "mayor que dies";
  } else {
    cout << "menor que dies";
  }

  // for
  for (int i = 0; i<5; i++){
    cout << i << endl;
  }

  // while
  int i = 0;
  while(i<5){
    cout << i << endl;
    i++;
  }

  // arreglos y vectores
  // arreglo estatico
  int numerosEstaticos[4]= {2,7,11,15};

  // vector dinamico
  vector<int> numerosVector = {2,7,11,15};

  // entrada y salida
  int edadPersona;
  cout << "Ingrese su edad: ";
  cin >> edadPersona;
  cout << "Tu edad es: " << edadPersona << endl;
  // cout -> salida a consola
  // cin -> entrada por teclado
  // << -> envia datos de salida
  // >> -> toma datos de entrada


  return 0;
}
