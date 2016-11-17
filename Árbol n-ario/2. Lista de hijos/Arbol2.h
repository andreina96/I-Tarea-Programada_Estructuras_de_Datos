#ifndef LISTAHIJOS_H_INCLUDED
#define LISTAHIJOS_H_INCLUDED
#include "cajitaprincipal.h"
#include <iostream>

//Esta es la implementacion de Lista de Hijos del modeloArbo, esta compuesta de nodos que tienen un puntero a su primer hijo y un puntero
//a su siguiente nodo

using namespace std;
typedef cajitaprincipal* nodo;
typedef cajitahijos* nodoHijos;
const nodo nodoNulo = 0;

class arbol{

private:

	nodo r;

    void vaciarRec(nodo n);
    void vaciarHijosRec(nodoHijos nhijos);

public:

	arbol();
	~arbol();
    void crear();
	void destruir();
	void vaciar();
	bool vacio();
	void poneRaiz(int etiqueta);
	void agregarHijo(int etiqueta, int posicion, nodo padre);
	void borrarHoja(nodo hoja);
	void modifEtiqueta(int etiqueta, nodo n);
	nodo raiz();
	nodo padre(nodo hijo);
	nodo hijoMasIzq(nodo padre);
	nodo herDer(nodo hermano);
	int etiqueta(nodo n);
	nodo traNodo(int etiqueta);
};

#endif // LISTAHIJOS_H_INCLUDED
