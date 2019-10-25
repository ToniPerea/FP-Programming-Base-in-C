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

double redondeo(double numero_dado, int precision_dada){
   numero_dado = round(numero_dado * PotenciaEntera(10 , precision_dada));
   numero_dado = numero_dado / PotenciaEntera(10 , precision_dada);
}

int main(){
   double numero, indice_precision;

   cout << "\nIntroduce el número a redondear y la precisión de redondeo: ";
   cin >> numero >> indice_precision;

   numero = redondeo(numero, indice_precision);

   cout << "\nEl número redondeado es: " << numero << "\n\n";
}
