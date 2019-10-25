#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int posiciones_de_rotacion = 0;
   const int INTERVALO = 'Z' - 'A' + 1, minimo = 'A', maximo = 'Z';
   char letra, letra_decodificada;

   cout << "Introduzca las posiciones de rotacion: ";
   cin >> posiciones_de_rotacion;
   cout << "Introduzca la letra a codificar: ";
   cin >> letra;

   letra = (letra%minimo + posiciones_de_rotacion)%INTERVALO;
   letra = letra + minimo;

   letra_decodificada = (letra%minimo + (INTERVALO - posiciones_de_rotacion))% INTERVALO;
   letra_decodificada = letra_decodificada + minimo;

   cout << "\nLa letra ya codificada es " << letra << " y sin decodificar seria " << letra_decodificada << "\n\n";
}
