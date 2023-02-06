/*
Fecha: 01 de Febrero del 2023
Versi�n: v2
Autor: Nicol�s Padilla Medina

Problema: 
	Se tiene un GYM en el cual se desea automatizar el registro de usuarios.
	Se sugiere que los datos solicitados sean exhaustivos 
	Se requiere saber la cantidad de hijos y los datos de edad de los hijos
	Se requiere que se impriman los nombres de los usuarios registrados satisfactoriamente.
	
Soluci�n:
	*Se har� un TDA para la captura de datos de usuarios.
	*Se har� un TDA anidado para la captura de datos de los hijos.
	*Se anunciar� expl�citamente cada acci�n/operaci�n a realizar.
*/
#include <iostream>
#include <locale.h>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

//TDA para captura de datos del cliente
struct Cliente {
 string nombre;
 int edad;
 long cedula;
 long celular;
 char genero;
 int peso;
 string direccion;
 int numhijos;
 //TDA para captura de datos de los hijos 
 struct Hijo{
 	int edad;
 	long documento;//char[10]
 };
 Hijo hijos[numhijos];
 string redsocial;
 string franhor;
};

char comprobarsexo(){
 char s;
 cin>>s;
 if(s=='M'||s=='F'){
    return s;
 }else {
    cout<<"Ha ingresado un valor incorrecto";
    comprobarsexo();
 }
}
int comprobar(){
 string num;
 int numero;
 cin>>num;
 for(int i=0;i<num.length();i++){
    if(!isdigit(num[i])){
        cout<<"ERROR el dato ingresado debe ser un n�mero entero";
        comprobar();
    }
 }
 stringstream aux(num);
 aux>>numero; 
 cout<<numero;
return numero;
}


long comprobarL(){
 string num;
 long numero;
 cin>>num;
 for(int i=0;i<num.length();i++){
    if(!isdigit(num[i])){
        cout<<"ERROR el dato ingresado debe ser un n�mero entero";
        comprobarL();
    }
}
 stringstream aux(num);
 aux>>numero; 
 cout<<numero;
 return numero;
 }



void ingresar(int num, Cliente c[]){
 string auxstring;
//Se hace un ciclo para ingresar datos del cliente
 for(int i=0;i<num;i++){
 	
    cout<<"Ingrese el nombre del cliente "<<i+1;
    cin>>c[i].nombre;
    cout<<"Ingrese la edad de "<<c[i].nombre;
    c[i].edad=comprobar();
    cout<<"Ingrese la cedula de "<<c[i].nombre;
    c[i].cedula=comprobarL();
    cout<<"Ingrese el n�mero de tel�fono de "<<c[i].nombre;
    c[i].celular=comprobarL();
    cout<<"Ingrese el g�nero de "<<c[i].nombre<< " (M para m�sculino, F para femenino)";
    c[i].genero=comprobarsexo();
    cout<<"Ingrese el peso en Kilogramos de "<<c[i].nombre;
    c[i].peso=comprobar();
    cout<<"Ingrese la direcci�n de "<<c[i].nombre;
    cin>>c[i].direccion;
    cout<<"Ingrese el n�mero de hijos de "<<c[i].nombre;
    cin>>c[i].numhijos;
    //Se hace una decisi�n para capturar la cantidad de hijos (Si tiene o no)
    if(c[i].numhijos>0){
    	for(int j=0;j<c[i].numhijos;j++){
			cout<<"Ingrese la edad del hijo "<<j+1;
    		cin>>c[i].hijos[j].edad;
    		cout<<"Ingrese el documento del hijo "<<j+1;
    		cin>>c[i].hijos[j].documento;
		}
	}
    /*c[i].hijos[c[i].numhijos];
    for(int j=0;j<c[i].hijos;j++){
		cout<<"a";
	}*/	
    cout<<"Ingrese la red social de "<<c[i].nombre;
    cin>>c[i].redsocial;
    cout<<"Ingrese la franja horaria de "<<c[i].nombre;
    cin>>c[i].franhor;
 }
}
void mostrar(int num,Cliente c[]){
//Ciclo para mostrar datos
for(int i=0;i<num;i++){
cout<<"Cliente "<<i+1<<":"<<"\nNombre: "<<c[i].nombre<<"\nEdad: "<<c[i].edad
<<"\nC�dula: "<<c[i].cedula<<"\nTel�fono: "<<c[i].celular
<<"\nG�nero: "<<c[i].genero<<"\nPeso: "<<c[i].peso<<"\nDirecci�n: "<<c[i].direccion
<<"\nN�mero de Hijos: "<<c[i].numhijos<<"\nRed Social: "<<c[i].redsocial
<<"\nFranja Horaria: "<<c[i].franhor;
cout<<"\n--------------------------\n";
}
}
int main ()
{
setlocale(LC_CTYPE,"Spanish");//signos de puntuaci�n
int num;
//Se presenta la bienvenida
cout<<"------BIENVENIDO AL SISTEMA DE ALMACENAMIENTO DE DATOS---------\n";
//se pregunta el n�mero de clientes a ingresar
cout<<"Ingrese el n�mero de clientes a ingresar";
cin>>num;
//Se crea un arreglo de clientes de tama�o seg�n lo ingresado anteriormente
struct Cliente c[num];
//Se va a la funci�n destinada a insertar los datos de los clientes
ingresar(num,c);
//Se va a la funci�n destinada a mostrar los datos de los clientes
mostrar(num,c);

return 0;
}
