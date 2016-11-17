#ifndef CAJITAPRINCIPAL_H_INCLUDED
#define CAJITAPRINCIPAL_H_INCLUDED
#include "cajitahijos.h"
//cajita de la lista de hijos principal, tiene su etiqueta, un señalador a su primer hijo y un señalador al siguiente nodo.


using namespace std;

class cajitahijos;

class cajitaprincipal{

private:

	int etiqueta;
	cajitaprincipal* siguiente;
	cajitahijos* primero;

public:

	cajitaprincipal(int);
	cajitaprincipal();
    ~cajitaprincipal();
    void setEtiqueta(int);
	int getEtiqueta();
	void setSiguiente(cajitaprincipal*);
	cajitaprincipal* getSiguiente();
	void setPrimero(cajitahijos*);
	cajitahijos* getPrimero();

};





#endif // CAJITAPRINCIPAL_H_INCLUDED
