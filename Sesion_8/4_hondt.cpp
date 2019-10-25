#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int ESPACIO = 50;
   int partidos, escanios, i, maximo_hondt = 0, cociente_hondt, partido_maximo;
   int votos_por_partido[ESPACIO], escanios_por_partido[ESPACIO] = {0};

   cout << "Introduzca el número de escaños y partidos: ";
   cin >> escanios >> partidos;

   for (i = 0 ; i < partidos ; i++){
      cout << "\nIntroduzca los votos del partido número " << i+1 << " : ";
      cin >> votos_por_partido[i];
   }

   for (i = 0 ; i < escanios ; i++){
      for (int j = 0 ; j < partidos ; j++){
         cociente_hondt = votos_por_partido[j] / (escanios_por_partido[j] + 1);
         if (cociente_hondt > maximo_hondt){
            maximo_hondt = cociente_hondt;
            partido_maximo = j;
         }
      }
   escanios_por_partido[partido_maximo] = escanios_por_partido[partido_maximo] + 1;
   maximo_hondt = 0;
   cociente_hondt = 0;

   }

   for (i = 0 ; i < partidos ; i++){
      cout << escanios_por_partido[i] << "\t\t";
   }

}
