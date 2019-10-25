#include <cmath>
#include <iostream>
using namespace std;

int main(){
   int tope_adicional = 0, i, j;

   for (i = 31 ; i <= 81 ; i = i + 10){                               //primer numero de cada fila
      if (i != 41){                                                   //Menos el 41 que se salta con este if
         cout << "\n";
         for (j = i ; j <= (i + 90 + tope_adicional) ; j = j + 10){   //Este for se utiliza para las columnas
            if (i == 51){                                             //En la fila "51" se salta un incremento de 10 en el 81
               if (j != i + 30)
                  cout << " " << j;
            }
            else if (i >= 61){                                        //Y a partir de la 61 se salta dos, en el i+30 e i+40
               if ((j != i + 30) && (j != i + 40))
                  cout << " " << j;
            }
            else                                                      //Sin embargo en la primera fila no se salta ninguna columna
               cout << " " << j;
         }

         if (tope_adicional < 20)                                     //Este if es para ir fijando el tope en cada una de las filas, incrementando hasta 20.
            tope_adicional = tope_adicional + 10;
      }
   }

   cout << "\n";
}
