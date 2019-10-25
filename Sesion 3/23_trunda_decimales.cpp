#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double numero_decimal;
   int numeros_decimales_a_guardar,numero_decimal_en_entero;
   double mover_coma;

   cout << "Introduzca el numero decimal y la cantidad de numeros tras la coma ',' que quieres que se queden : ";
   cin >> numero_decimal;
   cin >> numeros_decimales_a_guardar;

   mover_coma = pow(10,numeros_decimales_a_guardar);
   numero_decimal_en_entero = numero_decimal * mover_coma;
   numero_decimal = numero_decimal_en_entero/mover_coma;

   cout << "\nEl numero es " << numero_decimal << "\n\n";
}
