#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double PI = 3.14159;
   double grado1, grado2 = 0;
   double radianes1, radianes2 = 0;

   cout << "Introduzca el primer grado: " ;
   cin >> grado1 ;
   cout << "Introduzca el segundo grado: " ;
   cin >> grado2 ;

   radianes1 = grado1 * (PI / 180) ;
   radianes2 = grado2 * (PI / 180) ;

   cout << "\nEl primer grado a radian es " << radianes1 << " y el segundo es " << radianes2 << "\n\n" ;
}
