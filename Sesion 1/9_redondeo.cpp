#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double numero = 0;
   int precision = 0;

   cout << "Introduzca el numero a redondear: " ;
   cin >> numero ;
   cout << "Introduzca la precision con la que quiere redondear: " ;
   cin >> precision ;

   numero = numero * pow(10,precision);  //esto se penaliza hay que ponerlo en constantes.
   numero = round(numero);
   numero = numero / pow(10,precision);

   cout << "\nEl resultado redondeado es " << numero << "\n\n" ;


}
