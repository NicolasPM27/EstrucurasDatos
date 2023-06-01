#ifndef quatTree_h
#define quatTree_h

#include "nodo.h"


class QuadTree{
    private:
        Nodo raiz;
    public:
        QuadTree();
        QuadTree(Coord pInicial, Coord pFinal, int color);
        void ImprimirArbol(char* nombreArchivo); 
        void LlenarArbol(char* nombreArchivo);     
};


#endif