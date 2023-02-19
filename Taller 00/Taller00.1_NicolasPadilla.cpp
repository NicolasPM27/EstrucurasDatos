/*
Fecha: 19-02-2023
Versión: v_01;
Autor: Nicolás Padilla

Problema:
    Se quiere tener un arreglo de 10 números aleatorios entre 0-25.
    Se quiere llenar esos 10 elementos de forma aleatoria.
    Se quiere mostrar en pantalla el número y la dirección en memoria de este.
Solución:
    *Se hará un array de números tipo int.
    *Se hará una función para generar números aleatorios entre 0 y 25
    *Se hará un arreglo de punteros con el fin de guardar todas las direcciones e imprimirlas todas de manera ordenada.
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
//Función destinada a llenar el arreglo de números aleatorios
void llenaraleatorio(int numeros []){
    //Establece el punto de partida de los números aleatorios en función a la hora del procesador
    //Con el fin de que la salida sea distinta en cada compilación y ejecución
    srand(time(NULL));
    //Ciclo que asigna a cada posición del arreglo un número entre 1 y 25
    for(int i=0; i<10;i++){
        numeros[i]=rand()% 26;
    }
}
//Función destinada a asignar los valores al puntero y mostrarlos en pantalla junto a su dirección
void mostrarnum(int numeros [], int *punt[]){
    //Asigna cada dirección del arreglo al puntero
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
