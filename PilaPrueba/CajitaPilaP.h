#ifndef CAJITAPILAP_H_INCLUDED
#define CAJITAPILAP_H_INCLUDED

#include <iostream>

class CajitaPilaP{

private:

    CajitaPilaP* siguiente;
    int elemento;

public:

     CajitaPilaP() : siguiente(0){}

    ~ CajitaPilaP(){}

     CajitaPilaP(int e){
        elemento = e;
        siguiente = 0;
    }

    void setSiguiente( CajitaPilaP* s){
        this->siguiente = s;
    }

     CajitaPilaP* getSiguiente(){
        return this->siguiente;
    }

    void setElemento(int e){
        this->elemento = e;
    }

    int getElemento(){
        return this->elemento;
    }

};


#endif // CAJITAPILAP_H_INCLUDED
