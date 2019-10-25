#include <iostream>
#include <cmath>
using namespace std;

int main(){
   const char TERMINADOR = '#';
   char a_borrar, vector[2500000];
   int posicion_lectura = 0, posicion_escritura = 0, util_vector, i;

   while (vector[i - 1] != '#'){
      vector[i] = cin.get();
      i++;
   }

   cin >> a_borrar;

   util_vector = i - 1;

   while (posicion_lectura < util_vector){
      if (vector [posicion_lectura] == a_borrar)
         posicion_lectura++;
      else{
         vector[posicion_escritura] = vector[posicion_lectura];
         posicion_lectura++;
         posicion_escritura++;
      }
   }

   util_vector = posicion_escritura;

   for (i = 0 ; i < util_vector ; i++ )
      cout << vector[i];



}
