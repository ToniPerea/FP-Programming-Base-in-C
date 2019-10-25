#include <cmath>
#include <iostream>
using namespace std;

int main(){
   const int NUMERO_DE_MESES = 11, MES_LARGO = 31, MES_CORTO = 30, MES_FEBRERO = 28, MES_BISIESTO = 29;
   int mes[NUMERO_DE_MESES];
   int dias, meses, anios, i;
   bool es_bisiesto, no_mas_de_doce_meses;

   for (i = 0 ; i <= 6 ; i = i + 2){
      mes[i] = MES_LARGO;
      if (i != 0)
         mes[i-1] = MES_CORTO;
   }

   for (i = 7 ; i <= 11 ; i = i + 2){
      mes[i] = MES_LARGO;
      if (i != 7)
         mes [i-1] = MES_CORTO;
   }

   cout << "\nIntroduzca día, mes y año: ";
   cin >> dias >> meses >> anios;

   while (dias >= 0){
      es_bisiesto = (anios % 4 == 0 && anios % 100 != 0) || (anios % 400 == 0);

      if (es_bisiesto)
         mes[1] = MES_BISIESTO;
      else
         mes[1] = MES_FEBRERO;

      no_mas_de_doce_meses = meses <= NUMERO_DE_MESES + 1;

      if (dias <= mes[meses-1] && no_mas_de_doce_meses)
         cout << "La fecha es correcta.";
      else
         cout << "La fecha no es correcta";

      cout << "\nIntroduzca día, mes y año: ";
      cin >> dias >> meses >> anios;
   }








}
