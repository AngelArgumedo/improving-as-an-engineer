
#include <iostream>
using namespace std;

int main() {
  cout << "Anidacion del ciclo for" << endl;

  int lado;

  cout << "Lado ";
  cin >> lado;

  for (int i = 1; i <= lado; i++) {
    for (int j = 1; j <= lado; j++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
