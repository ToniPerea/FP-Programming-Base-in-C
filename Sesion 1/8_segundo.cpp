#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int hora1, hora2, minuto1, minuto2, segundo1, segundo2 = 0;
   int segundos_totales1, segundos_totales2, diferencia = 0;

   cout << "Introduzca la hora, minuto y segundo del primer instante(separados por espacios): " ;
   cin >> hora1 ;
   cin >> minuto1 ;
   cin >> segundo1 ;
   cout << "Introduzca la hora, minuto y segundo del segundo instante(separados por espacios): " ;
   cin >> hora2 ;
   cin >> minuto2 ;
   cin >> segundo2 ;

   segundos_totales1 = (hora1 * 3600) + (minuto1 * 60) + segundo1;
   segundos_totales2 = (hora2 * 3600) + (minuto2 * 60) + segundo2;
   diferencia = segundos_totales2 - segundos_totales1;

   cout << "\nEl numero de segundo que hay entre los dos instantes es " << diferencia << "\n\n" ;
}
