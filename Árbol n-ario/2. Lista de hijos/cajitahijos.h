#ifndef CAJITAHIJOS_H_INCLUDED
#define CAJITAHIJOS_H_INCLUDED
#include "cajitaprincipal.h"

//cajitas de cada lista de hijos, tiene un señalador a su "identidad" y un señalador al siguiente hijo.

class cajitaprincipal;

class cajitahijos{

private:

	cajitaprincipal* estenodo;
	cajitahijos* siguiente;

public:

	cajitahijos(cajitaprincipal*);
	cajitahijos();
    ~cajitahijos();
    void setEsteNodo(cajitaprincipal*);
	cajitaprincipal*& getEsteNodo();
	void setSiguiente(cajitahijos*);
	cajitahijos*& getSiguiente();

};


#endif // CAJITAHIJOS_H_INCLUDED
