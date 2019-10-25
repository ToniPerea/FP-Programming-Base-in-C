#include <iostream>
#include <cmath>

using namespace std;

int main(){

    //Detectar Minuscula.

    char letra;
    bool es_minuscula;

    cout << "\nIntroduzca una letra: ";
    cin >> letra;

    es_minuscula = (letra >= 'a') && (letra <= 'z');

    cout << "\n " << es_minuscula;
    cout << "\n\n";

    //Edad.

    int edad;
    bool es_edad;

    cout << "\nIntroduzca la edad: ";
    cin >> edad;

    es_edad = (edad > 65) || (edad < 18);

    cout << "\n" << es_edad;
    cout << "\n\n";

    //Adivine

    int adivine;
    bool es_variable;

    cout << "\nIntroduzca el valor: ";
    cin >> adivine;

    es_variable = (adivine > 1) && (adivine < 100);

    cout << "\n " << es_variable;
    cout << "\n\n";

    // Detectar años bisiestos

    int anio;
    bool es_bisiesto;

    cout << "\nIntroduzca un año: ";
    cin >> anio;

    es_bisiesto = ( (anio % 4 == 0) && (anio % 100 != 0) )   ||  (anio % 400 == 0) ;

    cout << "\n" << es_bisiesto;
    cout << "\n\n";

}
