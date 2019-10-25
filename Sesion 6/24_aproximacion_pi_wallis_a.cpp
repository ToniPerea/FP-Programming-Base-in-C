#include <iostream>
#include <cmath>
using namespace std;

int main(){
   int tope, numerador = 0, denominador = 1, contador = 1;
   double pi, fraccion = 1;
   bool cambio_denominador;

   do {
      cout << "\nIntroduce el tope de la serie: ";
      cin >> tope;
   } while (tope < 1 || tope > 100000);

   while (contador <= tope){
      cambio_denominador = contador % 2 == 0;

      if (cambio_denominador)
         denominador = denominador + 2;
      else
         numerador = numerador + 2;

      fraccion = fraccion * numerador/denominador;

      contador++;
   }

   pi = fraccion * 2;

   cout.precision(15);
   cout << "El valor aproximado de pi es: " << pi << "\n\n";
}
