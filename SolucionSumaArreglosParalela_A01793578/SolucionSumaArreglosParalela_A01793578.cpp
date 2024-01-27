// SolucionSumaArreglosParalela_A01793578.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

// 2.- Configurarlo para que pueda utilizar la librería OpenMP
# ifdef _OPENMP
    #include <omp.h>
#endif

using namespace std;

int main() {
    // 3.- Crear dos arreglos con 1000 elementos cada uno
    const int sizeArray = 1000;
    int a1[sizeArray];
    int a2[sizeArray];
    int aResult[sizeArray];

    // Asignar valores aleatorios entre 0 y 10 a cada elemento de los arreglos
    for (int i = 0; i < sizeArray; ++i) {
        a1[i] = rand() % 11;
        a2[i] = rand() % 11;
    }

    # ifdef _OPENMP
        omp_set_num_threads(4);
    #endif

    // 4.- Realizar un for paralelo para sumar ambos arreglos
    #pragma omp parallel for
    for (int i = 0; i < sizeArray; ++i) {
        aResult[i] = a1[i] + a2[i];
        // Validación de que se está ejecutando correctamente el procesamiento paralelo.
         int tid = omp_get_thread_num();
         cout << "Hilo " << tid << " procesando iteración " << i << endl;
    }

    // 5.- Imprimir solo los primeros 15 elementos para comprobación
    cout << "Array 1\tArray 2\tResult: " << endl;
    for (int i = 0; i < 15; ++i) { 
        cout << a1[i] << '\t' << a2[i] << '\t' << aResult[i] << endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
