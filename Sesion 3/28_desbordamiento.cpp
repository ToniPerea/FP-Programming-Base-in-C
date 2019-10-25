#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //SALIDAS

    cout << "int chico, chico1, chico2;\nchico1 = 1234567;\nchico2 = 1234567;\nchico = chico1 * chico2;";
    cout << "\n\nRESPUESTA : Desbordamiento. El producto de 'chico1' y 'chico2' es demasiado grande\n\n\n";

    cout << "long grande;\nint chico1, chico2;\nchico1 = 1234567;\nchico2 = 1234567;\ngrande = chico1 * chico2";
    cout << "\n\nRESPUESTA : Desbordamiento. Exactamente igual al anterior.No hemos cambiado nada\n\n\n";

    cout << "double resultado, real1, real2;\nreal1 = 123.1;\nreal2 = 124.2;\nresultado = real1 * real2;";
    cout << "\n\nRESPUESTA : Error de Precision.\n\n\n";

    cout << "double resultado, real1, real2;\nreal1 = 123456789.1;\nreal2 = 123456789.2;\nresultado = real1 * real2;";
    cout << "\n\nRESPUESTA : Desbordamiento.\n\n\n";

    cout << "double real, otro_real;\nreal = 2e34;\notro_real = real + 1;\notro_real = otro_real - real;";
    cout << "\n\nRESPUESTA : Precision. El incremento no se puede percibir.\n\n\n";

    cout << "double real, otro_real;\nreal = 1e+300;\notro_real = 1e+200;\notro_real = otro_real * real;";
    cout << "\n\nRESPUESTA : Desbordamiento. El producto es demasiado grande...\n\n\n";

    cout << "float chico;\ndouble grande;\ngrande = 2e+150;\nchico = grande;";
    cout << "\n\nRESPUESTA: Desbordamiento. -float- no puede almacenar valores mayores a 3.40e38\n";

}
