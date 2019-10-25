#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double pi_antes_de_cristo, pi_mesopotamia, pi_claudio;

   cout << "Calculando los distintos valores de PI......" << "\n";

   pi_antes_de_cristo = 256.0/81;
   pi_mesopotamia = 3 + (1.0/8);
   pi_claudio = 377.0/120;

   cout << "\nLa PI segun la gente del año 1800 antes de Cristo es: " << pi_antes_de_cristo << "\n\n";
   cout << "La PI segun los mesopotamicos es: " << pi_mesopotamia << "\n\n";
   cout << "La PI segun Claudio Ptlomeo es: " << pi_claudio << "\n\n";
}
