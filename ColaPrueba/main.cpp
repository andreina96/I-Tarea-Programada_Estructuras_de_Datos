#include <stdlib.h>
#include <iostream>
#include "ColaPrueba.h"

//Esta es la clase que se utiliza para probar la cola en el menú de pruebas.
//funciona exactamente igual pero aquí el nodo lo definimos como un entero.
//Decimos entonces que es una cola de nodos, donde el nodo es un tipo entero.

int main(){
    ColaPrueba c = ColaPrueba();
    c.crear();
    c.agregar(1);
    cout << c.frente()<< endl;
    c.sacar();
    cout << c.frente()<< endl;
    c.agregar(3);
    c.agregar(4);
    cout << c.frente()<< endl;
    c.sacar();
    cout << c.frente()<< endl;
    c.sacar();

    cout << c.frente()<< endl;

    return 0;

}
