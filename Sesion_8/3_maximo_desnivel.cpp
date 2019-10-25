#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 50;
   int utilizados, i, diferencia, maximo = 0, desnivel_acumulado = 0;
   int alturas[ESPACIO];

   do{
      cout << "Introduzca el número de alturas que va a introducir: ";
      cin >> utilizados;
   } while (utilizados < 2);
   for (i = 0 ; i < utilizados ; i++){
      cin >> alturas[i];
   }

   for (i = 0 ; i < utilizados - 1 ; i++){
      diferencia = alturas[i+1] - alturas[i];
      if (abs(diferencia) > maximo)
         maximo = abs(diferencia);
   }

   for (i = 0 ; i < utilizados - 1 ; i++){
      diferencia = alturas[i+1] - alturas[i];
      if (diferencia > 0)
         desnivel_acumulado = desnivel_acumulado + diferencia;
   }

   cout << "\n\nEl máximo desnivel es: " << maximo << " y el desnivel acumulado es: " << desnivel_acumulado << "\n\n";




}
