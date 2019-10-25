#include <cmath>
#include <iostream>

using namespace std;

int main(){
   int horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2;
   const string EL_PRIMERO_ANTERIOR = "\nEl primero es anterior.\n\n",
    EL_PRIMERO_NO_ES_ANTERIOR = "\nEl primero no es anterior.\n\n";

   cout << "\nIntroduce hora, minuto y segundo del instante inicial: ";
   cin >> horas_1 >> minutos_1 >> segundos_1;
   cout << "\nAhora, introduce hora, minuto y segundo del instante final: ";
   cin >> horas_2 >> minutos_2 >> segundos_2;

   if (horas_1 < horas_2)
      cout << EL_PRIMERO_ANTERIOR;
   else if (horas_1 > horas_2)
         cout << EL_PRIMERO_NO_ES_ANTERIOR;
      else if (minutos_1 < minutos_2)
            cout << EL_PRIMERO_ANTERIOR;
         else if (minutos_1 > minutos_2)
               cout << EL_PRIMERO_NO_ES_ANTERIOR;
            else if (segundos_1 < segundos_2)
                  cout << EL_PRIMERO_ANTERIOR;
               else
                  cout << EL_PRIMERO_NO_ES_ANTERIOR;

}
