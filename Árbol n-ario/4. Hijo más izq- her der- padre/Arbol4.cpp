#include "Arbol4.h"

arbol::arbol() : r(0){}

arbol::~arbol(){}

void arbol::crear(){}

void arbol::destruir(){
    destruirRec(r);
}

void arbol::destruirRec(nodo n){
    nodo nh = n->getHijoMasIzq();
	while(nh != nodoNulo){
        nodo na = nh->getHerDer();
		destruirRec(nh);
        nh = na;
	}
    delete n;
}

void arbol::vaciar(){
	if(!vacio()){
		vaciarRec(r);
	}
	nodo auxiliar = r;
	r = 0;
	delete auxiliar;
}


void arbol::vaciarRec(nodo n){
	nodo nh = n->getHijoMasIzq();
	while(nh != nodoNulo){
        nodo na = nh->getHerDer();
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
    nodo auxiliar = new cajita4(etiqueta, 0);
    r = auxiliar;
}

void arbol::agregarHijo(int etiqueta, int posicion, nodo padre){
    if(posicion == 1){
        nodo auxiliar = new cajita4(etiqueta, padre);
        auxiliar->setHerDer(padre->getHijoMasIzq());
        padre->setHijoMasIzq(auxiliar);
    }
    else{
        nodo inicio = padre->getHijoMasIzq();
        int posiInicial = 1;
        while(posiInicial != posicion - 1){
            posiInicial++;
            inicio = inicio->getHerDer();
        }
        nodo auxiliar = new cajita4(etiqueta, padre);
        nodo auxiliarHermanos = inicio->getHerDer();
        auxiliar->setHerDer(auxiliarHermanos);
        inicio->setHerDer(auxiliar);
    }
}

void arbol::borrarHoja(nodo hoja){
    nodo p = padre(hoja);
    if(hoja == p->getHijoMasIzq()){
        nodo auxiliar = hoja;
        p->setHijoMasIzq(hoja->getHerDer());
        delete auxiliar;
    }
    else{
        nodo herIzq = p->getHijoMasIzq();
        while(herIzq->getHerDer() != hoja){
            herIzq = herIzq->getHerDer();
        }
        nodo auxiliar = hoja;
        herIzq->setHerDer(hoja->getHerDer());
        delete auxiliar;
    }
}

void arbol::modifEtiqueta(int etiqueta, nodo n){
    n->setEtiqueta(etiqueta);
}

nodo arbol::raiz(){
    return r;
}

nodo arbol::padre(nodo hijo){
    return hijo->getPadre();
}

nodo arbol::hijoMasIzq(nodo padre){
    return padre->getHijoMasIzq();
}

nodo arbol::herDer(nodo hermano){
    return hermano->getHerDer();
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
