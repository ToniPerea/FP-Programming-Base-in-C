#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 50;
   int util_filas, util_columnas, MATRIZ[ESPACIO][ESPACIO], i, j, minimos[ESPACIO], maximo;

   cout << "Introduzca las filas y columnas utiles: ";
   cin >> util_filas >> util_columnas;

   cout << "Ahora la matris: ";
   for (i = 0 ; i < util_filas ; i++){
      for (j = 0 ; j < util_columnas ; j++)
         cin >> MATRIZ[i][j];
   }

   for (i = 0 ; i < util_filas ; i++){
      minimos[i] = MATRIZ[i][0];
      for(j = 0 ; j < util_columnas ; j++){
         if(MATRIZ[i][j] < minimos[i])
            minimos[i] = MATRIZ[i][j];
      }
   }
   maximo = minimos[0];
   for (i = 0 ; i < util_filas ; i++){
      if(minimos[i] > maximo)
         maximo = minimos[i];
   }

   cout << "El máximo de los mínimos es: " << maximo << "\n\n";

}
