#ifndef PILAPRUEBA_H_INCLUDED
#define PILAPRUEBA_H_INCLUDED

#include "CajitaPilaP.h"


class PilaPrueba{

private:

    CajitaPilaP* primero;

public:

    PilaPrueba();
    ~PilaPrueba();
    void crear();
    void destruir();
    void vaciar();
    bool vacia();
    void poner(int);
    void quitar();
    int tope();
    void recorrer();

};

#endif // PILAPRUEBA_H_INCLUDED
