#include <cmath>
#include <iostream>

using namespace std;

int main(){
   const double MINIMO_PUNTOS_DESCUENTO_BAJO = 100, MINIMO_PUNTOS_DESCUENTO_ALTO = 200,
   MINIMO_KM_DESCUENTO = 700, MAXIMO_NUM_PUNTOS = 400, PRECIO_KILOMETRO_ADICIONAL = 0.1,
   DOS_POR_CIENTO = 0.98, TRES_POR_CIENTO = 0.97, CUATRO_POR_CIENTO = 0.96,
   PRECIO_BASE = 150, DISTANCIA_BASE_MAXIMA = 300;
   double distancia, distancia_adicional = 0, precio = 150, puntos_tarjeta;
   char nuevo_billete;

   do{
      cout << "\nEsperando orden ('N' o '#'): ";
      cin >> nuevo_billete;
   }while (nuevo_billete != 'N' && nuevo_billete != '#');

   while (nuevo_billete != '#') {

      do{
         cout << "\n¿Cuántos kilometros quiere viajar?: ";
         cin >> distancia;
      }while (distancia < 0);

      do {
         cout << "\n¿Cuántos puntos tiene en su tarjeta de cliente?: ";
         cin >> puntos_tarjeta;
      } while(puntos_tarjeta < 0 || puntos_tarjeta > MAXIMO_NUM_PUNTOS);


      if (distancia > DISTANCIA_BASE_MAXIMA)
         distancia_adicional = distancia - DISTANCIA_BASE_MAXIMA;

      precio = precio + PRECIO_KILOMETRO_ADICIONAL * distancia_adicional;

      if (distancia > MINIMO_KM_DESCUENTO)
         precio = precio * DOS_POR_CIENTO;

      if (puntos_tarjeta > MINIMO_PUNTOS_DESCUENTO_ALTO)
         precio = precio * CUATRO_POR_CIENTO;

      else if (puntos_tarjeta > MINIMO_PUNTOS_DESCUENTO_BAJO)
         precio = precio * TRES_POR_CIENTO;

      cout << "\nEl precio a pagar es de: " << precio << " euros.\n\n";
      precio = PRECIO_BASE;

      do{
         cout << "\nEsperando orden ('N' o '#'): ";
         cin >> nuevo_billete;
      }while (nuevo_billete != 'N' && nuevo_billete != '#');
   }

}
