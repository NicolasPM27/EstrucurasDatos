#include "clases.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

// DECLARACIÓN DE CLASES
// --------------------------------------------------------------------------------------

// Los enteros pueden cambiarse por float
// elementos = obstaculos

//-----------------------Elemento----------------------------------------------
  void elemento::fijarTipoElemento(string tipo_elemento) {
    this->tipo_elemento = tipo_elemento;
  }
  void elemento::fijarTamano(int tamano) { this->tamano = tamano; }
  void elemento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }
  void elemento::fijarCoordenada_x(int coordenada_x) {
    this->coordenada_x = coordenada_x;
  }
  void elemento::fijarCoordenada_y(int coordenada_y) {
    this->coordenada_y = coordenada_y;
  }

  // Getters
  string elemento::obtenerTipoElemento() { return tipo_elemento; }
  int elemento::obtenerTamano() { return tamano; }
  string elemento::obtenerUnidadmedida() { return unidad_medida; }
  int elemento::obtenerCoordenada_x() { return coordenada_x; }
  int elemento::obtenerCoordenada_y() { return coordenada_y; }


//-----------------------Movimiento----------------------------------------------
  void movimiento::fijarTipo_movimiento(string tipo_movimiento) {
    this->tipo_movimiento = tipo_movimiento;
  }
  void  movimiento::fijarMagnitud(float magnitud) { this->magnitud = magnitud; }
  void  movimiento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }

  // Getters
  string  movimiento::obtenerTipo_movimiento() { return tipo_movimiento; }
  float  movimiento::obtenerMagnitud() { return magnitud; }
  string  movimiento::obtenerUnidadMedida() { return unidad_medida; }


//-----------------------Analisis----------------------------------------------
  void analisis::fijarTipo_analisis(string tipo_analisis) {
    this->tipo_analisis = tipo_analisis;
  }
  void analisis::fijarObjeto(string objeto) { this->objeto = objeto; }
  void analisis::fijarComentario(string comentario) { this->comentario = comentario; }

  // Getters
  string analisis::obtenerTipo_analisis() { return tipo_analisis; }
  string analisis::obtenerObjeto() { return objeto; }
  string analisis::obtenerComentario() { return comentario; }


//-----------------------Curiosity----------------------------------------------
  // Setters
  void Curiosity::fijarElementos(const list<elemento> &newElementos) {
    elementos = newElementos;
  }
  void Curiosity::fijarListaMovimientos(const list<movimiento> &newListaMovimientos) {
    listaMovimientos = newListaMovimientos;
  }
  void Curiosity::fijarListaAnalisis(const list<analisis> &newListaAnalisis) {
    listaAnalisis = newListaAnalisis;
  }

  // Getters
  list<elemento> Curiosity::obtenerElementos() { return elementos; }
  list<movimiento> Curiosity::obtenerListaMovimientos() const { return listaMovimientos; }
  list<analisis> Curiosity::obtenerListaAnalisis() const { return listaAnalisis; }
  //Métodos
  void Curiosity::agregarElemento(elemento auxEle){
    elementos.push_back(auxEle);
  }
void Curiosity::agregarMovimiento(movimiento auxMov){
    listaMovimientos.push_back(auxMov);
  }
void Curiosity::agregarAnalisis(analisis auxAna){
    listaAnalisis.push_back(auxAna);
  }

  list<elemento>::iterator Curiosity::getElementoBegin() {
    return elementos.begin();
  }
  list<elemento>::iterator Curiosity::getElementoEnd() {
    return elementos.end();
  }

  list<analisis>::iterator Curiosity::getAnalisisBegin() {
    return listaAnalisis.begin();
  }
  list<analisis>::iterator Curiosity::getAnalisisEnd() {
    return listaAnalisis.end();
  }

  list<movimiento>::iterator Curiosity::getMovimientoBegin() {
    return listaMovimientos.begin();
  }
  list<movimiento>::iterator Curiosity::getMovimientoEnd() {
    return listaMovimientos.end();
  }

//-----------------------Rectangulo----------------------------------------------
int Rectangulo::contador=0;

  Rectangulo::Rectangulo(int x1, int x2, int y1, int y2, string t){
      xmin = x1;
      xmax = x2;
      ymin = y1;
      ymax = y2;
      tipo = t;
      indice=contador++;
 }
  void Rectangulo::fijarXmin(int x1){
    xmin = x1;
  }
  void Rectangulo::fijarXmax(int x2){
    xmax = x2;
  }
  void Rectangulo::fijarYmin(int y1){
    ymin = y1;
  }
  void Rectangulo::fijarYmax(int y2){
    ymax = y2;
  }
  void Rectangulo::fijarTipo(string t){
    tipo = t;
  }
  int Rectangulo::obtenerXmin(){
    return xmin;
  }
  int Rectangulo::obtenerXmax(){
    return xmax;
  }
  int Rectangulo::obtenerYmin(){
    return ymin;
  }
  int Rectangulo::obtenerYmax(){
    return ymax;
  }
  string Rectangulo::obtenerTipo(){
    return tipo;
  }
  int Rectangulo::obtenerIndice(){
    return indice;
  }
//Función de intersección
  bool Rectangulo::intersecta(const Rectangulo& o) {
        if (xmax < o.xmin || o.xmax < xmin) {//Si no se intersectan en x
            return false;
        }
        if (ymax < o.ymin || o.ymax < ymin) {//Si no se intersectan en y
            return false;
        }
        return true;
    }
  //Función de contención  
    bool Rectangulo::contiene(const Rectangulo& o){
        if(o.xmin >= xmin && o.xmax <= xmax && o.ymin >= ymin && o.ymax <= ymax){//Si el rectángulo o está dentro de this
            return true;
        }

        return false;
  }

   //-----------------------Nodo---------------------------------------------- 


    Nodo::Nodo(Rectangulo *o){
        obstaculo = o;
        izq = NULL;
        der = NULL;
    }

    Nodo::~Nodo(){
        delete obstaculo;
        delete izq;
        delete der;
    }
    //Setters
    void Nodo::fijarObstaculo(Rectangulo *o){
        obstaculo = o;
    }
    void Nodo::fijarIzq(Nodo *n){
        izq = n;
    }
    void Nodo::fijarDer(Nodo *n){
        der = n;
    }
    Rectangulo* Nodo::obtenerObstaculo(){
        return obstaculo;
    }
    //Getters
    Nodo* Nodo::obtenerIzq(){
        return izq;
    }
    Nodo* Nodo::obtenerDer(){
        return der;
    }
    Nodo* &Nodo::obtenerIzqRef(){
        return izq;
    }
    Nodo* &Nodo::obtenerDerRef(){
        return der;
    }
    //-----------------------KDTree---------------------------------------------- 


    KDTree::KDTree(){
        raiz = NULL;
    }
    KDTree::~KDTree(){
        delete raiz;
    }
    //Getter
    void KDTree::fijarRaiz(Nodo *n){
        raiz = n;
    }
    //Setter
    Nodo* KDTree::obtenerRaiz(){
        return raiz;
    }
    //Función pública de inserción
    bool KDTree::insertar(Rectangulo *o){
        if(insertar(o, raiz, true)){
            return true;
        }else
            return false;    
    }
    //Función para contar la cantidad de nodos
    int KDTree::contarNodos(){
        return contarNodos(raiz);
    }
    //Función pública de búsqueda
    bool KDTree::buscar(Rectangulo *rect){
      bool hayUno=false;
      return buscar(raiz, rect, hayUno);
    }
    //Función privada de inserción
    bool KDTree::insertar(Rectangulo *o, Nodo *&nodo, bool eje){
        if(nodo == NULL){
            nodo = new Nodo(o);
            return true;
        }else{
            if(nodo->obtenerObstaculo()->intersecta(*o)){//Si el obstaculo a insertar intersecta con el nodo actual(Ya hay un obstaculo en esas coordenadas)
                return false;
            }
            if(eje){//Si el eje es x
                if(o->obtenerXmin() < nodo->obtenerObstaculo()->obtenerXmin()){//Si el obstaculo a insertar tiene xmin menor que el nodo actual
                    insertar(o, nodo->obtenerIzqRef(), !eje);//Se inserta en el subarbol izquierdo y se cambia el eje
                }else{
                    insertar(o, nodo->obtenerDerRef(), !eje);//Se inserta en el subarbol derecho y se cambia el eje
                }
            }else{//Si el eje es y
                if(o->obtenerYmin() < nodo->obtenerObstaculo()->obtenerYmin()){//Si el obstaculo a insertar tiene ymin menor que el nodo actual
                    insertar(o, nodo->obtenerIzqRef(), !eje);//Se inserta en el subarbol izquierdo y se cambia el eje
                }else{
                    insertar(o, nodo->obtenerDerRef(), !eje);//Se inserta en el subarbol derecho y se cambia el eje
                }
            }
        }
    }
    //Función privada de búsqueda, recorre el árbol inorden y compara si el obstaculo del nodo está en el rectángulo(Cuadrante)
    bool KDTree::buscar(Nodo *nodo, Rectangulo *rect, bool &hayUno){
        if(nodo == NULL){
          return false;
        }
             buscar(nodo->obtenerIzq(), rect,hayUno);//Se busca en el subarbol izquierdo
            if(rect->intersecta(*nodo->obtenerObstaculo())){//Si el cuadrante contiene al obstaculo
              cout<<"Elemento:"<<nodo->obtenerObstaculo()->obtenerTipo()
              <<" \nCoordenadas: ("<<nodo->obtenerObstaculo()->obtenerXmin()<<","<<nodo->obtenerObstaculo()->obtenerYmin()<<"),("
              <<nodo->obtenerObstaculo()->obtenerXmax()<<","<<nodo->obtenerObstaculo()->obtenerYmax()<<")\n";
              hayUno=true;
              }
             buscar(nodo->obtenerDer(), rect,hayUno);//Se busca en el subarbol derecho
            return hayUno;
        }

    //Función pública de vacío
   bool KDTree::vacio(){
        if(raiz == NULL){
            return true;
        }else{
            return false;;
        }
    }
    //Función privada de contar nodos
    int KDTree::contarNodos(Nodo *nodo){
        if(nodo == NULL){
            return 0;
        }else{
            return 1 + contarNodos(nodo->obtenerIzq()) + contarNodos(nodo->obtenerDer());
        }
    }
    //Función publica de arbolAVector
    void KDTree::arbolAVector(vector<Rectangulo*> &v){
    arbolAVector(raiz, v);    
    }
    //Función privada de arbolAVector
    void KDTree::arbolAVector(Nodo *nodo, vector<Rectangulo*> &v){
        if(nodo == NULL){
            return ;
        }else{
            arbolAVector(nodo->obtenerIzq(), v);
            v.push_back(nodo->obtenerObstaculo());
            arbolAVector(nodo->obtenerDer(), v);
        }
    }


//------------------------------Tercer componente--------------------------------------------
Grafo::Grafo(vector<Arista> const &aristas, int n){
  //cambiar el tamaño de la lista de adyacencia para que se ajuste al número de vértices
  listaAdyacencia.resize(n);
  //agregar aristas al grafo no dirigido
  for (auto &arista: aristas){
    int inicio = arista.inicio->obtenerIndice();
    int dest =arista.dest->obtenerIndice();
    double peso = arista.peso;
    //Insertar al final de la lista
    //cout<<"inicio: "<<arista.inicio->obtenerTipo()<<inicio<<"dest: "<<dest<<"peso: "<<peso<<endl;
    listaAdyacencia[inicio].push_back(make_pair(*(arista.dest), peso));
  }
}
//Definir infinito como un valor grande
const double INF = 1e15;

  void Grafo::rutaMasLarga(Grafo const &Grafo, int n){
  //Algoritmo para hallar la ruta más larga entre todos los nodos en todo el grafo
  //Se crea un vector de distancias y un vector de visitados
  vector<double> distancia(n, INF);
  vector<bool> visitado(n, false);
  //Se crea una cola de prioridad para almacenar los nodos visitados
  priority_queue< Pair, vector <Pair> , greater<Pair> > pq;
  //Se inserta el nodo inicial con distancia 0
  pq.push(make_pair(0, 0));
  distancia[0] = 0;
  //Se itera hasta que la cola de prioridad esté vacía
  while (!pq.empty()){
    //Se extrae el nodo con menor distancia
    int u = pq.top().second;
    pq.pop();
    //Se marca el nodo como visitado
    visitado[u] = true;
    //Se itera sobre los nodos adyacentes
    for (Pair v: listaAdyacencia[u]){
      //Se obtiene el índice del nodo adyacente
      int indice = v.first.obtenerIndice();
      //Se obtiene el peso de la arista
      double peso = v.second;
      //Si el nodo no ha sido visitado y la distancia es menor a la actual
      if (!visitado[indice] && distancia[indice] > distancia[u] + peso){
        //Se actualiza la distancia
        distancia[indice] = distancia[u] + peso;
        //Se inserta el nodo en la cola de prioridad
        pq.push(make_pair(distancia[indice], indice));
      }
    }
  }
  //Se imprime la distancia más larga
  cout<<"La distancia más larga es: "<<distancia[n-1]<<endl;
}

  void Grafo::imprimirGrafo(Grafo const &grafo, int n){//Función que imprime el grafo
  for (int i = 0; i < n; i++){
    cout<<"Nodo "<<i<<":\n";
    for (Pair v: grafo.listaAdyacencia[i]){
     cout<<"("<< v.first.obtenerIndice() <<") ," << v.first.obtenerTipo() << v.second<< ")\t";
    }
    cout << endl;
  }
}   



