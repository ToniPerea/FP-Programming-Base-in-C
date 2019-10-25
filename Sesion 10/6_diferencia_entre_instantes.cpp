#include <cmath>
#include <iostream>
using namespace std;

int LeeIntRango(int min_dado, int max_dado){
   int numero_de_vuelta;

   do{
      cin >> numero_de_vuelta;
   }while(!(numero_de_vuelta >= min_dado && numero_de_vuelta <= max_dado));

   return numero_de_vuelta;
}

int segundos(int momento_1, int momento_2, int segundos_por_unidad_dada){
   return (momento_2 - momento_1) * segundos_por_unidad_dada;
}

int main(){
   int horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2, segundos_total;
   const int SEGUNDOS_EN_HORA = 3600, SEGUNDOS_EN_MINUTO = 60;
   cout << "Introduzca el primer instante: ";
   horas_1 = LeeIntRango(0,23);
   minutos_1 = LeeIntRango(0,59);
   segundos_1 = LeeIntRango(0,59);
   cout << "Introduzca el segundo instante: ";
   horas_2 = LeeIntRango(0,23);
   minutos_2 = LeeIntRango(0,59);
   segundos_2 = LeeIntRango(0,59);

   segundos_total = segundos(horas_1, horas_2, SEGUNDOS_EN_HORA) + segundos(minutos_1, minutos_2, SEGUNDOS_EN_MINUTO) + segundos(segundos_1, segundos_2, 1);

   cout << "\nEntre los dos instantes hay un número de: " << segundos_total << " segundos.\n\n";
}
