#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "NReinas.h"

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE,"Spanish");//signos de puntuación
    int k = 0; // Nivel del árbol
    int N;     // Tamaño del tablero/# reinas
    cout << "-------------------------------BIENVENIDO A LA SIMULACIÓN DEL PROBLEMA DE LAS N REINAS-------------------------------" << endl;
    
    do 
    {
        sol = 0;
        cout << "Ingrese el número de reinas o (-1) para salir: ";
        cin >> N;
        if(N == -1)
        {
            cout << "Gracias por usar el programa" << endl;
            break;
        }
        if (N < 4)
        {
            cout << "No se puede resolver el problema para un tablero de " << N << "x" << N << endl;
        }
        else
        {
            int *reinas = new int[N];// Se crea un arreglo de reinas del tamaño del tablero.
            
            for (int i = 0; i < N; i++)// Se inicializa el arreglo de reinas en -1.
            {
                reinas[i] = -1;
            }

            Nreinas(reinas, N, k);// Se llama a la función recursiva para colocar las reinas en el tablero.

        }
    }while ( N != -1);

    return 0;
}