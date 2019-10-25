#include <cmath>
#include <iostream>
using namespace std;

int main(){
   int tope, contador = 0;
   double pi, sumatoria = 0, numerador, denominador;

   do {
      cout << "\nIntroduce el tope de la serie: ";
      cin >> tope;
   } while (tope < 1 || tope > 100000);

   while (contador <= tope) {
      numerador = pow (-1 , contador);
      denominador = 2*contador + 1;
      sumatoria = sumatoria + numerador/denominador;

      contador++;
   }

   pi = sumatoria * 4;

   cout.precision(15);
   cout << "El valor aproximado de pi es: " << pi << "\n\n";

}
