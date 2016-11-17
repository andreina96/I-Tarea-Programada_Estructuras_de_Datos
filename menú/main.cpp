#include "menu.h"

//Este es el main que se ejecuta a la hora de iniciar el programa. Lo primero que se hace es inicializar una clase prueba.
//Esta clase prueba, es el menú desde donde se pueden llamar operadores básicos de la cola, la pila o el árbol.
//A la hora de trabajar con distintos modelos, desde el menú se pueden crear las siguientes clases clases como ModeloArbol, ModeloPila o ModeloCola.
//Los operadores básicos son a su vez llamados por dichas clases, al igual que en el caso del ModeloArbol a sus algoritmos respectivos.
//El modeloArbol es más complejo ya que este a su vez llama a los operadores básicos de la implementación específica del arbol con la que se este trabajando
//Así por ejemplo si se trabaja con el Array con señalador al padre. El modelo árbol le pide a esta implementación sus operadores básicos para ser ejectutados.

int main(){

    prueba p;
    p.menu();

    return 0;

}
