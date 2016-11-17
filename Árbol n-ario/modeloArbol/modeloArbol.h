#ifndef MODELOARBOL_H_INCLUDED
#define MODELOARBOL_H_INCLUDED
#include "modeloCola.h"
#include "modeloPila.h"

//Esta es la clase que llama a los operadores basicos de cada implementacion del modeloArbol, tambiénn desde acá se llama a los algoritmos
//Se escoge con cual arbol se desea trabajar utilizando los includes que aparecen a continuacion.
//Recordar que al cambiar de implementacion tambien se deben cambiar los includes de las estructuras auxiliares que utilice un algoritmo.
//Por ejemplo si se desea cambiar a lista de hijos y se quiere el algoritmo se recorrido por niveles, deberá ir a modeloPila y cambiar la definición de nodo y el include.


/* ======================= Arbol1 : arreglo con señalador al padre ============================== */
//#include "arbol1.h"
/* ======================= Arbol2 : lista de hijos ============================================== */
//#include "arbol2.h"
//#include "cajitaprincipal.h"
/* ======================= Arbol3 : hijo más izquierdo- hermano derecho ========================= */
//#include "arbol3.h"
//#include "cajita3.h"
/* ======================= Arbol4 : hijo más izquierdo- hermano derecho- puntero al padre ======= */
#include "arbol4.h"
#include "cajita4.h"

class modeloArbol{

private:

    arbol a;
    arbol b;
    arbol c;

public:

    /* Operadores básicos */

    modeloArbol();
    ~modeloArbol();
    void crear(arbol&);
    void destruir(arbol&);
    void vaciar(arbol&);
    bool vacio(arbol&);
    void poneRaiz(int etiqueta, arbol&);
    void agregarHijo(int etiqueta, int posicion, nodo n, arbol&);
    void borrarHoja(nodo n, arbol&);
    void modifEtiqueta(int etiqueta, nodo n, arbol&);
    nodo raiz(arbol&);
    nodo padre(nodo n, arbol&);
    nodo hijoMasIzq(nodo n, arbol&);
    nodo herDer(nodo n, arbol&);
    arbol& devolverArbol(int);
    int etiqueta(nodo n, arbol&);
    nodo traNodo(int etiqueta, arbol&);

    /* Algoritmos */

    nodo herIzq(nodo, arbol&);
    bool etiquetasRepetidas(arbol&);
    void etiquetasRec1(nodo n, arbol& a,bool &resultado );
    void etiquetasRec2(nodo n1,nodo n2,arbol& a,bool &resultado);
    int altura(nodo, arbol&);
    void alturaRec(nodo, int &altura,int alturaTemporal, arbol&);
    int profundidad (nodo, arbol&);
    int niveles(arbol&);
    void listarEtiquetasDelNivel(int nivel, arbol&);
    void listarEtiquetasDelNivelRec(int nivel, int nivelActual, nodo n, arbol&);
    void listarEtiquetasHijos(nodo papa, arbol&);
    int cantidadNodos(arbol&);
    void cantidadNodosRec(nodo n, int &cantidad, arbol&);
    void borrarSubArbol(nodo aBorrar, arbol&);
    void borrarSubArbolRec(nodo n, arbol&);
    void borrarNodoMoverSubArboles(nodo aBorrar, arbol&);
    void copiarGeneral(arbol &ar1, nodo n1, arbol& ar2, nodo n2, int p);
    void copiarEn(arbol&, arbol&);
    bool iguales(arbol&, arbol&);
    void igualesRec(nodo, nodo, arbol&, arbol&, bool&);
    void listarPreOrden(arbol&);
    void listarPreOrdenRec(nodo, arbol&);
    void listarPostOrden(arbol&);
    void listarPostOrdenRec(nodo, arbol&);
    void listarInOrden(arbol&);
    void listarInOrdenRec(nodo, arbol&);
    void listarPorNivelesCola(arbol&);
    void listarPreOrdenPila(arbol&);

    nodo buscarNodo(int, arbol&);
    void buscarNodoRec(int, nodo, nodo&, arbol&);








};

#endif // MODELOarbol&_H_INCLUDED
