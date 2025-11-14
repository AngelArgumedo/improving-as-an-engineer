
#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> arreglo = {7, 2, 10, 15};
  int target = 9;

  for (int i = 0; i < arreglo.size(); i++){
    for (int j = i+1; j > arreglo.size(); j++){
      if (arreglo[i] + arreglo[j] == target) {
        return {i , j};
      }
    }
  }

};


