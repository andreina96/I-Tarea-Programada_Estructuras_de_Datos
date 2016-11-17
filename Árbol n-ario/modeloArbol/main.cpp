#include "modeloArbol.h"

int main(){

    modeloArbol ma = modeloArbol();
    cout << "Probando algoritmos de la clase modelo arbol" << endl << endl;
    arbol a = ma.devolverArbol(1);
    ma.crear(a);
    ma.poneRaiz(1, a);
    ma.agregarHijo(2,1,ma.traNodo(1,a), a);
    ma.agregarHijo(3,2,ma.traNodo(1,a), a);
    ma.agregarHijo(4,3,ma.traNodo(1,a), a);
    ma.agregarHijo(7,1,ma.traNodo(2,a), a);
    ma.agregarHijo(90,1,ma.traNodo(3,a), a);
    ma.agregarHijo(239,1,ma.traNodo(3,a), a);
    ma.agregarHijo(99,1,ma.traNodo(90,a), a);
    ma.agregarHijo(109,1,ma.traNodo(99,a), a);
    ma.listarPreOrdenPila(a);
    cout << "Estructura: 1 es la raiz, 2,3,4 hijos de la raiz, 7 hijo de 2, 90 hijo de 3, 239 hijo de 3, 99 hijo de 90, 109 hijo de 99"<< endl;
    cout << "Antes de borrar 3: ";
    ma.listarPreOrden(a);
    ma.borrarNodoMoverSubArboles(ma.traNodo(3,a),a);
    cout << endl << "Despues de borrar 3: ";
    ma.listarPreOrden(a);
    /*cout << "Se agrego 1. Raiz" << endl;
    cout << "Se agrego 2. Hijo de raiz" << endl;
    cout << "Se agrego 3. Hijo de raiz" << endl;
    cout << "Se agrego 4. Hijo de raiz" << endl;
    cout << "Se agrego 7. Hijo de 2" << endl;
    cout << "Se agrego 90. Hijo de 3" << endl;
    cout << "Se agrego 99. Hijo de 90" << endl;
    cout << "Se agrego 109. Hijo de 99" << endl;
    cout << "HermanoIzquierdo: el hermano izquierdo del nodo 3, es: " << ma.etiqueta(ma.herIzq(ma.traNodo(3,a), a), a) << endl;
    cout << "HermanoIzquierdo: el hermano izquierdo del nodo 4, es: " << ma.etiqueta(ma.herIzq(ma.traNodo(4,a), a), a) << endl;
    if(ma.etiquetasRepetidas(a)){
        cout << "EtiquetasRepetidas: el arbol si tiene etiquetas repetidas" << endl;
    }
    cout << "Altura: la altura del árbol, es: " << ma.altura(ma.raiz(a), a) << endl;
    cout << "Profundidad: la profundidad de nodo 109, es: " << ma.profundidad(ma.traNodo(109, a), a) << endl;
    cout << "Nivel: los niveles que tiene el árbol, son: " << ma.niveles(a) << endl;
    cout << "Listar niveles: nivel 1 " << endl;
    ma.listarEtiquetasDelNivel(1, a);
    cout << "Listar niveles: nivel 2 " << endl;
    ma.listarEtiquetasDelNivel(2, a);
    cout << "Listar niveles: nivel 3 " << endl;
    ma.listarEtiquetasDelNivel(3, a);
    cout << "Listar niveles: nivel 4 " << endl;
    ma.listarEtiquetasDelNivel(4, a);
    cout << "Listar niveles: nivel 5 " << endl;
    ma.listarEtiquetasDelNivel(5, a);
    cout << "Listar hijos: de la raiz" << endl;
    ma.listarEtiquetasHijos(ma.raiz(a), a);
    cout << "Listar hijos: de 2" << endl;
    ma.listarEtiquetasHijos(ma.traNodo(2, a), a);
    cout << "Listar hijos: de 3" << endl;
    ma.listarEtiquetasHijos(ma.traNodo(3, a), a);
    cout << "Listar hijos: de 90" << endl;
    ma.listarEtiquetasHijos(ma.traNodo(90, a), a);
    cout << "Listar hijos: de 99" << endl;
    ma.listarEtiquetasHijos(ma.traNodo(99, a), a);
    cout << "Cantidad de nodos: la cantidad de nodos del arbol, es: " << ma.cantidadNodos(a) << endl;
    ma.borrarSubArbol(ma.traNodo(2, a), a);
    cout << "Borrar subarbol: se borro el sub arbol 2, ahora la cantidad de nodos del arbol, es: " << ma.cantidadNodos(a) << endl;

    arbol b = ma.devolverArbol(2);
    ma.crear(b);
    ma.poneRaiz(1, b);
    ma.agregarHijo(3,1,ma.traNodo(1,b), b);
    ma.agregarHijo(4,2,ma.traNodo(1,b), b);
    ma.agregarHijo(90,1,ma.traNodo(3,b), b);
    ma.agregarHijo(99,1,ma.traNodo(90,b), b);
    ma.agregarHijo(109,1,ma.traNodo(99,b), b);

    cout << "Cantidad nodos: la cantidad de nodos del arbol, es: " << ma.cantidadNodos(b) << endl;

    if(ma.iguales(a, b) == 1){
        cout << "Iguales: los arboles a y b, son iguales" << endl;
    }
    else{
        cout << "Iguales: los arboles a y b, no son iguales" << endl;
    }
    cout << "Listar preorden: " << endl;
    ma.listarPreOrden(a);
    cout << endl;
    cout << "Listar postorden: " << endl;
    ma.listarPostOrden(a);
    cout << endl;
    cout << "Listar inorden: " << endl;
    ma.listarInOrden(a);
    cout << endl;
    cout << "Buscar nodo: el nodo con etiqueta 90, tiene efectivamente etiqueta: " << ma.etiqueta(ma.buscarNodo(90,a), a) << endl;
    ma.listarPorNivelesCola(a);
    cout << endl;
    arbol c = ma.devolverArbol(3);
    ma.crear(c);
    cout << "CopiarEn: copiar arbol a en c" << endl;
    cout << "Listar preorden: listar en preorden el arbol c:" << endl;
    ma.copiarEn(a,c);
    ma.listarPreOrden(c);
    cout << endl << "Listar preorden pila: listar el arbol c, usando la pila:" << endl;
    ma.listarPreOrdenPila(c);*/

    /*modeloArbol ma = modeloArbol();
    cout << "Probando metodos de la clase modelo arbol" << endl << endl;
    arbol a = a;
    ma.crear(a);
    bool vacio = ma.vacio(a);
    if(vacio == 1){
        cout << "vacio(): El arbol esta aun vacio" << endl;
    }
    ma.poneRaiz(7, a);
    cout << "raiz(): La raiz es " << ma.etiqueta(ma.raiz(a), a) << endl;
    vacio = ma.vacio(a);
    if(vacio == 0){
        cout << "vacio(): El arbol ya no esta vacio" << endl;
    }
    ma.agregarHijo(9, 1, ma.raiz(a), a);
    cout << "hijoMasIzq(): El hijo mas izquierdo de la raiz es " << ma.etiqueta(ma.hijoMasIzq(ma.raiz(a), a), a) << endl;
    ma.agregarHijo(20, 2, ma.raiz(a), a);
    cout << "herDer(): El hermano derecho de \"9\" es " << ma.etiqueta(ma.herDer(ma.hijoMasIzq(ma.raiz(a), a), a), a) << endl;
    nodo n9 = ma.traNodo(9, a);
    cout << "traNodo(): El nodo con etiqueta \"9\" tiene efectivamente etiqueta " << ma.etiqueta(n9, a) << endl;
    ma.agregarHijo(78, 1, n9, a);
    cout << "hijoMasIzq(): El hijo mas izquierdo del nodo \"9\" es " << ma.etiqueta(ma.hijoMasIzq(n9, a), a) << endl;
    ma.agregarHijo(40, 1, ma.raiz(a), a);
    cout << "hijoMasIzq(): El hijo mas izquierdo de la raiz es " << ma.etiqueta(ma.hijoMasIzq(ma.raiz(a), a), a) << endl;
    n9 = ma.traNodo(9, a);
    cout << "herDer(): El hermano derecho de \"9\" es " << ma.etiqueta(ma.herDer(n9, a), a) << endl;
    nodo n20 = ma.traNodo(20, a);
    ma.borrarHoja(n20, a);
    if(ma.herDer(n9, a) == 0){
        cout << "borrarHoja(): Ahora, el nodo con etiqueta \"20\" se ha borrado" << endl;
    }
    ma.modifEtiqueta(80, n9, a);
    cout << "modifEtiqueta(): Ahora, el nodo que tenia etiqueta \"9\", tiene etiqueta " << ma.etiqueta(n9, a) << endl;*/


    return 0;

}
