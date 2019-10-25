#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double DESCUENTO1 = 0.04;
   const double DESCUENTO2 = 0.02;
   double descuento_aplicado1, descuento_aplicado2 = 0.0;
   int precio1,  precio2 = 0;
   int billete = 0;

   cout << "Introduzca el precio del billete: " ;
   cin >> billete ;

   descuento_aplicado1 = billete * DESCUENTO1;
   precio1 = billete - descuento_aplicado1;
   descuento_aplicado2= billete * DESCUENTO2;
   precio2 = billete - descuento_aplicado2;

   cout << "\nEl precio con un descuento de 4% es " << precio1 << " y con un descuento del 2% es " << precio2 << "\n\n" ;

}
