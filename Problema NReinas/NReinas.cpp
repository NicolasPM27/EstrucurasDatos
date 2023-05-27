/*
Fecha: 26-05-2023
Versión: v_01
Autor: Nicolás Padilla

Problema:
    Dado un tablero de ajedrez de NxN,
    colocar N reinas de tal forma que no se amenacen entre ellas.

Solución:
    Backtracking, buscar todas las posibles soluciones y si en algun momento se determina que la solución no es ideal,
    se regresa a la solución anterior y se prueba con otra solución.

*/

#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;
int sol = 0;

/*
Función para comprobar que la reina se encuentre en una posición válida, es decir,
que no se encuentre en la misma columna, fila o diagonal que otra reina.
Recibe un arreglo de reinas, el tamaño del tablero y la posición de la reina a comprobar / el nivel del árbol.
*/
bool comprobar(int reinas[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        if ((reinas[i] == reinas[k]) // Si dos reinas están en la misma fila
            or (abs(k - i) == abs(reinas[k] - reinas[i])))
        { // Si dos reinas están en la misma diagonal, a partir del valor absoluto de la resta de sus posiciones.
            return false;
        }
    }
    return true;
}
/*
Función recursiva para colocar las reinas en el tablero.
Recibe un arreglo de reinas, el tamaño del tablero y la posición de la reina a colocar / el nivel del árbol.
*/
void Nreinas(int reinas[], int n, int k)
{
    if (k == n)
    { // Si el nivel del arbol ya llegó al tamaño del tablero/# reinas, se encontró una solución, ya que es el ultimo nivel.
        sol++;
        cout << "Solución " << sol << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << "[" << reinas[i] << "]-";
        }
        cout << endl;
    }
    else
    { // Si no se ha llegado al ultimo nivel, se colocan las reinas en las posiciones posibles.
        for (reinas[k] = 0; reinas[k] < n; reinas[k]++)
        {
            if (comprobar(reinas, n, k))
            {                              // Se comprueba que la reina se encuentre en una posición válida.
                Nreinas(reinas, n, k + 1); // Se llama a la función recursiva para colocar la siguiente reina.
            }
        }
    }
}

