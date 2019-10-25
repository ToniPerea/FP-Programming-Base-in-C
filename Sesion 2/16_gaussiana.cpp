#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double PI = 3.14159;
   double esperanza, desviacion_tipica, abscisa, gaussiana = 0;

   cout << "Introduzca el valor de la esperanza y de la desviacion tipica: " ;
   cin >> esperanza ;
   cin >> desviacion_tipica ;
   cout << "Introduzca el valor de la abscisa x: " ;
   cin >> abscisa ;

   gaussiana = (1 / (desviacion_tipica * sqrt(2 * PI))) * exp(-0.5 * (((abscisa - esperanza) / desviacion_tipica) * ((abscisa - esperanza) / desviacion_tipica)));

   cout << "\nEl valor de la funcion gaussiana es " << gaussiana << "\n\n" ;
}
