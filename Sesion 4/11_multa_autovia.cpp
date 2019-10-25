#include <cmath>
#include <iostream>

using namespace std;

int main(){
   int velocidad, multa, puntos;
   bool gravedad_1, gravedad_2, gravedad_3, gravedad_4, gravedad_5;

   cout << "¿A qué velocidad circulaba?: ";
   cin >> velocidad;

   gravedad_1 = velocidad >=121 && velocidad <= 150;
   gravedad_2 = velocidad >=151 && velocidad <= 170;
   gravedad_3 = velocidad >=171 && velocidad <= 180;
   gravedad_4 = velocidad >=181 && velocidad <= 190;
   gravedad_5 = velocidad >=191;

   if (gravedad_1){
      multa = 100;
      puntos = 0;}
   else if (gravedad_2){
      multa = 300;
      puntos=2;}
   else if (gravedad_3){
      multa = 400;
      puntos = 4;}
   else if (gravedad_4){
      multa = 500;
      puntos = 6;}
   else if (gravedad_5){
      multa = 600;
      puntos = 6;}
   else{
      multa = 0;
      puntos = 0;}

   cout << "\n\nLa multa por la infracción es de: " << multa << " y se retirarán " << puntos << " puntos del carnet.\n\n";



}
