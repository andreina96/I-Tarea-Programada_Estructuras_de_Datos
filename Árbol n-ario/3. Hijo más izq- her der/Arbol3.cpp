#include "Arbol3.h"

arbol::arbol() : r(0){}

arbol::~arbol(){}

void arbol::crear(){}

void arbol::destruir(){
    destruirRec(r);
}

void arbol::destruirRec(nodo n){                    //se hace un llamado en post orden que primero llama a todos sus hijos para borrarse.
    cajita3* nh = n->getHijoMasIzq();
	while(nh != nodoNulo){
        cajita3* na = nh->getHerDer();
		destruirRec(nh);
        nh = na;
	}
    delete n;
}

void arbol::vaciar(){
	if(!vacio()){
		vaciarRec(r);
	}
	cajita3* auxiliar = r;
	r = 0;
	delete auxiliar;
}


void arbol::vaciarRec(nodo n){
	cajita3* nh = n->getHijoMasIzq();
	while(nh != nodoNulo){
        cajita3* na = nh->getHerDer();
		vaciarRec(nh);
        nh = na;
	}
	if(n != r){
        delete n;
	}
}

bool arbol::vacio(){
    if(r == nodoNulo)
        return true;
    return false;
}

void arbol::poneRaiz(int etiqueta){
    cajita3* auxiliar = new cajita3(etiqueta);
    r = auxiliar;
}

void arbol::agregarHijo(int etiqueta, int posicion, nodo padre){    //para agregar un hijo nos vamos directo al padre
    if(posicion == 1){                                             //si es en la posicion 1 nada mas lo aregamos como hijo mas izquiero
        cajita3* auxiliar = new cajita3(etiqueta);
        auxiliar->setHerDer(padre->getHijoMasIzq());
        padre->setHijoMasIzq(auxiliar);
    }
    else{
        cajita3* inicio = padre->getHijoMasIzq();                  //si no, nos movemos empezando por su hijo izquierdo
        int posiInicial = 1;
        while(posiInicial != posicion - 1){
            posiInicial++;
            inicio = inicio->getHerDer();                         //una vez que llegamos a la posiciion correcta, le agregamos ese nodo como su hermano derecho
        }
        cajita3* auxiliar = new cajita3(etiqueta);
        cajita3* auxiliarHermanos = inicio->getHerDer();
        auxiliar->setHerDer(auxiliarHermanos);
        inicio->setHerDer(auxiliar);
    }
}

void arbol::borrarHoja(nodo hoja){
    bool borrado = false;
    borrarHojaRec(r, hoja, borrado);
}

void arbol::borrarHojaRec(nodo n, nodo hoja, bool borrado){        //nos debemos de mover recursivamente por todo el arbol hasta encntrar al padre
	nodo nh = n->getHijoMasIzq();
    if(nh == hoja){                                                 //cuano llegamos al padre de la hoja, cambiamos el hijo mas izquierdo del padre y lo borramos
        cajita3* auxiliarHermanos = hoja->getHerDer();
        cajita3* auxiliarHoja = hoja;
        n->setHijoMasIzq(auxiliarHermanos);
        delete auxiliarHoja;
        borrado = true;
	}
    while((nh != nodoNulo) && (borrado == 0)){
        borrarHojaRec(nh, hoja, borrado);                  //si no hemos encontrado al padre realizamos un llamado recursivo
        if(nh->getHerDer() == hoja){                       //si lo encontramos como hermano derecho de otro hijo, debemos cambiar el hermano derecho del su hermano anterior
            cajita3* auxiliarHermanos = hoja->getHerDer();  //pero el hermano izquierdo del padre lo dejamos igual
            cajita3* auxiliarHoja = hoja;
            nh->setHerDer(auxiliarHermanos);
            delete auxiliarHoja;
            borrado = true;
        }
        else{
            nh = nh->getHerDer();
        }
    }
}

void arbol::modifEtiqueta(int etiqueta, nodo aModificar){
    aModificar->setEtiqueta(etiqueta);
}

nodo arbol::raiz(){
    return r;
}

nodo arbol::padre(nodo hijo){       //para el padre debemos de recorrer todo el arbol
    nodo padre = nodoNulo;
    padreRec(r, 0, hijo, padre);
    return padre;
}

void arbol::padreRec(nodo n, nodo p, nodo hijo, nodo& padre){
	p = n;
	nodo nh = n->getHijoMasIzq();        //hasta encontrarlo como hizo izquierdo o hermano de alguien
	while(nh != nodoNulo){
        if(hijo == nh){
            padre = p;
        }
		padreRec(nh, n, hijo, padre);
		nh = nh->getHerDer();
	}
}

nodo arbol::hijoMasIzq(nodo padre){
    return padre->getHijoMasIzq();
}

nodo arbol::herDer(nodo hermano){
    if(hermano->getHerDer() != 0)
        return hermano->getHerDer();
    return 0;
}

int arbol::etiqueta(nodo n){
    return n->getEtiqueta();
}

nodo arbol::traNodo(int etiqueta){
    nodo ne = nodoNulo;
    if (r != 0){
        traNodoRec(ne, r, etiqueta);
    }

    return ne;
}

void arbol::traNodoRec(nodo& ne, nodo n, int etiqueta){
    if(n->getEtiqueta() == etiqueta){
        ne = n;
    }
    nodo nh = n->getHijoMasIzq();
    while (nh != nodoNulo){
        traNodoRec(ne, nh, etiqueta);
        nh = nh->getHerDer();
    }
}

void arbol::listarInOrden(){
    if(!vacio())
        listarInOrdenRec(raiz());
}

void arbol::listarInOrdenRec(nodo n){
    nodo nh = hijoMasIzq(n);
    if(nh != nodoNulo){
        listarInOrdenRec(nh);
    }
    cout << etiqueta(n) << ".";
    if(nh != 0){
        nh = herDer(nh);
        while(nh != nodoNulo){
            listarInOrdenRec(nh);
            nh = herDer(nh);
        }
    }
}
