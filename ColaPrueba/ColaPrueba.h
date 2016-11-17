#ifndef COLAPRUEBA_H_INCLUDED
#define COLAPRUEBA_H_INCLUDED

#include <string>
using namespace std;

class ColaPrueba{

private:

    int numElem;
    int primero;
    int ultimo;
    int arreglo[100];

public:

    ColaPrueba();
    void crear();
    void destruir();
    void vaciar();
    bool vacia();
    void agregar(int elemento);
    void sacar();
    int frente();

};


#endif // COLAPRUEBA_H_INCLUDED
