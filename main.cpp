#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include<vector>
#include <locale.h>
#include "funciones.h"
using namespace std;
int main()
{
    setlocale(LC_CTYPE,"Spanish");//signos de puntuación
    list<Autor>autores =llenarAutores();
    list<Album> albumes =llenarAlbumes();
    string nom;//Parametro que se ingresa al solicitar el nombre de autor o álbum
    int op;//Opcion que elige el usuario
    do
    {
        cout<<"\n-----------BIENVENIDO A JAVEMUSIC------------\n";
        cout<<"1. Mostrar todos los autores presentes\n2. Listar todas las canciones de un autor\n3. Listar todos los álbumes presentes\n"
            << "4. Listar todas las canciones de un álbum\n5. Listar todas las canciones de todos los álbumes\n0. Salir\nIngrese una opción";
        cin>>op;
        switch(op)
        {
        case 0:
            cout<<"Gracias, hasta pronto";
            break;
        case 1:
            op1(autores);
            break;
        case 2:
            cout<<"Ingrese el nombre del autor ";
            cin>>nom;
            op2(autores,nom);
            break;
        case 3:
            op3(albumes);
            break;
        case 4:
            cout<<"Ingrese el nombre del álbum ";
            cin>>nom;
            op4(albumes,nom);
            break;
        case 5:
            op5(albumes);
            break;
        default:
            cout<<"Ingresó una opción inválida";
        }
    }
    while(op!=0);

    return 0;
}