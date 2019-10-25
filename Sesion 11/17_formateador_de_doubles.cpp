#include <cmath>
#include <iostream>

using namespace std;

class Formateo {
private:
   string delimitador_izquierda, delimitador_derecha;
   char punto_o_coma;
   int precision;
   double real;

   int PotenciaEntera(double base_dada, int exponente_dado){
      int numero_de_vuelta = base_dada;

      if (exponente_dado == 0)
         numero_de_vuelta = 1;
      else {
         for (int i = 1 ; i < exponente_dado ; i++)
            numero_de_vuelta = numero_de_vuelta * base_dada;
      }

      return numero_de_vuelta;
   }

   double redondeo(double numero_dado, int precision_dada){
      numero_dado = round(numero_dado * PotenciaEntera(10 , precision_dada));
      numero_dado = numero_dado / PotenciaEntera(10 , precision_dada);

      return numero_dado;
   }

   string EliminaUltimos(string cadena_dada, char a_borrar_dado){
      while (cadena_dada[cadena_dada.size() - 1] == a_borrar_dado){
         cadena_dada.pop_back();
      }

      return cadena_dada;
   }

   string Quieres_punto_o_coma(string cadena_dada){
      for (int i = 0 ; i < cadena_dada.size() ; i++){
         if (cadena_dada[i] == '.')
            cadena_dada[i] = punto_o_coma;
      }
      return cadena_dada;
   }

   string DoubleToString(double numero_dado, int precision_dada){
      string cadena_a_devolver;

      numero_dado = redondeo(numero_dado, precision_dada);
      cadena_a_devolver = to_string(numero_dado);

      return EliminaUltimos(cadena_a_devolver, '0');

   }

public:
   Formateo(double real_dado)
      :real(real_dado), punto_o_coma('.'), delimitador_derecha(">>"), delimitador_izquierda("<<"), precision(4)
      {}
   Formateo(double real_dado, string delimitador_izquierda_dado, string delimitador_derecha_dado, char punto_o_coma_dado, int precision_dada)
      :real(real_dado), punto_o_coma(punto_o_coma_dado), delimitador_derecha(delimitador_derecha_dado), delimitador_izquierda(delimitador_izquierda_dado), precision(precision_dada)
      {}
   string GetString(){
      string cadena_de_vuelta;
         cadena_de_vuelta = delimitador_izquierda + DoubleToString(real, precision) + delimitador_derecha;

      if (punto_o_coma != '.')
         cadena_de_vuelta = Quieres_punto_o_coma(cadena_de_vuelta);

      return cadena_de_vuelta;
   }
};

int main(){
   const char TERMINADOR = '#';
   double real;
   string delimitador_derecha, delimitador_izquierda;
   char caracter, punto_o_coma;
   int precision;

   cout << "Introduzca el real: ";
   cin >> real;

   cout << "Intrdozca la precision: ";
   cin >> precision;

   cout << "Introduca el punto o la coma";
   cin >> punto_o_coma;

   cout << "Introduzca el delimitador derecho";

   cin >> caracter;

   while (caracter != TERMINADOR){
      delimitador_derecha.push_back(caracter);
      cin >> caracter;
   }
   cout << "Introduzca el delimitador izquierdo";

   cin >> caracter;

   while (caracter != TERMINADOR){
      delimitador_izquierda.push_back(caracter);
      cin >> caracter;
   }

   Formateo a_formatear(real, delimitador_izquierda, delimitador_derecha, punto_o_coma, precision);

   cout << "\n" << a_formatear.GetString() << "\n\n";

}
