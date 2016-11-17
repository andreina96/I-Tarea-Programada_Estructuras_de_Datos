#include "Arbol1.h"

arbol::arbol() : ultimo(0), numElem(0){}

arbol::~arbol(){}

void arbol::crear(){
    ultimo = 0;
    numElem = 0;
}

void arbol::destruir(){
    ultimo = 0;
    numElem = 0;
}

void arbol::vaciar(){
    ultimo = 0;
    numElem = 0;
}

bool arbol::vacio(){
    if(numElem == 0)
        return 1;
    return 0;
}

void arbol::poneRaiz(int etiqueta){  //la raiz siempre va en la posicion 0 del array.
    arreglo[0].setEtiqueta(etiqueta);
    ultimo = 0;
    numElem = 1;
}

void arbol::agregarHijo(int etiqueta, int posicion, nodo padre){  //se inserta el hijo después de donde este al padre y se corre todo hacia la derecha.
    if(numElem != 100){
        int contPos = 0;
        int nodo;
        for(int i = 0; i <= ultimo; i++){
            if(arreglo[i].getPadre() == padre){
                contPos++;
                if(contPos == posicion)
                    nodo = i;
            }
        }
        if(contPos < posicion){
            arreglo[ultimo + 1].setEtiqueta(etiqueta);
            arreglo[ultimo + 1].setPadre(padre);
        }
        if(contPos >= posicion){
            for(int i = ultimo + 1; i > nodo; i--){
                arreglo[i] = arreglo[i-1];
            }
            arreglo[nodo].setEtiqueta(etiqueta);
            arreglo[nodo].setPadre(padre);
        }
        ultimo++;
        numElem++;
    }
}

void arbol::borrarHoja(nodo hoja){    // se corren hacia atras todas las posiciones  del array que estaban adelante de dicho nodo.
    for(int i = hoja; i < ultimo; i++){
        if(arreglo[i+1].getPadre() <= hoja){
            cajita1 temporal = arreglo[i + 1];
            arreglo[i] = temporal;
        }
        else{
            cajita1 temporal = arreglo[i + 1];
            arreglo[i] = temporal;
            arreglo[i].setPadre(arreglo[i].getPadre() - 1);
        }
    }
    ultimo--;
    numElem--;
}

void arbol::modifEtiqueta(int etiqueta, nodo n){
    arreglo[n].setEtiqueta(etiqueta);
}

nodo arbol::raiz(){
    return 0;
}

nodo arbol::padre(nodo hijo){   //es directo porque ya tiene un señalador a este
    if (hijo != 0){
        return arreglo[hijo].getPadre();
    }
    else{
        return nodoNulo;
    }
}

nodo arbol::hijoMasIzq(nodo padre){  //se busca desde el padre porque el hijo siempre esta mas a la derecha en el array
    int hijo = nodoNulo;
    for(int i = padre + 1; i <= ultimo; i++){
        if(arreglo[i].getPadre() == padre){
            hijo = i;
            i = 100;
        }
    }

    return hijo;
}

nodo arbol::herDer(nodo hermano){    //se busca al hermano a partir del nodo donde estamos porque este siempre está más a la derecha.
    for(int i = hermano + 1; i <= ultimo; i++){
        if(arreglo[i].getPadre() == arreglo[hermano].getPadre()){
            return i;
        }
    }

    return nodoNulo;
}

nodo arbol::etiqueta(nodo n){
    return arreglo[n].getEtiqueta();
}

nodo arbol::traNodo(int etiqueta){
    for(int i = 0; i <= ultimo; i++){
        if(arreglo[i].getEtiqueta() == etiqueta){
            return i;
        }
    }
    return 100;
}
