#include <cmath>
#include <iostream>

using namespace std;

string EliminaUltimos(string cadena_dada, char a_borrar_dado){
   while (cadena_dada[cadena_dada.size() - 1] == a_borrar_dado){
      cadena_dada.pop_back();
   }

   return cadena_dada;
}

int main(){
   string cadena;
   char caracter, a_borrar;
   const char TERMINADOR = '#';

   cout << "Introduzca caracteres: ";
   caracter = cin.get();

   while (caracter != TERMINADOR){
      cadena.push_back(caracter);
      caracter = cin.get();
   }

   cout << "Introduzca el caracter a borrar: ";
   cin >> a_borrar;

   cadena = EliminaUltimos(cadena, a_borrar);

   cout << "\nLa cadena es: " << cadena << "\n\n";
}
