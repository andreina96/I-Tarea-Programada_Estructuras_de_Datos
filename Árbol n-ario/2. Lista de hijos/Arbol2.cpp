#include "Arbol2.h"

arbol::arbol() : r(0){}

arbol::~arbol(){
	destruir();
}

void arbol::crear(){
    r = 0;
}

void arbol::destruir(){
	vaciar();
	delete r;
}

void arbol::vaciar(){                //se debe recorrer toda la lista principal y toda la lista de hijos para borrar el arbol
	if (r != 0){
		if (r->getSiguiente() != 0){
			vaciarRec(r->getSiguiente());
        }
        r = 0;
	}
}

void arbol::vaciarRec(nodo n){
	if(n->getPrimero() != 0){
		vaciarHijosRec(n->getPrimero());
	}
	if(n->getSiguiente() != 0){
		vaciarRec(n->getSiguiente());
	}
	delete n;
}

void arbol::vaciarHijosRec(nodoHijos hijo){
	if (hijo->getSiguiente() != 0){
		vaciarHijosRec(hijo->getSiguiente());
	}
	delete hijo;
}

bool arbol::vacio(){
	if(r == 0)
		return true;
    return false;
}

void arbol::poneRaiz(int etiqueta){
	nodo raiz = new cajitaprincipal(etiqueta);
	r = raiz;
}

void arbol::agregarHijo(int etiqueta, int posicion, nodo padre){  //el hijo se agrega al inicio de la lista porque e es donde es más cómodo
	nodo aAgregar = new cajitaprincipal(etiqueta);
	nodoHijos aAgregarHijo = new cajitahijos(aAgregar);
	nodo nodoAuxiliar = r->getSiguiente();
	r->setSiguiente(aAgregar);
	aAgregar->setSiguiente(nodoAuxiliar);
	nodoHijos nodoHijo = padre->getPrimero();
	if(posicion == 1){                                       //si la posicion es uno, se agrega al inicio de la lista de hijos
		aAgregarHijo->setSiguiente(nodoHijo);
		padre->setPrimero(aAgregarHijo);
	}
	else{                                                     //si no hay que avanzar de posiciones hasta que lleguemos a la correcta para meter ahí al hijo
		for (int i = 2; i < posicion; i++){
			nodoHijo = nodoHijo->getSiguiente();
		}
		aAgregarHijo->setSiguiente(nodoHijo->getSiguiente());
		nodoHijo->setSiguiente(aAgregarHijo);
	}
}

void arbol::borrarHoja(nodo hoja){                          //se debe buscar el nodo en la lista principal y además en la lista de hijos
	bool borradoDeHijos= false;
	bool borradoDeLista =false;
	if (hoja == r){
		r = 0;
		borradoDeHijos = true;
		borradoDeLista = true;
	}
	nodo nodoPadre = r;
	while(!borradoDeHijos || !borradoDeLista){
		if(!borradoDeHijos){                                  //nos movemospor la lista de hijos buscando al nodo
			nodoHijos nHermano = nodoPadre->getPrimero();
			if (nHermano != 0){
				if (nHermano->getEsteNodo() == hoja){
					nodoPadre->setPrimero(nHermano->getSiguiente());
					delete nHermano;                       //una vez que lo encontramos los borramos y cambiamos a su hijo más izquierdo
					borradoDeHijos = true;
				}
			}
			while((nHermano != 0) && (!borradoDeHijos) && (nHermano->getSiguiente() != 0)){    //ahora pasamos a buscar al nodo en la lista principal
				nodoHijos siguiente = nHermano->getSiguiente();
				if (hoja == siguiente->getEsteNodo()){                   //observar que se empieza desde nHermano y no desde el inicio para ser más efectivos
					nHermano->setSiguiente(siguiente->getSiguiente());
					delete siguiente;
					borradoDeHijos = true;
				}
				nHermano = nHermano->getSiguiente();
			}
		}
		if (!borradoDeLista){
			if (nodoPadre->getSiguiente() == hoja){
				nodoPadre->setSiguiente((hoja->getSiguiente()));
				delete hoja;
				borradoDeLista= true;
			}
		}
		nodoPadre = nodoPadre->getSiguiente();
	}
}

void arbol::modifEtiqueta(int etiqueta, nodo n){
	n->setEtiqueta(etiqueta);
}

nodo arbol::raiz(){
    return r;
}

nodo arbol::padre(nodo hijo){          //para buscar al padre hay que movernos por toda la lista principal y ver en cual lista de hijos esta
	if(hijo != r){
		nodo padre = r;
		while(1){
			nodoHijos hermano = padre->getPrimero();
			while(hermano != 0){
				if(hijo == hermano->getEsteNodo()){
					return padre;
				}
				else{
					hermano = hermano->getSiguiente();
				}
			}
			padre = padre->getSiguiente();
		}
	}

	return 0;
}

nodo arbol::hijoMasIzq(nodo padre){
	if (padre->getPrimero() != 0)
		return padre->getPrimero()->getEsteNodo();
    return 0;
}

nodo arbol::herDer(nodo hermano){
	if(hermano != r){
		nodo npadre = r;
		while(npadre != 0){
			nodoHijos nhermano = npadre->getPrimero();
			while(nhermano != 0){
				if(hermano == nhermano->getEsteNodo()){
					if(nhermano->getSiguiente() == 0)
						return 0;
					return nhermano->getSiguiente()->getEsteNodo();
				}
				else
					nhermano = nhermano->getSiguiente();
            }
            npadre = npadre->getSiguiente();
		}
	}
	return 0;
}

int arbol::etiqueta(nodo n){
	if(n != 0)
		return n->getEtiqueta();
    return 0;
}

nodo arbol::traNodo(int etiqueta){
	nodo n = r;
	while(1){
		if(n->getEtiqueta() == etiqueta){
			return n;
		}
		n = n->getSiguiente();
	}
}
