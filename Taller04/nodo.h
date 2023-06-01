#ifndef nodo_h
#define nodo_h
#include <vector>

struct Coord{
    int x;
    int y;
};

class Nodo{
    private:
        Coord pInicial;
        Coord pFinal;
        int color;
        std::vector<Nodo> hijos;
    public:
        Nodo();
        Nodo(Coord pInicial, Coord pFinal, int color);
        void setSupIzq(int color);
        void setSupDer(int color);
        void setInfIzq(int color);
        void setInfDer(int color);      
        Nodo* getHijoSupIzq();
        Nodo* getHijoSupDer();
        Nodo* getHijoInfIzq();
        Nodo* getHijoInfDer();
        int encontrarCoordenada(Coord punto);  
        int getColor();
        void setColor(int color);
        Coord getPInicial();
        Coord getPFinal();
        void imprimir();
};


#endif