#include <cmath>
#include <iostream>

using namespace std;

class CoordenadasGPS{
private:
   double longitud, latitud, altura;
   bool Rango_Correcto(double dato, int min, int max){
      return dato <= max && dato >= min;
   }
   double Conversor_Grados_a_Radianes(double grados_dados){
      return 3.1416 * grados_dados / 180;
   }
public:
   void SetCoordenadas(double longitud_dada, double latitud_dada, double altura_dada){
      if (Rango_Correcto(longitud_dada,-90,90))
         longitud = Conversor_Grados_a_Radianes(longitud_dada);
      else
         longitud = -1;
      if (Rango_Correcto(latitud_dada,-180,180))
         latitud = Conversor_Grados_a_Radianes (latitud_dada);
      else
         latitud = -1;
      if (Rango_Correcto(altura_dada,-423,8848))
         altura = altura_dada;
      else
         altura = -1;
   }

   double Longitud(){
      return longitud;
   }
   double Latitud(){
      return latitud;
   }
   double Altura(){
      return altura;
   }
};

int main(){
   CoordenadasGPS posicion;
   double longitud, latitud, altura;

   cout << "Introduzca coordenadas";
   cin >> longitud >> latitud >> altura;

   posicion.SetCoordenadas(longitud, latitud, altura);

   cout << "\nLas coordendas son: "
   << posicion.Longitud() << " "
   << posicion.Latitud() << " "
   << posicion.Altura() << "\n\n";
}
