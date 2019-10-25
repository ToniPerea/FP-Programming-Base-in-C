#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int posiciones_de_rotacion = 0;
   const int minimo = 'A', maximo = 'Z', INTERVALO = 'Z' - 'A' + 1;
   char letra, letra_decodificada;
   bool sobrepasa_el_maximo, sobrepasa_el_minimo;

   cout << "Introduzca las posiciones de rotacion: ";
   cin >> posiciones_de_rotacion;
   cout << "Introduzca la letra a codificar: ";
   cin >> letra;

   sobrepasa_el_maximo = letra + posiciones_de_rotacion > maximo;

   if (sobrepasa_el_maximo)
      letra = letra + posiciones_de_rotacion - INTERVALO;
   else
      letra = letra + posiciones_de_rotacion;

   sobrepasa_el_minimo = letra - posiciones_de_rotacion < minimo;

   if (sobrepasa_el_minimo)
      letra_decodificada = letra - posiciones_de_rotacion + INTERVALO;
   else
      letra_decodificada = letra - posiciones_de_rotacion;

   cout << "\nLa letra ya codificada es " << letra << " y sin decodificar seria " << letra_decodificada << "\n\n";
}
