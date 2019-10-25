#include <iostream>
using namespace std;

int main(){
	const int FILAS_MAXIMAS = 5, COLUMNAS_MAXIMAS = 10;
	int matriz[FILAS_MAXIMAS][COLUMNAS_MAXIMAS], inicio = 31, velocidad_variante, incremento = 10;

	for(int num_fil = 0 ; num_fil < FILAS_MAXIMAS ; num_fil++){
		if(num_fil == 1){
			inicio = inicio + incremento * 2;
		}
		else if(num_fil >= 2){
			inicio = inicio + incremento;
		}

		velocidad_variante = inicio;

		for(int num_col = 0 ; num_col < COLUMNAS_MAXIMAS ; num_col++){
			matriz[num_fil][num_col] = velocidad_variante;

			if(num_col == 2 && num_fil >= 1){
				if(num_fil == 1){
					velocidad_variante = velocidad_variante + incremento * 2;
				}
				else{
					velocidad_variante = velocidad_variante + incremento * 3;
				}
			}
			else{
				velocidad_variante = velocidad_variante + incremento;
			}
		}
	}

	for(int num_fil = 0 ; num_fil < FILAS_MAXIMAS ; num_fil++){
		for(int num_col = 0 ; num_col < COLUMNAS_MAXIMAS ; num_col++){
			cout << matriz[num_fil][num_col] << " ";
		}

		cout << "\n";
	}
}
