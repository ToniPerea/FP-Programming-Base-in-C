#include <cmath>
#include <iostream>

using namespace std;

class Secuenciacaracteres{
private:
   static const int ESPACIO = 20;
   char vector[ESPACIO];
   int utilizados = 0;

   bool Posicion_correcta(int posicion){
      return posicion >= 0 && posicion < utilizados;
   }

public:
   void Add(char caracter_dado){
      if (utilizados < ESPACIO){
         vector[utilizados] = caracter_dado;
         utilizados++;
      }
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
         return vector[posicion_dada];
   }

   string To_String(){
      string cadena_a_devolver;
      cadena_a_devolver.reserve(utilizados);

      for(int i = 0 ; i < utilizados ; i++)
         cadena_a_devolver.push_back(vector[i]);
      return cadena_a_devolver;
   }

   void EliminaRepetidos(){
      bool no_es_la_primera = false;
      int i = 0, posicion_lectura, posicion_escritura;

      while (i < utilizados){
         for (int j = i - 1 ; j >= 0 && no_es_la_primera == false ; j--){
            no_es_la_primera = vector[j] == vector[i];
         }

         if (no_es_la_primera){
            posicion_lectura = i;
            posicion_escritura = i;

            while (posicion_lectura < utilizados){
               if (vector[posicion_lectura] == vector[i])
                  posicion_lectura++;
               else{
                  vector[posicion_escritura] = vector[posicion_lectura];

                  posicion_lectura++;
                  posicion_escritura++;
               }
            }
            utilizados = posicion_escritura;
            no_es_la_primera = false;
         }
         else
            i++;
      }
   }

   void Inserta(int pos_insercion, char valor_nuevo){
     for (int i = utilizados ; i > pos_insercion ; i--)
        vector[i] = vector[i-1];

     vector[pos_insercion] = valor_nuevo;
     utilizados++;
  }

   void Inserta_secuencia(string secuencia_dada, int posicion_dada){
      int j = posicion_dada;
      for (int i = 0 ; i < secuencia_dada.size() ; i++)
         Inserta(j, secuencia_dada[i]);
   }

   void Caracter_por_secuencia(char caracter_dado, Secuenciacaracteres secuencia_dada){
      Secuenciacaracteres secuencia_auxiliar;

      for (int i = 0 ; i < utilizados ; i++){
         if (vector[i] == caracter_dado){
            for (int j = 0 ; j < secuencia_dada.Utilizados() ; j++){
               secuencia_auxiliar.Add(secuencia_dada.Get_Elemento(j));
            }
         }
         else{
            secuencia_auxiliar.Add(vector[i]);
         }
      }

      for (int i = 0 ; i < secuencia_auxiliar.Utilizados() ; i++)
         vector[i] = secuencia_auxiliar.Get_Elemento(i);
      utilizados = secuencia_auxiliar.Utilizados();

   }

};

int main(){
   Secuenciacaracteres secuen;
   const char TERMINADOR = '#';
   char caracter, a_borrar;
   Secuenciacaracteres secuencia_para_remplazar;

   cout << "Introduzca caracteres a la secuencia: ";
   caracter = cin.get();

   while (caracter != TERMINADOR){
      secuen.Add(caracter);
      caracter = cin.get();
   }

   cout << "Introduzca caracteres para remplazar: ";
   caracter = cin.get();

   while (caracter != TERMINADOR){
      secuencia_para_remplazar.Add(caracter);
      caracter = cin.get();
   }

   cout << "Ahora el caracter a borrar: ";
   cin >> a_borrar;

   secuen.Caracter_por_secuencia(a_borrar, secuencia_para_remplazar);

   cout << "La secuencia es: " << secuen.To_String();
}
