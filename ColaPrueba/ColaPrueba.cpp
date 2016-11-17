#include "ColaPrueba.h"

ColaPrueba::ColaPrueba(){}

void ColaPrueba::crear(){
    primero = 1;
    ultimo = 0;
    numElem = 0;
}

void ColaPrueba::destruir(){}

void ColaPrueba::vaciar(){
    primero = 1;
    ultimo = 0;
    numElem = 0;
}

bool ColaPrueba::vacia(){
    if(numElem == 0)
        return true;

    return false;
}

void ColaPrueba::agregar(int elemento){
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

void ColaPrueba::sacar(){
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

int ColaPrueba::frente(){
    if (numElem > 0){
        return arreglo[primero];
    }
    else{
        return 0;
    }
}
