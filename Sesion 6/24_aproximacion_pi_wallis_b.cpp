#include <iostream>
#include <cmath>
using namespace std;

int main(){
   int tope, numerador = 0, denominador = 1, contador = 1, numerador_auxiliar;
   double pi, fraccion = 1;
   bool cambio_denominador;

   do {
      cout << "\nIntroduce el tope de la serie: ";
      cin >> tope;
   } while (tope < 1 || tope > 100000);

   while (contador <= tope){
      numerador_auxiliar = numerador;
      numerador = denominador + 1;
      denominador = numerador_auxiliar + 1;

      fraccion = fraccion * numerador/denominador;

      contador++;
   }

   pi = fraccion * 2;

   cout.precision(15);
   cout << "El valor aproximado de pi es: " << pi << "\n\n";
}
