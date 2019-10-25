#include <iostream>
#include <cmath>

using namespace std;

class CalificacionFinal {
private:
   double practico_1, practico_2, evaluacion_continua, examen_escrito, subida;
public:
   CalificacionFinal(double practico_1_dado, double practico_2_dado, double evaluacion_continua_dada, double examen_escrito_dado, double subida_dada)
      :practico_1(practico_1_dado), practico_2(practico_2_dado), evaluacion_continua(evaluacion_continua_dada), examen_escrito(examen_escrito_dado), subida(subida_dada)
         {
            if (examen_escrito + subida >= 5)
               examen_escrito = examen_escrito + subida;
         }
   double Nota(bool estandar){
      double nota_de_corte = 4, ponderacion_continua_practico_1 = 0.1, ponderacion_practico_2 = 0.2, ponderacion_escrito = 0.6;
      if (!estandar){
         nota_de_corte = 4.4;
         ponderacion_continua_practico_1 = 0.05;
         ponderacion_escrito = 0.7;
      }
      if (examen_escrito >= nota_de_corte)
         return (practico_1 + evaluacion_continua)*ponderacion_continua_practico_1 + practico_2*ponderacion_practico_2 + examen_escrito*ponderacion_escrito;
      else
         return examen_escrito;
   }
};

int main(){
   const int TERMINADOR = -1;
   double practico_1, practico_2, evaluacion_continua, examen_escrito, subida;

   cin >> subida;
   while (subida != TERMINADOR){
      cout << "\n------------------------------------------\n";
      cin >> evaluacion_continua;
      while (evaluacion_continua != TERMINADOR){
         cin >> practico_1 >> practico_2 >> examen_escrito;
         CalificacionFinal alumno(practico_1, practico_2, evaluacion_continua, examen_escrito, subida);
         cout << alumno.Nota(true) << "/" << alumno.Nota(false) << "\n";
         cin >> evaluacion_continua;
      }
      cin >> subida;
   }
}
