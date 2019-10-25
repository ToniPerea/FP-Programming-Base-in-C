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

string EliminaUltimos(string cadena_dada, char a_borrar_dado){
   while (cadena_dada[cadena_dada.size() - 1] == a_borrar_dado){
      cadena_dada.pop_back();
   }

   return cadena_dada;
}

string DoubleToString(double numero_dado, int precision_dada){
   string cadena_a_devolver;

   numero_dado = redondeo(numero_dado, precision_dada);
   cadena_a_devolver = to_string(numero_dado);

   return EliminaUltimos(cadena_a_devolver, '0');

}

int main(){
   double numero;
   int precision;

   cout << "Introduzca el número y precisión: ";
   cin >> numero >> precision;

   cout << "\nLa cadena es: " << DoubleToString(numero, precision) << "\n\n";
}
