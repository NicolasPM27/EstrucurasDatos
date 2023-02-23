#ifndef funciones_h
#define funciones_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include<vector>
#include <locale.h>

using namespace std;
struct Album;
struct Cancion;

struct Autor
{
    string nombre;
    list<Cancion> v;
};

struct Album
{
    string nombre;
    list<Cancion> vc;
    int ano;
};
struct Cancion
{
    string nombre;
    string genero;
    int ano;

};

Cancion llenarcan(string linea, vector<int> pos);
list<Autor> llenarAutores();
list<Album> llenarAlbumes();
bool comparara(const Autor& a, const Autor& b);
bool compararc(const Cancion& a, const Cancion& b );
bool compararal(const Album& a, const Album& b);
bool compararalcron(const Album& a, const Album& b);
void op1(list<Autor>& autores);
void op2(list<Autor>& autores, string nombre);
void op3(list<Album>& albumes );
void op4(list<Album>& albumes, string nombre);
void op5(list<Album>& albumes);

#endif