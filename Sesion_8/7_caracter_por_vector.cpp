//El resultado del problema no es correcto del todo

#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 50;
   int i = 0, utilizados_primer_vector, utilizados_sustituyente, utilizados_sustituido, k = 0;
   char v[ESPACIO], sustituyente[ESPACIO], sustituido[ESPACIO];
   char a_borrar;

   do {
      cin >> v[i];
      i++;
   } while(v[i-1] != '#');

   utilizados_primer_vector = i - 1;

   i = 0;

   do {
      cin >> sustituyente[i];
      i++;
   } while(sustituyente[i-1] != '#');

   utilizados_sustituyente =  i - 1;

   utilizados_sustituido = utilizados_primer_vector;

   cout << "Caracter a sustituir: ";
   cin >> a_borrar;

   for (i = 0 ; i < utilizados_primer_vector ; i++){
      if (v[i] == a_borrar)
         utilizados_sustituido = utilizados_sustituido + utilizados_sustituyente - 1;
   }

   for (i = 0 ; i < utilizados_sustituido ; i++){
      if (v[k] == a_borrar){
         for (int j = 0 ; j < utilizados_sustituyente ; j++){
            sustituido[i] = sustituyente[j];
            i++;
         }

         k = i - utilizados_sustituyente;
         i = i - 1;
      }else
         sustituido[i] = v[k];
      k++;
   }

   for (i = 0 ; i < utilizados_sustituido ; i++){
      cout << sustituido[i];
   }


}
