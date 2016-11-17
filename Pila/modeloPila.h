#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "cajita.h"

//Esta es la pila que se utiliza como modelo auxiliar para los algoritmos del arbol. Guarda elementos del tipo nodos del arbol.
//Esta pila ha sido implementada como una lista simplemente enlazada donde se agrega y se elimina solamente al primer elemento.


typedef cajitapila* caPi;

class modeloPila{

private:

    cajitapila* primero;     //la pila esta hechas de cajitas pila ya que cada una contiene su elemento y el señalador al siguiente.

public:

    modeloPila();
    ~modeloPila();
    void crear();
    void destruir();
    void vaciar();
    bool vacia();
    void poner(nodo);
    void quitar();
    cajitapila* tope();
    void recorrer();

};

#endif // modeloPila_H_INCLUDED
