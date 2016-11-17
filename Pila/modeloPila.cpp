#include <iostream>
#include "modeloPila.h"
using namespace std;

modeloPila::modeloPila() : primero(0){}

modeloPila::~modeloPila(){
    vaciar();
}

void modeloPila::crear(){
    primero = 0;
}

void modeloPila::destruir(){
    while(!vacia()){
        quitar();
    }
}

void modeloPila::vaciar(){
    while(!vacia()){
        quitar();
    }
}

bool modeloPila::vacia(){
    if(primero == 0)
        return 1;
    return 0;
}

void modeloPila::poner(nodo elemento){     //pone un elemento al inicio de la pila y hace que este sea el nuevo primero.
    if(primero == 0){
        cajitapila* auxiliarPrimero = new cajitapila(elemento);
        primero = auxiliarPrimero;
    }
    else{
        cajitapila* nuevoPrimero = new cajitapila(elemento);
        nuevoPrimero->setSiguiente(primero);
        primero = nuevoPrimero;
    }
}

void modeloPila::quitar(){               //saca al primer elemento de la pila y hace que el nuevo primero ahora sea el segundo elemento.
    cajitapila* auxiliar = primero;
    if(auxiliar->getSiguiente() != 0){
        primero = primero->getSiguiente();
    }
    else{
        primero = 0;
    }
    delete auxiliar;
}

cajitapila* modeloPila::tope(){     //devuelve el primer elemento de la lista.
    if(primero != 0)
        return primero;
    return 0;
}

void modeloPila::recorrer(){
    if(!vacia()){
        cajitapila* auxiliar = primero;
        while(auxiliar != 0){
            cout << auxiliar->getElemento() << endl;
            auxiliar = auxiliar->getSiguiente();
        }
    }
}
