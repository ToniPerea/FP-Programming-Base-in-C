#include <iostream>

using namespace std;

int main(){
  const char TERMINADOR = '#';
  const int TAMANO = 100;
  char caracter, a_borrar;
  char v[TAMANO], nuevo[TAMANO];
  int v_util = 0, nuevo_util = 0;
  int v_contador = 0;

  cout << "Vector: ";
  cin >> caracter;

  while (caracter != TERMINADOR){
    v[v_util] = caracter;
    v_util++;
    cout << "Vector: ";
    cin >> caracter;
  }

  cout << "Vector nuevo: ";
  cin >> caracter;

  while (caracter != TERMINADOR){
    nuevo[nuevo_util] = caracter;
    nuevo_util++;
    cout << "Vector nueovo: ";
    cin >> caracter;
  }

  cout << "Caracter a borrar: "
  cin >> a_borrar;
}
