/*
Fecha: 19-02-2023
Versi�n: v_01;
Autor: Nicol�s Padilla

Problema:
    Se quiere tener un arreglo de 10 n�meros aleatorios entre 0-25.
    Se quiere llenar esos 10 elementos de forma aleatoria.
    Se quiere mostrar en pantalla el n�mero y la direcci�n en memoria de este.
Soluci�n:
    *Se har� un array de n�meros tipo int.
    *Se har� una funci�n para generar n�meros aleatorios entre 0 y 25
    *Se har� un arreglo de punteros con el fin de guardar todas las direcciones e imprimirlas todas de manera ordenada.
*/
#include <iostream>
#include <time.h>

using namespace std;

void llenaraleatorio(int numeros []);
void mostrarnum(int numeros [], int *punt[]);
int main()
{
    //Arreglo de 10 elementos
    int numeros[10];
    //Puntero
    int *punt[10];
    llenaraleatorio(numeros);
    mostrarnum(numeros,punt);
    return 0;
}
//Funci�n destinada a llenar el arreglo de n�meros aleatorios
void llenaraleatorio(int numeros []){
    //Establece el punto de partida de los n�meros aleatorios en funci�n a la hora del procesador
    //Con el fin de que la salida sea distinta en cada compilaci�n y ejecuci�n
    srand(time(NULL));
    //Ciclo que asigna a cada posici�n del arreglo un n�mero entre 1 y 25
    for(int i=0; i<10;i++){
        numeros[i]=rand()% 26;
    }
}
//Funci�n destinada a asignar los valores al puntero y mostrarlos en pantalla junto a su direcci�n
void mostrarnum(int numeros [], int *punt[]){
    //Asigna cada direcci�n del arreglo al puntero
    for(int i=0;i<10;i++){
        punt[i]=&numeros[i];
    }
    //Muestra en pantalla los elementos del arreglo
        cout<<"\n Elementos: \n";
        for(int i=0;i<10;i++){
        punt[i]=&numeros[i];
        cout<<"["<<*punt[i]<<"] ";
    }
    //Muestra en pantalla las direcciones del arreglo
        cout<<"\n Direcciones: \n";
        for(int i=0;i<10;i++){
        punt[i]=&numeros[i];
        cout<<"["<<punt[i]<<"] ";
    }
}
