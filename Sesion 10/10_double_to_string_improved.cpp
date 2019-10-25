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


string DoubleToString(double numero_dado, int precision_dada){
   string cadena_a_devolver = "";
   int entero_limpio;
   double computos;
   char caracter;

   numero_dado = redondeo(numero_dado, precision_dada);

   computos = numero_dado * PotenciaEntera(10, precision_dada);

   for (int i = precision_dada ; i >= 0 ; i--){
      computos = computos / PotenciaEntera(10, i);
      entero_limpio = computos;
      computos = computos - entero_limpio;
      computos = computos * PotenciaEntera(10, i);
      caracter = entero_limpio + 48;
      if(i == precision_dada - 1)
         cadena_a_devolver.push_back('.');

      cadena_a_devolver.push_back(caracter);
   }

   return cadena_a_devolver;


}

int main(){
   double numero;
   int precision;

   cout << "Introduzca el número y precisión: ";
   cin >> numero >> precision;

   cout << "\nLa cadena es: " << DoubleToString(numero, precision) << "\n\n";
}
