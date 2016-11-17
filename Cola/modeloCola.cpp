#include "modeloCola.h"

modeloCola::modeloCola(){}

void modeloCola::crear(){
    primero = 1;                     //el primero se coloa adelante del  último para decir que la cola está vacia
    ultimo = 0;
    numElem = 0;
}

void modeloCola::destruir(){}

void modeloCola::vaciar(){
    primero = 1;
    ultimo = 0;
    numElem = 0;
}

bool modeloCola::vacia(){
    if(numElem == 0)
        return true;

    return false;
}

void modeloCola::agregar(nodo elemento){     //se agrega el elemento al final y el señalador al último se corre una posicion hacia la derecha.
    if(numElem != 100){
        if(numElem == 0){
            ultimo = 1;
            arreglo[1] = elemento;

        }else if(ultimo == (99)){
            arreglo[0] = elemento;
            ultimo = 0;
        }
        else {
            ultimo ++;
            arreglo[ultimo] = elemento;
        }
        numElem ++;
    }
}

void modeloCola::sacar(){   //se saca el primer elemento y se corre la posicion del señalador al primero un espacio hacia delante.
    if(primero == 99){
        primero = 0;
    }
    else{
        primero ++;
    }
    numElem --;
    if(numElem == 0){
        vaciar();
    }
}

nodo& modeloCola::frente(){   //nos imprime el primer elemento del frente.
    return arreglo[primero];
}
