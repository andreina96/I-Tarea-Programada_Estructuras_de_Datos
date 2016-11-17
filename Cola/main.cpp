#include <stdlib.h>
#include <iostream>
#include "modeloCola.h"

int main(){
    modeloCola c = modeloCola();
    c.crear();
    c.agregar(1);
    c.sacar();
    c.agregar(3);
    c.agregar(4);
    c.sacar();
    c.sacar();

    cout << c.frente();

    return 0;

}
