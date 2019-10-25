#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double media;
	double desviacion_tipica=-1;
	double x;
	double gaussiana;
	double minimo;
	double maximo;
	double incremento;
	const double pi=3.1416;

	cout << "Introduce el valor de la media: ";
	cin >> media;

	while (desviacion_tipica<0){
		cout << "Introduce el valor de la desviacion tipica: ";
		cin >> desviacion_tipica;
	}

	cout << "Introduce el valor minimo: ";
	cin >> minimo;

	do {
		cout<<"Introduce el valor maximo: ";
		cin>>maximo;
	}while(maximo<minimo);

	cout << "Introduce el incremento: ";
	cin >> incremento;

	x = minimo;

	while(x <= maximo){
	gaussiana = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((x-media)/desviacion_tipica,2));

	cout << gaussiana << "   ";
	x = minimo + incremento;
	incremento += incremento;
}
	cout << endl;

}
