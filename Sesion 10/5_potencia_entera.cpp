#include <cmath>
#include <iostream>
using namespace std;

int PotenciaEntera(double base_dada, int exponente_dado){
   int numero_de_vuelta = base_dada;

   if (exponente_dado == 0)
      numero_de_vuelta = 1;
   else {
      for (int i = 1 ; i < exponente_dado ; i++)
         numero_de_vuelta = numero_de_vuelta * base_dada;
   }

   return numero_de_vuelta;
}

int main(){
   int lado_1, lado_2;
   double hipotenusa;

   cout << "Introduzca los catetos: ";
   cin >> lado_1 >> lado_2;

   hipotenusa = PotenciaEntera (lado_1, 2) + PotenciaEntera (lado_2, 2);

   hipotenusa = sqrt (hipotenusa);

   cout << "\nLa hipotenusa es: " << hipotenusa << "\n\n";
}
