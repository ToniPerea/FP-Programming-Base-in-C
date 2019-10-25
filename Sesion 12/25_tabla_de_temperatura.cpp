#include <iostream>
#include <cmath>

using namespace std;

const int CIUDADES = 10, HORAS = 24;

struct Registro{
   double temperatura;
   int ciudad, hora;
};

class TablaTemperaturas{
private:
   double matriz[CIUDADES][HORAS];

   bool EnRango(int fila, int columna){
      return (fila >= 0 && fila < CIUDADES) && (columna >= 0 && columna < HORAS);
   }

public:
   double Valor(int ciudad_dada, int hora_dada){
      if (EnRango(ciudad_dada, hora_dada))
         return matriz[ciudad_dada][hora_dada];
   }

   void Modifica(int ciudad_dada, int hora_dada, double temperatura_dada){
      if (EnRango(ciudad_dada, hora_dada))
         matriz[ciudad_dada][hora_dada] = temperatura_dada;
   }

   int Minimo(int ciudad_dada){
      double min;
      int indice_min;

      if (ciudad_dada >= 0 && ciudad_dada < CIUDADES){
         min = matriz[ciudad_dada][0];
         indice_min = 0;

         for (int i = 1 ; i < HORAS ; i++){
            if (matriz[ciudad_dada][i] < min){
               min = matriz[ciudad_dada][i];
               indice_min = i;
            }
         }
      }
      return indice_min;
   }

   Registro Maximo_de_los_minimos(){
      double minimos[CIUDADES], maximo;
      int indice_max = 0, i;
      Registro registro_de_vuelta;

      for (i = 0 ; i < CIUDADES ; i++){
         minimos[i] = matriz[i][Minimo(i)];
      }
      maximo = minimos[0];

      for (i = 1 ; i < CIUDADES ; i++){
         if (minimos[i] > maximo){
            maximo = minimos[i];
            indice_max = i;
         }
      }

      registro_de_vuelta.temperatura = minimos[indice_max];
      registro_de_vuelta.ciudad = indice_max;
      registro_de_vuelta.hora = Minimo(indice_max);

      return registro_de_vuelta;
   }
};

int main(){
   TablaTemperaturas tabla_de_ejemplo;
   int fila, columna, ciudad, hora;
   double temperatura;
   Registro registro_a_mostrar;

   for (fila = 0 ; fila < CIUDADES ; fila++){
      for (columna = 0 ; columna < HORAS ; columna++){
         cin >> temperatura;
         tabla_de_ejemplo.Modifica(fila, columna, temperatura);
      }
   }

   registro_a_mostrar = tabla_de_ejemplo.Maximo_de_los_minimos();

   temperatura = registro_a_mostrar.temperatura;
   hora = registro_a_mostrar.hora;
   ciudad = registro_a_mostrar.ciudad;

   cout << "\nTemperatura = " << temperatura << "\nCiudad = " << ciudad << "\nHora = " << hora << "\n\n";
}
