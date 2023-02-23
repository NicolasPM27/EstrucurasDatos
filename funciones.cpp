#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include<vector>
#include <locale.h>
#include "funciones.h"
using namespace std;

//Función para llenar las listas de autor y álbum
Cancion llenarcan(string linea, vector<int> pos)
{
    Cancion auxc;
    auxc.nombre=linea.substr(0,pos[0]-1);
    auxc.genero=linea.substr(pos[1],pos[2]-pos[1]-1);
    auxc.ano= stoi(linea.substr(pos[3],(pos[3]+4)));
    return auxc;
}
//Función dedicada a llenar la lista de autores
list<Autor> llenarAutores()
{
    list<Autor> autores;//Lista donde se van a almacenar todos los autores.
    ifstream archivo;
    string linea;
    archivo.open("example3.txt",ios::in);

    if(archivo.fail())
    {
        cerr<<"Error abriendo archivo";
    }
    if(archivo.is_open())//Se salta la linea con el número
    {
        getline(archivo,linea);
    }

    while(getline(archivo, linea))//Leer linea por linea
    {
        int index = 0;
        vector <int> pos;
        while ((index = linea.find("|", index)) != string::npos)//Busca las posiciones de cada '|' en un vector
        {
            pos.push_back(index+1);//Las ingresa en un vector
            index ++;
        }
        list<Autor>::iterator it_autor=autores.begin();//Iterador tipo autor que recorre la lista
        string nombre=linea.substr(pos[0], pos[1]-pos[0]-1);//nombre del autor
        bool esta=false;//Booleano que cuida que esté el autor en la lista de autores
        while(it_autor!=autores.end())
        {
            if(it_autor->nombre==nombre)//Si existe el autor en la lista, deja el apuntador en esa posición
            {
                esta=true;
                break;
            }
            it_autor++;
        }
        if(esta)
        {
            Cancion auxc=llenarcan(linea,pos);
            it_autor->v.push_back(auxc);//Si está, agrega la canción a la lista de canciones del autor
        }
        else
        {
            Cancion auxc=llenarcan(linea,pos);
            Autor auxa;
            auxa.nombre=nombre;
            auxa.v.push_back(auxc);//Si no está, crea un nuevo autor y le agrega la canción
            autores.push_back(auxa);
        }
    }
    archivo.close();
    return autores;
}
list<Album> llenarAlbumes()//Misma lógica que la función de llenarAutores
{
    ifstream archivo;
    string linea;
    archivo.open("example3.txt",ios::in);

    if(archivo.fail())
    {
        cerr<<"Error abriendo archivo";
    }
    if(archivo.is_open())
    {
        getline(archivo,linea);
    }
    list<Album> albumes;

    while(getline(archivo, linea))
    {
        int index = 0;
        vector <int> pos;
        while ((index = linea.find("|", index)) != string::npos)
        {
            pos.push_back(index+1);
            index ++;
        }
        list<Album>::iterator it_album=albumes.begin();
        string nombre=linea.substr(pos[2], pos[3]-pos[2]-1);
        bool esta=false;
        while(it_album!=albumes.end())
        {
            if(it_album->nombre==nombre)
            {
                esta=true;
                break;
            }
            it_album++;
        }
        if(esta)
        {
            Cancion auxc=llenarcan(linea,pos);
            it_album->vc.push_back(auxc);
        }
        else
        {
            Cancion auxc=llenarcan(linea,pos);
            Album auxa;
            auxa.nombre=nombre;
            auxa.ano=stoi(linea.substr(pos[3],(pos[3]+4)));
            auxa.vc.push_back(auxc);
            albumes.push_back(auxa);
        }
    }
    archivo.close();
    return albumes;
}
//Funciones de comparación, utilizadas por la función sort()
bool comparara(const Autor& a, const Autor& b)
{
    return a.nombre<b.nombre;
}
bool compararc(const Cancion& a, const Cancion& b )
{
    return a.nombre<b.nombre;
}
bool compararal(const Album& a, const Album& b)
{
    return a.nombre<b.nombre;
}
bool compararalcron(const Album& a, const Album& b)
{
    return a.ano<b.ano;
}
//Listar Autores por orden alfabetico
void op1(list<Autor>& autores)
{
    autores.sort(comparara);//Ordena los autores con la función de comparación
    for (const auto& autor : autores)
    {
        cout << "Autor: " << autor.nombre << endl;
    }
}
void op2(list<Autor>& autores, string nombre)
{
    bool existe=false;//Booleano que cuida que el nombre ingresado si exista
    for ( auto& autor : autores)
    {

        if(nombre.compare(autor.nombre)==0)
        {
            cout << "Autor: " << autor.nombre << endl;
            autor.v.sort(compararc);
            for (  auto& cancion : autor.v)
            {
                existe=true;
                cout << "\tCancion: " << cancion.nombre <<" de género "<<cancion.genero<<" del año "<<cancion.ano<<"\n";
            }
        }
    }
    if(!existe) cout<<"No existe un autor con el nombre:"<<nombre;
}
void op3(list<Album>& albumes )
{
    albumes.sort(compararalcron);
    for (const auto& album : albumes)
    {
        cout << "Álbum: " << album.nombre << " del año "<<album.ano<<endl;
    }
}
void op4(list<Album>& albumes, string nombre)
{
    bool existe=true;
    for ( auto& album : albumes)
    {

        if(nombre.compare(album.nombre)==0)
        {
            cout << "Álbum: " << album.nombre << endl;
            album.vc.sort(compararc);
            for (  auto& cancion : album.vc)
            {
                existe=true;
                cout << "\tCancion: " << cancion.nombre <<" de género "<<cancion.genero<<" del año "<<cancion.ano<<"\n";
            }
        }
    }
    if(!existe) cout<<"No existe un álbum con el nombre:"<<nombre;
}
void op5(list<Album>& albumes)
{
    albumes.sort(compararal);
    for ( auto& album : albumes)
    {
        cout << "Album: " << album.nombre << endl;
        album.vc.sort(compararc);
        for (  auto& cancion : album.vc)
        {
            cout << "\tCancion: " << cancion.nombre <<" de género "<<cancion.genero<<" del año "<<cancion.ano<<"\n";
        }
    }
}

