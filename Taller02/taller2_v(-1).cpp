#include <iostream>
#include <vector>

using namespace std;
struct Album;
struct Cancion;

struct Autor
{
    string nombre;
    vector<Cancion> v;
};

struct Album
{
    string nombre;
    Autor a;
    vector<Cancion> vc;
};
struct Cancion
{
    string nombre;
    Autor autor;
    string genero;
    Album album;
    int ano;
    int duracion;
    int calificacion;

};
#include <fstream>
#include <sstream>

// Función para llenar los datos de un archivo de texto en las estructuras dadas
void llenarDatos(string archivo, vector<Cancion>& canciones, vector<Autor>& autores, vector<Album>& albums)
{
    ifstream infile(archivo); // Abrir el archivo para lectura
    string linea;
    while (getline(infile, linea)) { // Leer línea por línea del archivo
        stringstream ss(linea);
        string cancion, autor, genero, album, ano_str;
        getline(ss, cancion, '|'); // Leer los datos separados por |
        getline(ss, autor, '|');
        getline(ss, genero, '|');
        getline(ss, album, '|');
        getline(ss, ano_str, '|');

        // Convertir el año a un entero
        int ano = stoi(ano_str);

        // Buscar si el autor ya existe en el vector de autores
        Autor* autor_ptr = nullptr;
        for (auto& a : autores) {
            if (a.nombre == autor) {
                autor_ptr = &a;
                break;
            }
        }

        // Si no existe, crear un nuevo autor y agregarlo al vector
        if (autor_ptr == nullptr) {
            autores.push_back({ autor, {} });
            autor_ptr = &autores.back();
        }

        // Buscar si el album ya existe en el vector de albums
        Album* album_ptr = nullptr;
        for (auto& a : albums) {
            if (a.nombre == album) {
                album_ptr = &a;
                break;
            }
        }

        // Si no existe, crear un nuevo album y agregarlo al vector
        if (album_ptr == nullptr) {
            albums.push_back({ album, *autor_ptr, {}, {} });
            album_ptr = &albums.back();
            autor_ptr->v.push_back(*album_ptr);
        }

        // Crear una nueva canción y agregarla al vector de canciones, el vector de canciones del autor y el vector de canciones del album
        canciones.push_back({ cancion, *autor_ptr, genero, *album_ptr, ano, 0, 0 });
        autor_ptr->v.back().vc.push_back(canciones.back());
        album_ptr->vc.push_back(canciones.back());
    }
}

int main()
{

    return 0;
}
