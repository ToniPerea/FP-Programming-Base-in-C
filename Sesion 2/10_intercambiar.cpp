#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int caja_derecha, caja_izquierda, auxiliar = 0;

   cout << "Introduzca el valor de la caja derecha: " ;
   cin >> caja_derecha ;
   cout << "Introduzca el valor de la caja izquierda: " ;
   cin >> caja_izquierda ;

   auxiliar = caja_izquierda;
   caja_izquierda = caja_derecha;
   caja_derecha = auxiliar;

   cout << "\nCaja derecha: " << caja_derecha << "\n\n" ;
   cout << "\nCaja izquierda: " << caja_izquierda << "\n\n" ;
}
