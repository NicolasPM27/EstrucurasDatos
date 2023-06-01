#include <stdio.h>
#include <iostream>
#include "quadTree.h"
using namespace std;
int main(int argc, char **argv) {
    QuadTree arbol;
    char* input;
    char* output;
    if(argc != 3) {
        cout << "Cantidad de argumentos no válida." << endl;
        cout << "[nombre_entrada.qt] [nombre_salida.pbm] " << endl;
        return 0;
    }else{
        input = argv[1];
        output = argv[2];
        cout << "Archivo a abrir: " << input << endl;
        cout << "Archivo de salida: " << output << endl;
    }
    arbol.LlenarArbol(input);
    arbol.ImprimirArbol(output);
    return 0;
}