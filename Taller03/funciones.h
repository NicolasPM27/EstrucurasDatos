#ifndef funciones_h
#define funciones_h
#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;
//Clase que representa el nodo de arbol AVL
class Nodo
{
    public:
    int dato;//Dato que contiene el nodo
    int altura;//Altura de subarbol
    Nodo *izq;//Puntero a la izquierda del arbol
    Nodo *der;//Puntero a la derecha del arbol

Nodo(int v): dato(v), altura(1),izq(nullptr), der(nullptr){}//Constructor
}; 

//Clase que representa el arbol AVL
class AVL{
private:    
    Nodo* raiz;//Nodo raiz

//Función que arroja la altura del nodo
int calcularAltura(Nodo* nodo){
    if(nodo==nullptr){
        return 0;
    }
    return nodo->altura;
}
//Función para obtener el factor de balance de los subárboles   
int diferencia(Nodo* nodo){
        if(nodo==nullptr){
            return 0;
        }
    return calcularAltura(nodo->izq)-calcularAltura(nodo->der);
}
//Función que devuelve el dato máximo de dos enteros
int max(int a, int b){

    return(a>b)? a:b;//Ternario, si a>b, retorna a, si no, retorna b
}    

//Función que representa la rotación simple a la derecha
Nodo* rotDerecha(Nodo* y){//y representa el nodo que hay que balancear
 if(y==nullptr||y->izq==nullptr){
    return y;
}
 Nodo* x = y->izq;//X es el nodo izquierdo 
 Nodo* T2 = x->der;//T2 significa el subárbol del nodo 

    x->der = y;
    y->izq = T2;
//Actualizar las alturas
x->altura= max(calcularAltura(x->izq),calcularAltura(x->der))+1;
y->altura= max(calcularAltura(y->izq),calcularAltura(y->der))+1;

return x;
}

//Función que representa la rotación simple a la izquierda
Nodo* rotIzquierda(Nodo* x){//x representa el nodo que hay que balancear
if(x==nullptr|| x->der==nullptr){
    return x;
}
 Nodo* y = x->der;//y es el nodo derecho 
 Nodo* T2 = y->izq;//T2 significa el subárbol del nodo 

    y->izq = x;
    x->der = T2;
//Actualizar las alturas
x->altura= max(calcularAltura(x->izq),calcularAltura(x->der))+1;
y->altura= max(calcularAltura(y->izq),calcularAltura(y->der))+1;

return y;
}
//Función de insertar
Nodo* insertar(Nodo* nodo, int v){

if(nodo==nullptr)
    return new Nodo(v);
//Se recorre el lugar correcto para insertar el nodo
if(v>nodo->dato)
    nodo->der=insertar(nodo->der,v);
else
    nodo->izq=insertar(nodo->izq,v); 

    return nodo;   
//Actualizar altura del nodo
nodo->altura=1+max(calcularAltura(nodo->izq),calcularAltura(nodo->der));    

//Balancear el arbol    
int factorBalance =diferencia(nodo);
//4 movimientos posibles:
//Izquierda izquierda 
if(factorBalance>1 && v<nodo->izq->dato)
    return rotDerecha(nodo);
//Derecha derecha
if(factorBalance<-1 && v> nodo->der->dato)   
    return rotIzquierda(nodo);
//Izquierda derecha
if(factorBalance>1 && v> nodo->izq->dato){
    nodo->izq=rotIzquierda(nodo->izq);
    return rotDerecha(nodo);
}
//Derecha izquierda
if(factorBalance<-1 && v<nodo->der->dato){
    nodo->der=rotDerecha(nodo->der);
    return rotIzquierda(nodo);
}

return nodo;
}

//Función para buscar el nodo menor(Usada para eliminar un nodo en caso que tenga dos hijos)
Nodo* minValor(Nodo* nodo){
    Nodo* actual= nodo;
    while(actual->der!=nullptr)
        actual=actual->der;
    return actual;
}   
//Función de eliminar un nodo
Nodo* eliminar(Nodo* nodo, int v){
    if(nodo==nullptr)
        return nodo;

if(v<nodo->dato)//Si el dato a eliminar se encuentra en el subarbol izquierdo
    nodo->izq=eliminar(nodo->izq,v);
else if(v>nodo->dato)//Si el dato se encuentra en el subarbol derecho
    nodo->der=eliminar(nodo->der,v);
else{
    //En caso de que tenga un hijo o ninguno
    if(nodo->izq==nullptr||nodo->der==nullptr){
        Nodo* temp= nodo->izq ? //Si existe el nodo izquierdo, asignarlo a temp, de lo contrario, asignar el nodo derecho
                    nodo->izq:
                    nodo->der; 
    //En caso de que no tenga hijos
    if(temp==nullptr){
        temp=nodo;
        nodo=nullptr;
    }                
    else //En caso de que tenga un hijp
    *nodo=*temp;//Copiar el contenido del hijo 
    }
    else //En caso de que tenga dos hijos
    {
        Nodo* temp=minValor(nodo->der);
        nodo->dato=temp->dato;
        nodo->der=eliminar(nodo->der,temp->dato);
    } 
}
if(nodo==nullptr)
        return nodo;
//Actualizar altura del nodo
nodo->altura=1+max(calcularAltura(nodo->izq),calcularAltura(nodo->der));    
//Balancear el arbol    
int factorBalance =diferencia(nodo);

//Izquierda izquierda 
if(factorBalance>1 && v<nodo->izq->dato)
    return rotDerecha(nodo);
//Derecha derecha
if(factorBalance<-1 && v> nodo->der->dato)   
    return rotIzquierda(nodo);
//Izquierda derecha
if(factorBalance>1 && v> nodo->izq->dato){
    nodo->izq=rotIzquierda(nodo->izq);
    return rotDerecha(nodo);
}
//Derecha izquierda
if(factorBalance<-1 && v<nodo->der->dato){
    nodo->der=rotDerecha(nodo->der);
    return rotIzquierda(nodo);
}

return nodo;
}


public:
//Constructor
AVL ():raiz(nullptr){}

//Función pública de insertar
void insertar(int v){
    raiz=insertar(raiz,v);
}
//Función pública de eliminar
void eliminar(int v){
    raiz=eliminar(raiz,v);
}
//Función para imprimir en preOrder (No usada en la implementación)
void imprimirPreOrder(Nodo* raiz){
    if(raiz!=nullptr){
        cout<<raiz->dato<<" ";
        imprimirPreOrder(raiz->der);
        imprimirPreOrder(raiz->izq);
    }

}
//Función para imprimir en InOrder (No usada en la implementación)
void imprimirInOrder(Nodo* raiz){
    if(raiz!=nullptr){
        imprimirInOrder(raiz->izq);
        cout<<"("<<raiz->dato<<")-> ";
        imprimirInOrder(raiz->der);
    }

}
//Función para recorrer ciertos nodos del arbol en InOrder (Usada para calcular la mediana)
void recorrer(Nodo* raiz, double &limite, int &mediana1,int &mediana2){
if(raiz==nullptr){
    return;
}
recorrer(raiz->izq,limite,mediana1,mediana2);
limite--;//Se resta el límite cada vez que pasa por un nodo
if(limite==0){//Cuando llega al final
    mediana1=raiz->dato;//Asigna el dato a la mediana
    if(limite-(int)limite!=0){//Si el limite no es entero, es decir, el total de nodos es impar
        return;
    } 
}
if((limite-int(limite)==0) && limite==-1){ //Si el limite es entero y se llega a la posición siguiente de la mediana
    mediana2=raiz->dato;
    return;
 } 

  recorrer(raiz->der,limite,mediana1,mediana2);
        
}
//Función que calcula el tamaño total del arbol
int tamano(Nodo* raiz){
    if(raiz==nullptr){
       return 0;
    }
return 1+tamano(raiz->izq)+tamano(raiz->der);
}
//Getter para la raiz del arbol
Nodo* getRaiz(){
    return raiz;
}

};
void ingresarDatos(AVL &arbol);
void mediana(AVL &arbol);
#endif