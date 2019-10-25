#include <cmath>
#include <iostream>
using namespace std;

int main(){
   double lat1, lat2, lon1, lon2, alpha, seno_latitud, seno_longitud, longitud_del_segmento, formula_c, minimo, altura1, altura2, incremento_altura, distancia_final;
   const double CONSTANTE_DE_CONVERSION = asin(0.5)*6 / 180.0, RADIO_MEDIO_TERRESTRE = 6372797.560856;

   cout << "Introduzca latitud, longitud y altura de la primera posición: ";
   cin >> lat1 >> lon1 >> altura1;
   cout << "Introduzca latitud, longitud y altura de la segunda posición: ";
   cin >> lat2 >> lon2 >> altura2;


   //Reciclo las variables porque no las voy a utilizar para nada en grados.
   lat1 = lat1 * CONSTANTE_DE_CONVERSION;
   lon1 = lon1 * CONSTANTE_DE_CONVERSION;
   lat2 = lat2 * CONSTANTE_DE_CONVERSION;
   lon2 = lon2 * CONSTANTE_DE_CONVERSION;

   seno_latitud = sin( (lat2 - lat1) / 2.0 );
   seno_longitud = sin( ( lon2 - lon1) / 2.0);

   alpha = pow(seno_latitud , 2) + cos(lat1) * cos(lat2) * pow(seno_longitud , 2);

   minimo = 1;

   if (sqrt(alpha) < 1)
      minimo = sqrt(alpha);

   formula_c = 2 * asin(minimo);

   longitud_del_segmento = RADIO_MEDIO_TERRESTRE * formula_c;
   incremento_altura = altura2 - altura1;
   distancia_final = pow(longitud_del_segmento , 2) + pow(incremento_altura , 2);
   distancia_final = sqrt(distancia_final);

   cout << fixed << "\n\nLa distancia sobre plano entre los dos puntos es de: " << longitud_del_segmento << " metros.";
   cout << "\n\nLa distancia real entre los dos puntos es de: " << distancia_final << " metros.\n\n";

   }
