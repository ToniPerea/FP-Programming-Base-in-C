#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 1000100, TERMINADOR = -1;
   int topk[ESPACIO], k, i = 0, izda, a_ordenar, util_topk, maximo, posicion_maximo, intercambiar;

   cout << "Introduzca el vector principal: ";
   while (topk[i-1] != TERMINADOR){
      cin >> topk[i];
      i++;
   }

   util_topk = i - 1;

   cout << "Introduzca el número k: ";
   cin >> k;

   for (izda = 0 ; izda < k ; izda++){
      maximo = topk[izda];
      for (i = izda + 1 ; i < util_topk ; i++){
         if (topk[i] > maximo){
            maximo = topk[i];
            posicion_maximo = i;
         }
      }
      intercambiar = topk[izda];
      topk[izda] = maximo;
      topk[posicion_maximo] = intercambiar;

   }

   util_topk = k;
   for (i = 0 ; i < util_topk ; i++)
      cout << topk[i] << "\t";

}
