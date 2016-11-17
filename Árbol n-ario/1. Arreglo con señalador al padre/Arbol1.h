#ifndef ARREGLOSENALPADRE_H_INCLUDED
#define ARREGLOSENALPADRE_H_INCLUDED

//Esta es la implementacion del arbol utilizando un array con señalador al pare.
//Cada vez que se mete un nodo se mete al final del array (para ello tenemos un señalador al ultimo) y se le dice quien es su padre

#include "Cajita1.h"
#include <iostream>
using namespace std;
typedef int nodo;
const int nodoNulo = 100;  //Nodo nulo para esta implementacion es el 100, ya que esta posicion no existe.

class arbol{

private:

    nodo ultimo;

public:
    int numElem;
    cajita1 arreglo[100];      //100 cajtas o sea M=100;

    arbol();
    ~arbol();

    //Operadores basicos del modelo
    void crear();
    void destruir();
    void vaciar();
    bool vacio();
    void poneRaiz(int etiqueta);
    void agregarHijo(int etiqueta, int posicion, nodo padre);
    void borrarHoja(nodo hoja);
    void modifEtiqueta(int etiqueta, nodo n);
    nodo raiz();
    nodo padre(nodo hijo);
    nodo hijoMasIzq(nodo padre);
    nodo herDer(nodo hermano);
    int etiqueta(nodo n);
    nodo traNodo(int etiqueta);
};

#endif // ARREGLOSENALPADRE_H_INCLUDED
