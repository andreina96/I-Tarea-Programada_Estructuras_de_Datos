#include "Arbol3.h"

int main(){

    typedef cajita3* nodo;

    arbol a = arbol();
    a.crear();
    a.poneRaiz(1);
    a.agregarHijo(3,1,a.traNodo(1));
    a.agregarHijo(4,2,a.traNodo(1));
    a.agregarHijo(90,1,a.traNodo(3));
    a.agregarHijo(99,1,a.traNodo(90));
    a.agregarHijo(109,1,a.traNodo(99));
    a.listarInOrden();


    /*cout << "Probando metodos de la clase" << endl << endl;
    a.crear();
    bool vacio = a.vacio();
    if(vacio == 1){
        cout << "vacio(): El arbol esta aun vacio" << endl;
    }
    a.poneRaiz(7);
    cout << "raiz(): La raiz es " << a.etiqueta(a.raiz()) << endl;
    vacio = a.vacio();
    if(vacio == 0){
        cout << "vacio(): El arbol ya no esta vacio" << endl;
    }
    a.agregarHijo(9, 1, a.raiz());
    cout << "hijoMasIzq(): El hijo mas izquierdo de la raiz es " << a.etiqueta((a.hijoMasIzq(a.raiz()))) << endl;
    a.agregarHijo(20, 2, a.raiz());
    cout << "herDer(): El hermano derecho de \"9\" es " << a.etiqueta(a.herDer(a.hijoMasIzq(a.raiz()))) << endl;
    nodo n9 = a.traNodo(9);
    cout << "traNodo(): El nodo con etiqueta \"9\" tiene efectivamente etiqueta " << a.etiqueta(n9) << endl;
    a.agregarHijo(78, 1, n9);
    cout << "hijoMasIzq(): El hijo mas izquierdo del nodo \"9\" es " << a.etiqueta(a.hijoMasIzq(n9)) << endl;
    a.agregarHijo(40, 1, a.raiz());
    cout << "hijoMasIzq(): El hijo mas izquierdo de la raiz es " << a.etiqueta(a.hijoMasIzq(a.raiz())) << endl;
    n9 = a.traNodo(9);
    cout << "herDer(): El hermano derecho de \"9\" es " << a.etiqueta(a.herDer(n9)) << endl;
    nodo n20 = a.traNodo(20);
    a.borrarHoja(n20);
    if(a.herDer(n9) == 0){
        cout << "borrarHoja(): Ahora, el nodo con etiqueta \"20\" se ha borrado" << endl;
    }
    a.modifEtiqueta(80, n9);
    cout << "modifEtiqueta(): Ahora, el nodo que tenia etiqueta \"9\", tiene etiqueta " << a.etiqueta(n9) << endl*/

    return 0;

}
