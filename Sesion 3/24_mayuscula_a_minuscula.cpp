#include <iostream>
#include <cmath>

using namespace std;

int main (){
    char letra_minuscula, letra_mayuscula;
    const int Dist_Mayus_Minus = 'a'-'A';

    cout << "Introduzca la letra Mayuscula: ";
    cin >> letra_mayuscula;

    letra_minuscula = letra_mayuscula + Dist_Mayus_Minus;

    cout << "\nLa letra minuscula es: " << letra_minuscula << "\n\n";

}
