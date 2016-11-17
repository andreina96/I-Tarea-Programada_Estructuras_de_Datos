#ifndef CAJITA_H_INCLUDED
#define CAJITA_H_INCLUDED
#include <iostream>
//#include "cajitaprincipal.h"
//typedef cajitaprincipal* nodo;
//#include "cajita3.h"
//typedef cajita3* nodo;
#include "cajita4.h"
typedef cajita4* nodo;

//typedef int nodo;

class cajitapila{

private:

    cajitapila* siguiente;   //puntero a la siguente cajita
    nodo elemento;
    bool visitado;         //se utiliza el visitado para simular la recursividad en el recorrido profundidad primero

public:

    cajitapila() : siguiente(0){}     //en inicio no tiene ningun siguiente

    ~cajitapila(){}

    cajitapila(nodo n){                //contiene un nodo que en este caso es un nodo de un arbol
        elemento = n;
        visitado = false;
        siguiente = 0;
    }

    void setSiguiente(cajitapila* s){
        this->siguiente = s;
    }

    cajitapila* getSiguiente(){
        return this->siguiente;
    }

    void setElemento(nodo n){
        this->elemento = n;
    }

    nodo getElemento(){
        return this->elemento;
    }

    void setVisitado(bool v){
        this->visitado = v;
    }

    bool getVisitado(){
        return this->visitado;
    }

};

#endif // CAJITA_H_INCLUDED
