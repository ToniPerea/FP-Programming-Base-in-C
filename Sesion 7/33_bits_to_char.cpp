#include <cmath>
#include <iostream>
using namespace std;

int main(){

   int digito_binario, numero_decimal = 0, contador = 0, letras = 0, otros_caracteres = 0;
   char caracter;
   double porcentaje_otros = 0, porcentaje_letras = 0, total_caracteres;
   bool es_letra;
   const int cifras_por_bloque = 8;

   cout << "Introduzca un digito: \n";
   cin >> digito_binario;

   while (digito_binario >= 0) {
      if (digito_binario == 1 || digito_binario == 0) {
         numero_decimal = numero_decimal + digito_binario * pow(2 , 7 - contador);
         contador++;
      }

      if (contador == cifras_por_bloque) {
         caracter = numero_decimal;
         cout << "\n\nEl caracter introducido es: " << caracter << "\n\n";

         es_letra = (numero_decimal >= 65 && numero_decimal <= 90) || (numero_decimal >= 97 && numero_decimal <= 122);
         numero_decimal = 0;
         contador = 0;

         if (es_letra)
            letras++;
         else
            otros_caracteres++;
      }

      cout << "Introduzca un digito: \n";
      cin >> digito_binario;
   }

   total_caracteres = otros_caracteres + letras;
   porcentaje_letras = letras / total_caracteres * 100;
   porcentaje_otros = 100 - porcentaje_letras;

   cout << "\n\nLetras: " << porcentaje_letras << "%\nOtros: " << porcentaje_otros << "%\n\n";
}
