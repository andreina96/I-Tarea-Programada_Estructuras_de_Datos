#ifndef MODELOCOLA_H_INCLUDED
#define MODELOCOLA_H_INCLUDED
#include <string>

//Esta cola se implementa utilizando un array "circular" en el sentido de que al irse sacando elementos, el ultimo y el primer
//elemento podrían pasar del final del array al inicio.

//Para implementarlo se utiliza dicho array además de un señalador al último, uno al primero y un contador con la cantidad
//de elementos para resolver ciertos problemas lógicos.

//En este caso específico, esta implementación será utilizada como modelo auxiliar para algunos algoritmos del árbol, por eso recibe nodos.

using namespace std;
//#include "cajitaprincipal.h"
//typedef cajitaprincipal* nodo;
//#include "cajita3.h"
//typedef cajita3* nodo;
#include "cajita4.h"
typedef cajita4* nodo;                  //el nodo se define como un nodo del arbol con el que se este trabajando.
//typedef int nodo;

class modeloCola{

private:

    int numElem;
    int primero;
    int ultimo;
    nodo arreglo[100];    //M = 100

public:

    modeloCola();
    void crear();
    void destruir();
    void vaciar();
    bool vacia();
    void agregar(nodo elemento);
    void sacar();
    nodo& frente();      //el frente de la cola es un elemento del tipo nodo y además devuelve la referencia por si se tuviera que trabajar cn esta.

};

#endif // MODELOCOLA_H_INCLUDED
