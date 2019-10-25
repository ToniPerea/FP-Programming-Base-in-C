#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const char RADAR_FIJO = 'F';
   const char RADAR_MOVIL = 'M';
   const int MARGEN_DE_ERROR_FIJO = 5;
   const int MARGEN_DE_ERROR_MOVIL = 7;
   char letra_a_introducir;
   int velocidad = 0;
   double velocidad_imputada = 0;

   cout << "Introduzca el tipo de radar usado (fijo-> F y movil-> M): ";
   cin >> letra_a_introducir;
   cout << "\nIntroduzca la velocidad captada por el radar: ";
   cin >> velocidad;

   if(letra_a_introducir == RADAR_FIJO){
      if(velocidad <= 100){
         velocidad_imputada = velocidad - MARGEN_DE_ERROR_FIJO;
      }else{
         const double RESULTADO_PORCENTAJE_FIJO = velocidad * 0.05;
         velocidad_imputada = velocidad - RESULTADO_PORCENTAJE_FIJO;
      }
      cout << "\nLa velocidad imputada por el radar fijo es " << velocidad_imputada << "\n\n";
   }else if(letra_a_introducir == RADAR_MOVIL){
      if(velocidad <= 100){
         velocidad_imputada = velocidad - MARGEN_DE_ERROR_MOVIL;
      }else{
         const double RESULTADO_PORCENTAJE_MOVIl = velocidad * 0.07;
         velocidad_imputada = velocidad - RESULTADO_PORCENTAJE_MOVIl;
      }
      cout << "\nLa velocidad imputada por el radar movil es " << velocidad_imputada << "\n\n";
   }else{
      cout << "\n\nNo ha introducido un radar. Saliendo del programa...." << "\n";
   }
}
