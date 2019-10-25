#include <iostream>
#include <cmath>

using namespace std;

class Instante {
private:
   int horas, minutos, segundos;
   bool Rango_Correcto(double dato, int min, int max){
      return dato <= max && dato >= min;
   }
public:
   Instante(int horas_dadas, int minutos_dados, int segundos_dados)
      :horas(horas_dadas), minutos(minutos_dados), segundos(segundos_dados)
      {
         if (!Rango_Correcto(horas, 0, 23))
            horas = -1;
         if (!Rango_Correcto(minutos, 0, 59))
            minutos = -1;
         if (!Rango_Correcto(segundos, 0, 59))
            segundos = -1;
      }
   Instante(int segundos_dados)
      {
         int horas_calculadas, minutos_calculados, segundos_calculados;

         horas = segundos_dados / 3600;
         segundos_dados = segundos_dados %  3600;
         minutos = segundos_dados / 60;
         segundos_dados = segundos_dados % 60;
         segundos = segundos_dados;
      }
   int Segundos_Transcurridos(){
      return horas*3600 + minutos*60 + segundos;
   }
   int Minutos_Transcurridos(){
      return horas*60 + minutos + segundos/60;
   }
   string Instante_a_partir_de_segundos(int segundos_dados){
      int horas_de_vuelta, minutos_de_vuelta, segundos_de_vuelta;
      string cadena_de_vuelta;

      horas_de_vuelta = segundos_dados / 3600;
      segundos_dados = segundos_dados %  3600;
      minutos_de_vuelta = segundos_dados / 60;
      segundos_dados = segundos_dados % 60;
      segundos_de_vuelta = segundos_dados;

      cadena_de_vuelta = to_string(horas_de_vuelta) + " h " + to_string(minutos_de_vuelta) + "' " + to_string(segundos_de_vuelta) + "'' ";

      return cadena_de_vuelta;
   }

   int GetHoras(){
      return horas;
   }
   int GetMinutos(){
      return minutos;
   }
   int GetSegundos(){
      return segundos;
   }
};

int main(){
   int segundos, minutos, horas, diferencia_segundos;

   cout << "Introduzca el primer instante: ";
   cin >> horas >> minutos >> segundos;

   Instante instante_inicial(horas, minutos, segundos);

   cout << "Introduzca el segundo instante: ";
   cin >> horas >> minutos >> segundos;

   Instante instante_final(horas, minutos, segundos);

   diferencia_segundos = ( instante_final.GetHoras() - instante_inicial.GetHoras() ) * 3600 +
   ( instante_final.GetMinutos() - instante_inicial.GetMinutos() ) * 60 +
   instante_final.GetSegundos() - instante_inicial.GetSegundos();

   Instante instante_diferencia(diferencia_segundos);

   cout << "Diferencia: " << instante_diferencia.Instante_a_partir_de_segundos(instante_diferencia.Segundos_Transcurridos()) << "\n\n";
   cout << "Total segundos diferencia: " << instante_diferencia.Segundos_Transcurridos() << "\n\n";
   cout << "Total minutos diferencia: " << instante_diferencia.Minutos_Transcurridos() << "\n\n";
}
