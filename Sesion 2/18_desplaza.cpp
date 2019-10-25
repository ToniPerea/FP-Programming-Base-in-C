#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int minimo, maximo, desplazamiento, numero_a_desplazar, numero_movido ;

   cout << "Introduzca el minimo y el maximo del intervalo: ";
   cin >> minimo;
   cin >> maximo;

   cout << "Introduzca que numero quiere desplazar dentro del intervalo: ";
   cin >> numero_a_desplazar;

   cout << "Introduzca cuantas posciones quieres desplazar el numero: ";
   cin >> desplazamiento;

   numero_movido =  (maximo + desplazamiento) - numero_a_desplazar;
   numero_movido = numero_movido + minimo;

   cout << "\nEl numero ya movido es " << numero_movido << "\n\n";


}
