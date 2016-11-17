#include <iostream>
#include "PilaPrueba.h"

//Esta clase es la que se utiliza para probar la funcionalidad de la Pila en el menú.
//Funciona exactamente igual que el ModeloPila pero en vez de guardar nodos de arboles
//guarda ints.

using namespace std;

int main()
{
    PilaPrueba p = PilaPrueba();
    p.crear();
    p.poner(12);
    cout << p.tope() << endl;
    p.quitar();
    if(p.vacia()){
        cout << "esta vacia" << endl;
    }
}
