#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stack>
#include "quadTree.h"

QuadTree::QuadTree(){//Constructor por defecto
    this->raiz = Nodo();
}

QuadTree::QuadTree(Coord pInicial, Coord pFinal, int color){//Constructor con parametros
    this->raiz = Nodo(pInicial, pFinal, color);
}

// Imprime el arbol en un archivo .pbm
void QuadTree::ImprimirArbol(char* nombreArchivo) {//Imprime el arbol en un archivo .pbm
    std::cout << "Creando archivo..." << std::endl;
    std::ofstream file(nombreArchivo, std::ios::out);
    Coord pInicial = this->raiz.getPInicial();
    Coord pFinal = this->raiz.getPFinal();
    Coord pActual;
    int color;
    if (file.is_open()) {  
        std::cout << "Abriendo archivo..." << std::endl;
        file << "P1" << std::endl;
        file << "# Image Created by QuadTree" << std::endl;  
        file << pFinal.x+1 << " " << pFinal.y+1 << std::endl;    
        for(int y = pFinal.y; y >= 0; y--){
            for(int x = 0; x <= pFinal.x; x++){ 
                pActual.x = x;
                pActual.y = y;
                color = this->raiz.encontrarCoordenada(pActual);
                file << color;
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Archivo creado." << std::endl;
    }
}

// Llena el arbol con los datos del archivo .qt
void QuadTree::LlenarArbol(char* nombreArchivo) {
    std::ifstream file(nombreArchivo);
    char character;
    int coordenadaW, coordenadaH;
    std::stack<Nodo*> pila;
    pila.push(new Nodo());
    Nodo* nodoActual;
    Coord pInicial, pFinal;
    pInicial.x = 0;
    pInicial.y = 0;
    if (file.is_open()) {
        if (file >> coordenadaW) {
            std::cout << "Width size: "<<coordenadaW << std::endl;
        }
        if (file >> coordenadaH) {
            std::cout << "Height size: "<<coordenadaH << std::endl;
        }
        pFinal.x = coordenadaW-1;
        pFinal.y = coordenadaH-1;
        this->raiz = Nodo(pInicial, pFinal, -1);
        nodoActual = &this->raiz;
        while (file.get(character)) {   
            if(!isdigit(character)){
                continue;
            }
            if(nodoActual->getColor() == -1){
                nodoActual->setColor(atoi(&character));
                continue;
            }else{
                if(nodoActual->getColor() == 2) {
                    if(pila.top()!=nodoActual)
                        pila.push(nodoActual);
                    if(nodoActual->getHijoSupIzq() == nullptr){
                        nodoActual->setSupIzq(-1);
                        nodoActual = nodoActual->getHijoSupIzq();
                    }else if(nodoActual->getHijoSupDer() == nullptr){
                        nodoActual->setSupDer(-1);
                        nodoActual = nodoActual->getHijoSupDer();
                    }else if(nodoActual->getHijoInfDer() == nullptr){
                        nodoActual->setInfDer(-1);
                        nodoActual = nodoActual->getHijoInfDer();
                    }else if(nodoActual->getHijoInfIzq() == nullptr){
                        nodoActual->setInfIzq(-1);
                        nodoActual = nodoActual->getHijoInfIzq();
                    }
                }else {
                    while(true) {
                        nodoActual = pila.top();
                        if(nodoActual->getHijoSupIzq() == nullptr){
                            nodoActual->setSupIzq(-1);
                            nodoActual = nodoActual->getHijoSupIzq();
                            break;
                        }else if(nodoActual->getHijoSupDer() == nullptr){
                            nodoActual->setSupDer(-1);
                            nodoActual = nodoActual->getHijoSupDer();
                            break;
                        }else if(nodoActual->getHijoInfDer() == nullptr){
                            nodoActual->setInfDer(-1);
                            nodoActual = nodoActual->getHijoInfDer();
                            break;
                        }else if(nodoActual->getHijoInfIzq() == nullptr){
                            nodoActual->setInfIzq(-1);
                            nodoActual = nodoActual->getHijoInfIzq();
                            break;
                        }else{
                            pila.pop();
                            continue;
                        }
                    }
                }         
                nodoActual->setColor(atoi(&character));
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "No se pudo abrir el archivo.\n";
    }
}




