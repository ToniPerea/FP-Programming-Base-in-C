#include <iostream>

using namespace std;

int main (){
    char letra_original, letra_convertida;
    const char paso_minuscula = 'a' - 'A';

    cout << "Introduzca una letra mayuscula o minuscula: ";
    cin >> letra_original;

    if (letra_original >= 'A' && letra_original <= 'Z'){
        letra_convertida = letra_original + paso_minuscula;
        cout << "\nLa letra pasada a minuscula es: " << letra_convertida << "\n\n";
	}
   else
      	if (letra_original >= 'a' && letra_original <= 'z'){
            letra_convertida = letra_original - paso_minuscula;
            cout << "\nLa letra pasada a mayuscula es: " << letra_convertida << "\n\n";
      	}
      	else{
            letra_convertida = letra_original;
            cout << "\nEl caracter introducido no pertenece al alfabeto." << "\n\n";
   		}

}
