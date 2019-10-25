#include <cmath>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

class GeneradorAleatorioEnteros{
private:
   mt19937 generador_mersenne; // Mersenne twister
   uniform_int_distribution<int> distribucion_uniforme;

   long long Nanosec(){
      return chrono::high_resolution_clock::now().
            time_since_epoch().count();
   }
public:
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   GeneradorAleatorioEnteros(int min, int max){
      const int A_DESCARTAR = 70000;
   // ACM TOMS Volume 32 Issue 1, March 2006

   auto semilla = Nanosec();
   generador_mersenne.seed(semilla);
   generador_mersenne.discard(A_DESCARTAR);
   distribucion_uniforme =
      uniform_int_distribution<int> (min, max);
}

int Siguiente(){
   return distribucion_uniforme(generador_mersenne);
   }
};

int main(){
   GeneradorAleatorioEnteros num_0_1_a_generar(1,5);
   GeneradorAleatorioEnteros entre_0_1(0,1);
   int max_esta_ronda, imprimir;

   for (int i = 0 ; i < 100 ; i++){
      max_esta_ronda = num_0_1_a_generar.Siguiente();
      for (int j = 0 ; j < max_esta_ronda ; j++){
         imprimir = entre_0_1.Siguiente();
         cout << imprimir;
      }
      cout << "\n";
   }

}
