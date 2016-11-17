#ifndef HMI_HD_PADRE_H_INCLUDED
#define HMI_HD_PADRE_H_INCLUDED
#include "Cajita4.h"
#include <iostream>

//Esta implementacion es la hermano derecho, hijo mas izquierdo con señalador al padre.
//Funciona exactamente igual pero pero cambian los operadores basicos de Padre, Agregar Hijo y borrar Hoja
//ya que en vez de tener que recorrer todo el arbol para buscar a su papa, tienen un señalador a este, mejorando así los tiempos reales
//de ejecución.


using namespace std;
typedef cajita4* nodo;
const nodo nodoNulo = 0;

class arbol{

private:

    nodo r;

    void destruirRec(nodo n);
    void vaciarRec(nodo n);
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
};

#endif // HMI-HD-PADRE_H_INCLUDED
