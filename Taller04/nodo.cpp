#include <stdio.h>
#include <iostream>
#include "nodo.h"


Nodo::Nodo(){//Constructor por defecto
    this->pInicial.x = 0;
    this->pInicial.y = 0;
    this->pFinal.x = 0;
    this->pFinal.y = 0;
    this->color = 2;
}

Nodo::Nodo(Coord pInicial, Coord pFinal, int color){//Constructor con parametros
    this->pInicial.x = pInicial.x;
    this->pInicial.y = pInicial.y;
    this->pFinal.x = pFinal.x;
    this->pFinal.y = pFinal.y;
    this->color = color;
}

void Nodo::setSupIzq(int color){//Crea el hijo superior izquierdo
    Coord pInicial;
    Coord pFinal;
    pInicial.x = this->pInicial.x;
    pInicial.y = ((this->pInicial.y + this->pFinal.y) / 2) + 1;
    pFinal.x = (this->pInicial.x + this->pFinal.x) / 2;
    pFinal.y = this->pFinal.y;
    Nodo hijo(pInicial, pFinal, color);
    this->hijos.push_back(hijo);
}

void Nodo::setSupDer(int color) {//Crea el hijo superior derecho
    Coord pInicial;
    Coord pFinal;
    pInicial.x = ((this->pInicial.x + this->pFinal.x) / 2) + 1;
    pInicial.y = ((this->pInicial.y + this->pFinal.y) / 2) + 1;
    pFinal.x = this->pFinal.x;
    pFinal.y = this->pFinal.y;
    Nodo hijo(pInicial, pFinal, color);
    this->hijos.push_back(hijo);
}

void Nodo::setInfDer(int color) {//Crea el hijo inferior derecho
    Coord pInicial;
    Coord pFinal;
    pInicial.x = ((this->pInicial.x + this->pFinal.x) / 2) + 1;
    pInicial.y = this->pInicial.y;
    pFinal.x = this->pFinal.x;
    pFinal.y = (this->pInicial.y + this->pFinal.y) / 2;
    Nodo hijo(pInicial, pFinal, color);
    this->hijos.push_back(hijo);
}

void Nodo::setInfIzq(int color) {//Crea el hijo inferior izquierdo
    Coord pInicial;
    Coord pFinal;
    pInicial.x = this->pInicial.x;
    pInicial.y = this->pInicial.y;
    pFinal.x = (this->pInicial.x + this->pFinal.x) / 2;
    pFinal.y = (this->pInicial.y + this->pFinal.y) / 2;
    Nodo hijo(pInicial, pFinal, color);
    this->hijos.push_back(hijo);
}

Nodo* Nodo::getHijoSupIzq() {//Retorna el hijo superior izquierdo
    if(this->hijos.size() <= 0)
        return nullptr;
    else
        return &this->hijos[0];
}

Nodo* Nodo::getHijoSupDer() {//Retorna el hijo superior derecho
    if(this->hijos.size() <= 1)
        return nullptr;
    else
        return &this->hijos[1];
}

Nodo* Nodo::getHijoInfDer() {//Retorna el hijo inferior derecho
    if(this->hijos.size() <= 2)
        return nullptr;
    else
        return &this->hijos[2];
}

Nodo* Nodo::getHijoInfIzq() {//Retorna el hijo inferior izquierdo
    if(this->hijos.size() <= 3)
        return nullptr;
    else
        return &this->hijos[3];
}

int Nodo::getColor() {//Retorna el color del nodo
    return this->color;
}

void Nodo::setColor(int color) {//Cambia el color del nodo
    this->color = color;
}

int Nodo::encontrarCoordenada(Coord punto) {//Retorna el color del nodo en la coordenada dada    
    if(this->color != 2) {
        return this->color;
    }else{
        if (punto.x >= this->pInicial.x && punto.x <= (this->pInicial.x + this->pFinal.x) / 2 && punto.y > (this->pInicial.y + this->pFinal.y) / 2 && punto.y <= this->pFinal.y) {
            return this->getHijoSupIzq()->encontrarCoordenada(punto);
        }
        else if (punto.x > (this->pInicial.x + this->pFinal.x) / 2 && punto.x <= this->pFinal.x && punto.y > (this->pInicial.y + this->pFinal.y) / 2 && punto.y <= this->pFinal.y) {
            return this->getHijoSupDer()->encontrarCoordenada(punto);
        }
        else if (punto.x > (this->pInicial.x + this->pFinal.x) / 2 && punto.x <= this->pFinal.x && punto.y >= this->pInicial.y && punto.y <= (this->pInicial.y + this->pFinal.y) / 2) {
            return this->getHijoInfDer()->encontrarCoordenada(punto);
        }
        else if (punto.x >= this->pInicial.x && punto.x <= (this->pInicial.x + this->pFinal.x) / 2 && punto.y >= this->pInicial.y && punto.y <= (this->pInicial.y + this->pFinal.y) / 2) {
            return this->getHijoInfIzq()->encontrarCoordenada(punto);
        }
        else {
            return -1;
        }
    }
}

Coord Nodo::getPInicial() {//Retorna la coordenada inicial del nodo
    return this->pInicial;
}

Coord Nodo::getPFinal() {//Retorna la coordenada final del nodo
    return this->pFinal;
}

void Nodo::imprimir() {//Imprime el arbol
    std::cout<< this->color <<std::endl;
    for(int i = 0; i<4 ; i++){
        if(this->hijos[i].getColor() == 2)
            this->hijos[i].imprimir();
        else{
            std::cout<< this->hijos[i].getColor() <<std::endl;
        }
    }
}