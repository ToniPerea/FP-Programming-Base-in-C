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
         centimos = centimos - 100;
         euros = euros + 1;
      }
   }
   int Euros(){
      return euros;
   }
   int Centimos(){
      return centimos;
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

   euros = cartera_1.Euros() + cartera_2.Euros();
   centimos = cartera_1.Centimos() + cartera_2.Centimos();

   Dinero cartera_3(euros, centimos);

   cout << "Hay un total de " << cartera_3.Euros() << "," << cartera_3.Centimos() << " eur" << "\n\n";
}
