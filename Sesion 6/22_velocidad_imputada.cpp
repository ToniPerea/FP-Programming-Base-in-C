#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const char RADAR_FIJO = 'F';
   const double MARGEN_ERROR_ALTA_VELOCIDAD_FIJO = 0.95, MARGEN_ERROR_ALTA_VELOCIDAD_MOVIL = 0.93;
   const int LIMITE_DE_BAJA_VELOCIDAD = 100, MARGEN_ERROR_BAJA_VELOCIDAD_MOVIL = 7, MARGEN_ERROR_BAJA_VELOCIDAD_FIJO = 5;
   char tipo_de_radar;
   double velocidad_inicial, error_a_alta_velocidad, velocidad_imputada, maxima_velocidad_imputada=0;
   int error_a_baja_velocidad;
   bool baja_velocidad;
   string matricula, matricula_maxima_velocidad;
   const string TERMINADOR = "#";

   cout << "\nIntroduzca la matrícula del vehículo: ";
   cin >> matricula;

   while (matricula != TERMINADOR){
      cout << "\n¿El radar es móvil o fijo?: ";
      cin >> tipo_de_radar;
      cout << "\n¿Velocidad del vehículo?: ";
      cin >> velocidad_inicial;

      if (tipo_de_radar == RADAR_FIJO){
         error_a_baja_velocidad = MARGEN_ERROR_BAJA_VELOCIDAD_FIJO;
         error_a_alta_velocidad = MARGEN_ERROR_ALTA_VELOCIDAD_FIJO;
      }
      else{
         error_a_baja_velocidad = MARGEN_ERROR_BAJA_VELOCIDAD_MOVIL;
         error_a_alta_velocidad = MARGEN_ERROR_ALTA_VELOCIDAD_MOVIL;
      }

      baja_velocidad = velocidad_inicial <= LIMITE_DE_BAJA_VELOCIDAD;

      if (baja_velocidad)
         velocidad_imputada = velocidad_inicial - error_a_baja_velocidad;
      else
         velocidad_imputada = velocidad_inicial * error_a_alta_velocidad;

      if (velocidad_imputada > maxima_velocidad_imputada){
         maxima_velocidad_imputada = velocidad_imputada;
         matricula_maxima_velocidad = matricula;
      }

      cout << "\nIntroduzca la matrícula del vehículo: ";
      cin >> matricula;
   }

   cout << "\n\nLa maxima velocidad imputada es: " << maxima_velocidad_imputada << " km/h, del vehiculo con matrícula " << matricula_maxima_velocidad << "\n\n" ;

}
