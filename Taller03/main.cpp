#include <iostream>
#include <fstream>
#include <cstring>
#include "funciones.h"

using namespace std;

int main(){
AVL arbol;
int op=1;//Opción que elige el usuario
ingresarDatos(arbol);
cout<<"Datos cargados del archivo con éxito";
while(op!=0){
    cout<<"\n1. Imprimir arbol In Order\n2. Calcular mediana\n0. Salir\nIngrese una opción:";
    cin>>op;
    switch(op){
        case 0:
            cout<<"Gracias,hasta pronto!\n";
            break; 
        case 1:
            arbol.imprimirInOrder(arbol.getRaiz());
        break;
        case 2:
            mediana(arbol);
        break;
        default:
            cout<<"Ingresó una opción inválida";
        break;
    }
}
return 0;

}