#ifndef HMI_HD_H_INCLUDED
#define HMI_HD_H_INCLUDED
#include "Cajita3.h"
#include <iostream>

//Esta es la implementacion de Hijo mas izquierdo, hermano derecho. Terminan siendo varias listas enlazadas.

using namespace std;
typedef cajita3* nodo;
const nodo nodoNulo = 0;   //el nodo nulo se define como un puntero 0

class arbol{

private:

    nodo r;   //tiene un puntero a la raiz

    void destruirRec(nodo n);
    void vaciarRec(nodo n);
    void borrarHojaRec(nodo n, nodo hoja, bool borrado);
    void padreRec(nodo n, nodo p, nodo hijo, nodo& padre);
    void traNodoRec(nodo& ne, nodo n, int etiqueta);

public:

    arbol();
    ~arbol();
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
    void listarInOrden();
    void listarInOrdenRec(nodo n);

};

#endif // HMI_HD_H_INCLUDED
