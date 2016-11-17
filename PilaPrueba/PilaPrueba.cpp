#include <iostream>
#include "PilaPrueba.h"
using namespace std;

PilaPrueba::PilaPrueba() : primero(0){}

PilaPrueba::~PilaPrueba(){
    vaciar();
}

void PilaPrueba::crear(){
    primero = 0;
}

void PilaPrueba::destruir(){
    while(!vacia()){
        quitar();
    }
}

void PilaPrueba::vaciar(){
    while(!vacia()){
        quitar();
    }
}

bool PilaPrueba::vacia(){
    if(primero == 0)
        return 1;
    return 0;
}

void PilaPrueba::poner(int elemento){
    if(primero == 0){
        CajitaPilaP* auxiliarPrimero = new CajitaPilaP(elemento);
        primero = auxiliarPrimero;
    }
    else{
        CajitaPilaP* nuevoPrimero = new CajitaPilaP(elemento);
        nuevoPrimero->setSiguiente(primero);
        primero = nuevoPrimero;
    }
}

void PilaPrueba::quitar(){
    CajitaPilaP* auxiliar = primero;
    if(auxiliar->getSiguiente() != 0){
        primero = primero->getSiguiente();
    }
    else{
        primero = 0;
    }
    delete auxiliar;
}

int PilaPrueba::tope(){
    return primero->getElemento();
}

void PilaPrueba::recorrer(){
    if(!vacia()){
        CajitaPilaP* auxiliar = primero;
        while(auxiliar != 0){
            cout << auxiliar->getElemento() << endl;
            auxiliar = auxiliar->getSiguiente();
        }
    }
}
