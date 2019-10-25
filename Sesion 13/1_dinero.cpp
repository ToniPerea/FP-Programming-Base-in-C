#include <cmath>
#include <iostream>

using namespace std;

class Dinero {
private:
   int euros, centimos;

public:
   Dinero(int euros_dados, int centimos_dados)
      :euros(euros_dados), centimos(centimos_dados)
   {
      if (centimos >= 100){
         euros = euros + centimos / 100;
         centimos = centimos % 100;
      }
   }

   int Euros(){
      return euros;
   }

   int Centimos(){
      return centimos;
   }

   double Suma_otra_cartera(Dinero cartera_dada){
      int euros_totales, centimos_totales;

      euros_totales = cartera_dada.Euros() + euros;
      centimos_totales = cartera_dada.Centimos() + centimos;

      if (centimos_totales > 100){
         euros_totales = euros_totales + centimos_totales / 100;
         centimos_totales = centimos_totales % 100;
      }

      return euros_totales + centimos_totales / 100.0;
   }

};

int main(){
   int euros, centimos;

   cout << "Introduzca el dinero de la primera cartera: ";
   cin >> euros >> centimos;

   Dinero cartera_1(euros, centimos);

   cout << "Introduzca el dinero de la segunda cartera: ";
   cin >> euros >> centimos;

   Dinero cartera_2(euros, centimos);

   cout << "Hay un total de " << cartera_1.Suma_otra_cartera(cartera_2) << " Euros." << "\n\n";
}
