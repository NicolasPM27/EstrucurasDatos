#include <iostream>
#include <fstream>
#include <cstring>
#include "funciones.h"

using namespace std;

//Función para ingresar los datos del archivo en el arbol
void ingresarDatos(AVL &arbol){
ifstream archivo;
string linea;
int v;//Variable que almacena los valores enteros del archivo
archivo.open("entrada.txt", ios::in);
if(archivo.fail()){
    cerr<<"Error abriendo archivo";
}
if(archivo.is_open()){
    while(getline(archivo,linea)){
        char* operacion =strtok(&linea[0]," ");//Tokenizar el string desde el inicio hasta un espacio (" ")
        char* valor =strtok(NULL,"");//Tokenizar el string desde el espacio hasta el final
        if(*operacion=='A'){
        v=stoi(valor);
        arbol.insertar(v);
        }
        if(*operacion=='E'){
        v=stoi(valor);
        arbol.eliminar(v);
        }
    }
}

}
//Función que calcula la mediana del arbol
void mediana(AVL &arbol){
int tamano=arbol.tamano(arbol.getRaiz());
//cout<<"["<<tamano<<"]";
double limite=tamano/2;//Variable que representa la posición central del arbol
int mediana1=0;//Variable que almacena la mediana del arbol
int mediana2=0;//Variable que almacena la segunda posición central del arbol
arbol.recorrer(arbol.getRaiz(),limite,mediana1,mediana2);
if(tamano%2==0){//Si es par
    cout<<"La mediana es: "<<mediana1<<"+"<<mediana2<<"/2 = "<<(mediana1+mediana2)/2<<"\n";
}else {
    cout<<"La mediana es: "<<mediana1;
}
}
