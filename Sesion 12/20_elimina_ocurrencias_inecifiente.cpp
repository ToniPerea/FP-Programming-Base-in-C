#include <cmath>
#include <iostream>

using namespace std;

class Secuenciacaracteres{
private:
   static const int ESPACIO = 50;
   char vector[ESPACIO];
   int utilizados = 0;

   bool Posicion_correcta(int posicion){
      return posicion >= 0 && posicion < utilizados;
   }

public:
   void Add(char caracter_dado){
      if (utilizados < ESPACIO)
         vector[utilizados] = caracter_dado;

      utilizados++;
   }

   void Borrar_en_posicion(int posicion_dada){
      if (Posicion_correcta(posicion_dada)){
         for (int j = posicion_dada ; j < utilizados - 1 ; j++)
            vector[j] = vector [j+1];

            utilizados--;
      }
   }

   void Borrar_caracter(char a_borrar_dado){
      int i = 0;

      while (i < utilizados){
         if (vector[i] == a_borrar_dado)
            Borrar_en_posicion(i);
         else
            i++;
      }
   }

   int Utilizados(){
      return utilizados;
   }

   void Modifica(char caracter_dado, int posicion_dada){
      if (Posicion_correcta(posicion_dada))
         vector[posicion_dada] = caracter_dado;
   }

   char Get_Elemento(int posicion_dada){
      if (Posicion_correcta(posicion_dada))
         return vector [posicion_dada];
   }

   string To_String(){
      string cadena_a_devolver;
      cadena_a_devolver.reserve(utilizados);

      for (int i = 0 ; i < utilizados ; i++)
         cadena_a_devolver.push_back(vector[i]);

      return cadena_a_devolver;
   }

};

int main(){
   Secuenciacaracteres secuen;
   const char TERMINADOR = '#';
   char caracter, a_borrar;

   cout << "Introduzca caracteres a la secuencia: ";
   caracter = cin.get();

   while (caracter != TERMINADOR){
      secuen.Add(caracter);
      caracter = cin.get();
   }

   cout << "Ahora introduzca el caracter a borrar: ";
   cin >> a_borrar;

   secuen.Borrar_caracter(a_borrar);

   cout << "La secuencia es: " << secuen.To_String() << "\n\n";
}
