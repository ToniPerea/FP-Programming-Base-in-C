#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double x1, x2, y1, y2 = 0;
   double distancia_euclidea = 0;

   cout << "Introduzca las coordenadas x e y del Punto 1: " ;
   cin >> x1 ;
   cin >> y1 ;
   cout << "Introduzca las coordenadas x e y del Punto 2: " ;
   cin >> x2 ;
   cin >> y2 ;

   distancia_euclidea = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

   cout << "\nLa distancia euclidea de los dos Puntos es " << distancia_euclidea << "\n\n" ;
}
