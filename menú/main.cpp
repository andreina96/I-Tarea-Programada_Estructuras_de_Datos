#include "menu.h"

//Este es el main que se ejecuta a la hora de iniciar el programa. Lo primero que se hace es inicializar una clase prueba.
//Esta clase prueba, es el men� desde donde se pueden llamar operadores b�sicos de la cola, la pila o el �rbol.
//A la hora de trabajar con distintos modelos, desde el men� se pueden crear las siguientes clases clases como ModeloArbol, ModeloPila o ModeloCola.
//Los operadores b�sicos son a su vez llamados por dichas clases, al igual que en el caso del ModeloArbol a sus algoritmos respectivos.
//El modeloArbol es m�s complejo ya que este a su vez llama a los operadores b�sicos de la implementaci�n espec�fica del arbol con la que se este trabajando
//As� por ejemplo si se trabaja con el Array con se�alador al padre. El modelo �rbol le pide a esta implementaci�n sus operadores b�sicos para ser ejectutados.

int main(){

    prueba p;
    p.menu();

    return 0;

}
