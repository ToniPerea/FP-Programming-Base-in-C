#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int numero_a , numero_b, numero_multiplicado;

   cout << "Introduce los numero a comparar sus signos: ";
   cin >> numero_a;
   cin >> numero_b;

   numero_multiplicado = numero_a * numero_b;

   if(numero_multiplicado <= 0){
      cout << "\nNo tienen el mismo signo." << "\n\n";
   }else{
      cout << "\nSi tienen el mismo signo." << "\n\n";
   }


}
