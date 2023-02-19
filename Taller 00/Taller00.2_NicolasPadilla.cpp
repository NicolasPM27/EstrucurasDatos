/*
Fecha: 19-02-2023
Versi�n: v_01;
Autor: Nicol�s Padilla

Problema:
   Se desea capturar los datos de los clientes para ser impreso en la factura.
   Se requiere crear una estructura de datos, que encapsule los datos de los usuarios.
   Se requiere que el uso de la estructura sea a trav�s de punteros.
   Se requiere imprimir las facturas en un fichero de texto.
Soluci�n:
    *Se har� un TDA para la captura de datos de los clientes.
    *Se har� un puntero que administre los datos de la TDA.
    *Se har� una funci�n que almacene todos los datos en un fichero de texto.
*/
#include <iostream>
#include <fstream>
#include <locale.h>
#include<string>

using namespace std;
//Estructura que almacena el nombre, apellido y documento del usuario
struct Usuario
{
    string nombre;
    string apellido;
    long documento;

};
void ingresar(Usuario *dirus);
void guardar(Usuario *dirus);
void crearus(Usuario *dirus);
long comprobarL();
//Contador que almacena la cantidad de facturas emitidas
//int con=0;

int main()
{
    setlocale(LC_CTYPE,"Spanish");//signos de puntuaci�n
    Usuario usuario, *dirus; //Estructura tipo usuario y contador a esta
    dirus= &usuario;
    crearus(dirus);
    return 0;
}
//Funci�n destinada a manejar el ingreso de datos y guardado en archivo
void crearus(Usuario *dirus)
{
    char opc; //Opcion que se elige en consola
    ingresar(dirus);
    guardar(dirus);
    do  //Ciclo destinado a guardar un nuevo usuario hasta que se desee
    {
        cout<<"\n�Desea ingresar un nuevo usuario? Y/N";
        cin>>opc;
        if(opc=='Y' ||opc=='y')
        {
            crearus(dirus);// funci�n recursiva
        }
        else if(opc=='N'||opc =='n')
        {
            cout<<"Saliendo del programa...";
            exit(0);//C�digo de salida con �xito
        }
        else
        {
            cout<<"Ingres� un d�gito incorrecto";
        }
    }
    while(opc!='Y'||opc !='y'||opc!='N'||opc!='n');

}
//Funci�n destinada a ingresar todos los datos del usuario
void ingresar(Usuario *dirus)
{
    cout<<"Ingrese el nombre del usuario:";
    cin>> (*dirus).nombre;
    cout<<"Ingrese el apellido del usuario:";
    cin>> (*dirus).apellido;
    cout<<"Ingrese el documento del usuario:";
    (*dirus).documento=comprobarL();

}
//Funci�n destinada a guardar todos los datos del usuario en un archivo de texto llamado "factura.txt"
void guardar(Usuario *dirus)
{
    int con=0; //Contador que aumenta cada vez que se genera una factura
    ofstream archivoE;//Ofstream para escribir
    ifstream archivoL;//Ifstream para leer
    string aux;
    archivoE.open("factura.txt",ios::app);//Crea el archivo si no existe, si existe, le hace append
    archivoL.open("factura.txt",ios::in);//Lee el archivo

    if(archivoE.fail()||archivoL.fail())//Condicional que cuida si el archivo falla
    {
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    //Cuenta la cantidad de veces que est� la palabra "FACTURA" para poner el n�mero serial al crear una nueva
    while(getline(archivoL,aux))
    {
        if(aux.find("FACTURA")==4)// el 4 corresponde a la posici�n de la palabra "FACTURA" en el archivo
        {
            con++;
        }
    }
    //Datos a escribir en el archivo de texto
    archivoE<<"--- FACTURA N�"<<con+1<<" -----\n";
    archivoE<<"Nombre: "<<(*dirus).nombre<<"\n";
    archivoE<<"Apellido: "<<(*dirus).apellido<<"\n";
    archivoE<<"Documento: "<<(*dirus).documento<<"\n";
    archivoL.close();
    archivoE.close();
    cout<<"Usuario guardado con �xito!! ";

}

long comprobarL()
{
    string num;
    long numero;
    cin>>num;
    for(int i=0; i<num.length(); i++)
    {
        if(!isdigit(num[i]))
        {
            cout<<"ERROR el dato ingresado debe ser un n�mero entero";
            comprobarL();
        }
    }
    numero= stol(num);
    return numero;
}


