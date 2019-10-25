#include <cmath>
#include <iostream>
using namespace std;

int LeeIntMayorIgualQue(int numero_dado){
   int numero_de_vuelta;

   do{
      cin >> numero_de_vuelta;
   }while (numero_de_vuelta < numero_dado);

   return numero_de_vuelta;
}

int LeeIntRango(int min_dado, int max_dado){
   int numero_de_vuelta;

   do{
      cin >> numero_de_vuelta;
   }while(!(numero_de_vuelta >= min_dado && numero_de_vuelta <= max_dado));

   return numero_de_vuelta;
}

int main(){
   int min, max, suma = 0, dato;

   cout << "Introduzca min y máximo";
   cin >> min;
   max = LeeIntMayorIgualQue(min);

   for (int i = 0 ; i < 3 ; i++){
      cout << "Introduzca un sumando: ";
      dato = LeeIntRango(min,max);
      suma = suma + dato;
   }


   cout << "\nLa suma es: " << suma << "\n\n";
}
