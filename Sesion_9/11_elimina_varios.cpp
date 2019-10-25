#include <iostream>
#include <cmath>
using namespace std;

int main(){
   int a_borrar[100], vector[100], posicion_lectura = 0, posicion_escritura = 0,
   util_vector, util_borrar, i, izda, a_desplazar;

   cout << "Introduzca el número de componentes del vector: ";
   cin >> util_vector;
   cout << "Ahora el vector: ";

   for (i = 0 ; i < util_vector ; i++)
      cin >> vector[i];

   cout << "Introduzca el número de componentes que quiere borrar: ";
   cin >> util_borrar;
   cout << "Ahora los números a borrar: ";

   for (i = 0 ; i < util_borrar ; i++)
      cin >> a_borrar[i];

   for (izda = 1 ; izda < util_borrar ; izda++){
      a_desplazar = a_borrar[izda];

      for (i = izda ; i > 0 && a_desplazar < a_borrar[i-1] ; i--)
         a_borrar[i] = a_borrar[i-1];

      a_borrar[i] = a_desplazar;
   }

   i = 0;
   while (posicion_lectura < util_vector){
      if (posicion_lectura == a_borrar[i]){
         posicion_lectura++;
         i++;
      }
      else{
         vector[posicion_escritura] = vector[posicion_lectura];
         posicion_lectura++;
         posicion_escritura++;
      }
   }
   util_vector = util_vector - util_borrar;


   for (i = 0 ; i < util_vector ; i++ )
      cout << vector[i];



}
