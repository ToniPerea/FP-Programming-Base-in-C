#include <iostream>
#include <cmath>

using namespace std;

const int ESPACIO = 50;

struct Registro{
   double temperatura;
   int ciudad, hora;
};

class SecuenciaDoubles{
private:
   static const int TAMANIO = 25;  // 2e6 es un real (dos millones) -> casting automático
                                    // Herramientas -> Opciones del Compilador ->
                                    // Compilador -> Añadir las siguientes opciones
                                    // -Wl,--stack,26000000

   int tope_maximo = TAMANIO;      // Se cambia sólo en uno de los constructores
                                   // Por si el usuario quiere restringir el número
                                   // máximo de elementos que puede almacenar en la secuencia
                                   // Los métodos de la clase que tengan que hacer alguna
                                   // comprobación sobre el tamaño, usarán tope_maximo en vez de TAMANIO

   double vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      double intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }

   bool EsCorrectoIndice(int pos){
      return 0 <= pos && pos < total_utilizados;
   }
public:
   SecuenciaDoubles()
      :total_utilizados(0) {
   }

   SecuenciaDoubles(int numero_maximo_componentes)
      :SecuenciaDoubles() {
      if (1 <= numero_maximo_componentes && numero_maximo_componentes <= TAMANIO)
         tope_maximo = numero_maximo_componentes;
   }


   int TotalUtilizados(){
      return total_utilizados;
   }

   int Capacidad(){
      return tope_maximo;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Aniade(double nuevo){
      if (total_utilizados < tope_maximo){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   void Modifica(int posicion, double nuevo){
      if (EsCorrectoIndice(posicion))
         vector_privado[posicion] = nuevo;
   }

   double Elemento(int indice){
      if (EsCorrectoIndice(indice))
         return vector_privado[indice];
      else
         return NAN;
   }

   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }

      return cadena;
   }
};

class TablaTemperaturas{
private:
   SecuenciaDoubles temperaturas[ESPACIO];
   int utilizados = 0;

   bool EnRango(int ciudad, int hora){
      return (ciudad >= 0 && ciudad < utilizados) && (hora >= 0 && hora < temperaturas[ciudad].TotalUtilizados());
   }

public:
   void Nueva_ciudad(SecuenciaDoubles secuencia_dada, int horas_dadas){
      for (int i = 0 ; i < horas_dadas ; i++){
         temperaturas[utilizados].Aniade(secuencia_dada.Elemento(i));
      }

      utilizados++;
   }

   double Valor(int ciudad_dada, int hora_dada){
      if (EnRango(ciudad_dada, hora_dada))
         return temperaturas[ciudad_dada].Elemento(hora_dada);
   }

   void Modifica(int ciudad_dada, int hora_dada, double temperatura_dada){
      if (EnRango(ciudad_dada, hora_dada))
         temperaturas[ciudad_dada].Modifica(hora_dada, temperatura_dada);
   }

   int Minimo(int ciudad_dada){
      double min;
      int indice_min, utilizados_ciudad = temperaturas[ciudad_dada].TotalUtilizados();

      if (ciudad_dada >= 0 && ciudad_dada < utilizados){
         min = temperaturas[ciudad_dada].Elemento(0);
         indice_min = 0;

         for (int i = 1 ; i < utilizados_ciudad ; i++){
            if (temperaturas[ciudad_dada].Elemento(i) < min){
               min = temperaturas[ciudad_dada].Elemento(i);
               indice_min = i;
            }
         }
      }
      return indice_min;
   }

   Registro Maximo_de_los_minimos(){
      int minimos[utilizados], indice_max, i;
      Registro registro_de_vuelta;
      SecuenciaDoubles temperaturas_minimas;
      double maximo;

      for (i = 0 ; i < utilizados ; i++)
         minimos[i] = Minimo(i);

      for (i = 0 ; i < utilizados ; i++)
         temperaturas_minimas.Aniade(temperaturas[i].Elemento(minimos[i]));

         maximo = temperaturas_minimas.Elemento(0);

         for (i = 1 ; i < utilizados ; i++){
            if (temperaturas_minimas.Elemento(i) > maximo){
               maximo = temperaturas_minimas.Elemento(i);
               indice_max = i;
            }
         }


      registro_de_vuelta.temperatura = temperaturas_minimas.Elemento(indice_max);
      registro_de_vuelta.ciudad = indice_max;
      registro_de_vuelta.hora = Minimo(indice_max);

      return registro_de_vuelta;
   }
};

int main(){
   TablaTemperaturas tabla_de_ejemplo;
   SecuenciaDoubles secuencia_copia;
   double temperatura, hora, ciudad;

   int horas;
   const int TERMINADOR = -1;
   double temperatura_al_vector;

   cin >> horas;

   while (horas != TERMINADOR){

      for (int i = 0 ; i < horas ; i++){
         cin >> temperatura_al_vector;
         secuencia_copia.Aniade(temperatura_al_vector);
      }

      tabla_de_ejemplo.Nueva_ciudad(secuencia_copia, horas);
      secuencia_copia.EliminaTodos();

      cin >> horas;
   }

    Registro registro_a_mostrar (tabla_de_ejemplo.Maximo_de_los_minimos());

   temperatura = registro_a_mostrar.temperatura;
   hora = registro_a_mostrar.hora;
   ciudad = registro_a_mostrar.ciudad;

   cout << "\nTemperatura = " << temperatura << "\nCiudad = " << ciudad << "\nHora = " << hora << "\n\n";
}
