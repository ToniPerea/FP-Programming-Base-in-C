#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double TARIFA_BASE = 150.0, PRECIO_KILOMETRO_ADICIONAL = 0.10;
   const int DISTANCIA_MAXIMA = 300;
   int km = 0;
   double precio = 0.0;
   double diferencia_de_km = 0.0;

   cout << "Introduzca los kilometros del recorrido: " ;
   cin >> km ;

   diferencia_de_km = km - DISTANCIA_MAXIMA;

   if(km > DISTANCIA_MAXIMA){
      precio = TARIFA_BASE + (diferencia_de_km * PRECIO_KILOMETRO_ADICIONAL);
   }else{
      precio = TARIFA_BASE;
   }

   cout << "\nEl coste del viaje es: " << precio << "\n\n" ;
}
