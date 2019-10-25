#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double interes, capital = 0;
   double total = 0;

   cout << "Introduzca su capital: " ;
   cin >> capital ;
   cout << "Introduzca el interes: " ;
   cin >> interes ;

   total = capital + capital * (interes / 100);

   cout << "\nSu capital ahora es de " << total << "\n\n" ;
}
