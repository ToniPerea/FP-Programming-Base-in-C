#include <cmath>
#include <iostream>
using namespace std;

int main(){
   bool es_feliz = false;
   int numero_candidato, suma_de_cifras = 0, cifra, i, maximo_iteraciones;

   cout << "Introduzca el número a valorar: ";
   cin >> numero_candidato;
   cout << "\nIntroduzca el grado de numero feliz: ";
   cin >> maximo_iteraciones;

   for (i = 0 ; i < maximo_iteraciones && !es_feliz ; i++){
      while (numero_candidato != 0){
         cifra = numero_candidato % 10;
         numero_candidato = numero_candidato / 10;
         suma_de_cifras = suma_de_cifras + pow(cifra , 2);
      }

      if (suma_de_cifras == 1)
         es_feliz = true;

      numero_candidato = suma_de_cifras;
      suma_de_cifras = 0;
   }

   if (es_feliz)
      cout << "\n\nEs feliz para cualquier grado mayor o igual que: " << i << "\n\n";
   else
      cout << "\n\nNo es feliz para cualquier grado menor o igual que: " << i << "\n\n";

}
