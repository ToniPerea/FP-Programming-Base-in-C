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
      if (centimos > 100){
         euros = euros + centimos / 100;
         centimos = centimos % 100;
      }
   }
   Dinero()
      :euros(0), centimos(0)
   {}

   int Euros(){
      return euros;
   }

   int Centimos(){
      return centimos;
   }

   Dinero Suma(Dinero cartera_dada){
      int euros_totales, centimos_totales;

      euros_totales = cartera_dada.Euros() + euros;
      centimos_totales = cartera_dada.Centimos() + centimos;

      if (centimos_totales >= 100){
         euros_totales = euros_totales + centimos_totales / 100;
         centimos_totales = centimos_totales % 100;
      }

      Dinero cartera_de_vuelta(euros_totales, centimos_totales);

      return cartera_de_vuelta;
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

   Dinero cartera_3(cartera_1.Suma(cartera_2));

   cout << "Hay un total de " << cartera_3.Euros() << "," << cartera_3.Centimos() << " Euros." << "\n\n";
}
