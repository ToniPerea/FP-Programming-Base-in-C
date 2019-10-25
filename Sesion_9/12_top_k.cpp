#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 250000, TERMINADOR = -1;
   int v[ESPACIO], topk[ESPACIO], k, util_v, i, izda, a_ordenar, util_topk;

   cout << "Introduzca el vector principal: ";
   while (v[i-1] != TERMINADOR){
      cin >> v[i];
      i++;
   }

   util_v = i - 1;

   cout << "Introduzca el número k: ";
   cin >> k;

   for (i = 0 ; i < util_v ; i++)
      topk[i] = v[i];

   util_topk = util_v;

   for (izda = 1 ; izda < util_topk ; izda++){
      a_ordenar = topk[izda];

      for (i = izda ; i > 0 && a_ordenar > topk[i-1] ; i--)
         topk[i] = topk[i-1];

      topk[i] = a_ordenar;
   }

   for(i = k ; i < util_topk ; i++){
      for (int j = i ; j < util_topk ; j++)
         topk[j] = topk[j+1];
   }

   util_topk = k;
   for (i = 0 ; i < util_topk ; i++ )
      cout << topk[i] << "\t";



}
