#include <cmath>
#include <iostream>

using namespace std;

const int NULO = -1;

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

class Instante {
private:
   int horas, minutos, segundos;

   bool Rango_Correcto(double dato, int min, int max){
      return dato <= max && dato >= min;
   }

public:
   Instante(int horas_dadas, int minutos_dados, int segundos_dados)
      :horas(horas_dadas), minutos(minutos_dados), segundos(segundos_dados)
      {
         if (!Rango_Correcto(horas, 0, 23))
            horas = NULO;
         if (!Rango_Correcto(minutos, 0, 59))
            minutos = NULO;
         if (!Rango_Correcto(segundos, 0, 59))
            segundos = NULO;
      }

   Instante(int segundos_dados)
      {
         int horas_calculadas, minutos_calculados, segundos_calculados;

         horas = segundos_dados / 3600;
         segundos_dados = segundos_dados %  3600;
         minutos = segundos_dados / 60;
         segundos_dados = segundos_dados % 60;
         segundos = segundos_dados;
      }
   Instante()
      :horas(NULO), minutos(NULO), segundos(NULO)
      {}

   int Segundos_Transcurridos(){
      return horas*3600 + minutos*60 + segundos;
   }

   int Minutos_Transcurridos(){
      return horas*60 + minutos + segundos/60;
   }

   string Instante_a_partir_de_segundos(int segundos_dados){
      int horas_de_vuelta, minutos_de_vuelta, segundos_de_vuelta;
      string cadena_de_vuelta;

      horas_de_vuelta = segundos_dados / 3600;
      segundos_dados = segundos_dados %  3600;
      minutos_de_vuelta = segundos_dados / 60;
      segundos_dados = segundos_dados % 60;
      segundos_de_vuelta = segundos_dados;

      cadena_de_vuelta = to_string(horas_de_vuelta) + " h " + to_string(minutos_de_vuelta) + "' " + to_string(segundos_de_vuelta) + "'' ";

      return cadena_de_vuelta;
   }

   int GetHoras(){
      return horas;
   }

   int GetMinutos(){
      return minutos;
   }

   int GetSegundos(){
      return segundos;
   }

   void Set(int horas_dadas, int minutos_dados, int segundos_dados){
      if (Rango_Correcto(horas_dadas, 0, 23))
         horas = horas_dadas;
      if (Rango_Correcto(minutos_dados, 0, 59))
         minutos = minutos_dados;
      if (Rango_Correcto(horas_dadas, 0, 59))
         segundos = segundos_dados;

   }
};

class VehiculoTunel {
private:
   string matricula;
   Instante entrada;
   Instante salida;
public:
   VehiculoTunel()
      :matricula("NONE")
      {}

   string Matricula(){
      return matricula;
   }

   Instante Entrada(){
      return entrada;
   }

   Instante Salida(){
      return salida;
   }

   bool Ha_salido(){
      return salida.GetHoras() != NULO;
   }

   void SetVehiculo(string matricula_dada, Instante entrada_dada){
      entrada = entrada_dada;
      matricula = matricula_dada;
   }

   void Sale(Instante salida_dada){
      salida = salida_dada;
   }

   int SegundosEntrada(){
      return entrada.Segundos_Transcurridos();
   }

   int SegundosSalida(){
      return salida.Segundos_Transcurridos();
   }

   int Diferencia_entrada_salida(){
      if (Ha_salido())
         return SegundosSalida() - SegundosEntrada();
   }

};

class Tunel {
private:
   static const int ESPACIO = 50;
   double longitud;
   VehiculoTunel vehiculos[ESPACIO];
   int vehiculos_utilizados = 0;

   int Numero_de_coche(string matricula_dada){
      for (int i = 0 ; i < vehiculos_utilizados ; i++){
         if (vehiculos[i].Matricula() == matricula_dada)
            return i;
      }
   }

   bool RangoCorrecto(int numero_de_coche){
      return numero_de_coche >= 0 && numero_de_coche < vehiculos_utilizados;
   }

public:
   Tunel(double longitud_dada)
      :longitud(longitud_dada)
      {}

   void Entra(string matricula_dada, Instante instante_dado){
      vehiculos[vehiculos_utilizados].SetVehiculo(matricula_dada, instante_dado);
      vehiculos_utilizados++;
   }

   void Sale(string matricula_dada, Instante instante_dado){
      vehiculos[Numero_de_coche(matricula_dada)].Sale(instante_dado);
   }

   string GetMatricula(int numero_de_coche){
      if (RangoCorrecto(numero_de_coche))
         return vehiculos[numero_de_coche].Matricula();
   }

   string Velocidad(int numero_de_coche){
      double velocidad;

      if (RangoCorrecto(numero_de_coche)){
         if (!vehiculos[numero_de_coche].Ha_salido())
            return "No ha salido";
         else{
            velocidad = longitud * 3600 / vehiculos[numero_de_coche].Diferencia_entrada_salida();

            Formateo velocidad_de_vuelta(velocidad, "", "km/h",'.',1);
            return velocidad_de_vuelta.GetString();
         }
      }
   }
};

int main(){
   const char TERMINADOR = '#';
   double longitud;
   char entrada_salida;
   int numero_de_coches = 0, hora, minuto, segundo;
   string matricula;

   cin >> longitud;

   Tunel un_tunel(longitud);

   cin >> entrada_salida;

   while (entrada_salida != TERMINADOR){
      cin >> matricula >> hora >> minuto >> segundo;
      Instante un_instante(hora, minuto, segundo);
      if (entrada_salida == 'E'){
         un_tunel.Entra(matricula, un_instante);
         numero_de_coches++;
      }
      else
         un_tunel.Sale(matricula, un_instante);

      cin >> entrada_salida;
   }

   for (int i = 0; i < numero_de_coches ; i++){
      cout << "Matricula: " << un_tunel.GetMatricula(i) << "\n";
      cout << "Velocidad:" << un_tunel.Velocidad(i) << "\n\n";
   }
}
