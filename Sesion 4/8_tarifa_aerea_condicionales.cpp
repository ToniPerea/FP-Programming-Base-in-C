#include <cmath>
#include <iostream>

using namespace std;

int main(){
   const double PRECIO_KILOMETRO_ADICIONAL = 0.1, DOS_POR_CIENTO = 0.98, TRES_POR_CIENTO = 0.97, CUATRO_POR_CIENTO = 0.96;
   double distancia, distancia_adicional = 0, precio = 150, puntos_tarjeta;

   cout << "\n¿Cuántos kilometros quiere viajar?: ";
   cin >> distancia;
   cout << "\n¿Cuántos puntos tiene en su tarjeta de cliente?: ";
   cin >> puntos_tarjeta;

   if (distancia > 300){
      distancia_adicional = distancia - 300;
   }

   precio = precio + PRECIO_KILOMETRO_ADICIONAL*distancia_adicional;

   if (distancia > 700){
      precio = precio * DOS_POR_CIENTO;
   }

   if (puntos_tarjeta > 200){
      precio = precio * CUATRO_POR_CIENTO;

   }else if{ (puntos_tarjeta > 100)
      precio = precio * TRES_POR_CIENTO;
   }

   cout << "\nEl precio a pagar es de: " << precio << " euros.\n\n";
}
