#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int descuento1, descuento2;
   double descuento_aplicado1, descuento_aplicado2;
   double precio1,  precio2;
   double billete = 0;

   cout << "Introduzca el precio del billete: " ;
   cin >> billete ;
   cout << "Introduzca los porcentajes de descuento: ";
   cin >> descuento1;
   cin >> descuento2;

   descuento_aplicado1 = billete * descuento1/100.0;
   precio1 = billete - descuento_aplicado1;
   descuento_aplicado2 = billete * descuento2/100.0;
   precio2 = billete - descuento_aplicado2;

   cout << "\nEl precio con un descuento de "<< descuento1 << "% es " << precio1 << " y con un descuento del " << descuento2 << "% es " << precio2 << "\n\n" ;

}
