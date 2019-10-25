#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double PI = 3.14159;
   double grado_longitud1, grado_longitud2, grado_latitud1, grado_latitud2 = 0;
   double radianes_longitud1, radianes_longitud2, radianes_latitud1, radianes_latitud2 = 0;
   double a = 0;

   cout << "Introduzca la latitud y la longitud del Punto 1: " ;
   cin >> grado_latitud1 ;
   cin >> grado_longitud1 ;
   cout << "Introduzca la latitud y la longitud del Punto 2: " ;
   cin >> grado_latitud2 ;
   cin >> grado_longitud2 ;

   radianes_longitud1 = grado_longitud1 * (PI / 180) ;
   radianes_latitud1 = grado_latitud1 * (PI / 180) ;
   radianes_longitud2 = grado_longitud2 * (PI / 180) ;
   radianes_latitud2 = grado_latitud2 * (PI / 180) ;
   a = pow(sin((1.0/2) * (radianes_latitud2 - radianes_latitud1)), 2) + cos(radianes_latitud1) * cos(radianes_latitud2) * pow(sin((1.0/2) * (radianes_longitud2 - radianes_longitud1)), 2);

   cout << "\nEl valor de a es " << a << "\n\n" ;
}
