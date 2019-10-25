#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double TARIFA_BASE = 150.0;
   int km = 0;
   double precio = 0.0;

   cout << "Introduzca los kilometros del recorrido: " ;
   cin >> km ;

   precio = TARIFA_BASE + (km * 0.10);

   cout << "\nEl coste del viaje es: " << precio << "\n\n" ;
}
