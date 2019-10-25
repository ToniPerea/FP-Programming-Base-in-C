#include <cmath>
#include <iostream>

using namespace std;

int main(){
   int horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2, segundos_total;

   cout << "\nIntroduce hora, minuto y segundo del instante inicial: ";
   cin >> horas_1 >> minutos_1 >> segundos_1;
   cout << "\nAhora, introduce hora, minuto y segundo del instante final: ";
   cin >> horas_2 >> minutos_2 >> segundos_2;

   segundos_total = (horas_2 - horas_1) * 3600 + (minutos_2 - minutos_1) * 60 + (segundos_2 - segundos_1);

   if (segundos_total > 0)
      cout << "\nEl primero es anterior al segundo.\n\n";
   else
      cout << "\nEl primero no es anterior.\n\n";
}
