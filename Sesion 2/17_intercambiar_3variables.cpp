#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int x, y, z ,auxiliar = 0;

   cout << "Introduzca el valor de x, y, z respectivamente: ";
   cin >> x;
   cin >> y;
   cin >> z;

   auxiliar = z;
   z = y;
   y = x;
   x = auxiliar;

   cout << "\nEl valor de x es " << x << endl;
   cout << "\nEl valor de y es " << y << endl;
   cout << "\nEl valor de z es " << z << "\n\n";
}
