#include "cajitahijos.h"

cajitahijos::cajitahijos(cajitaprincipal* en) : estenodo(en), siguiente(0){}

cajitahijos::cajitahijos() : estenodo(0), siguiente(0){}

cajitahijos::~cajitahijos(){}

void cajitahijos::setEsteNodo(cajitaprincipal* en){
	estenodo = en;
}

cajitaprincipal*& cajitahijos::getEsteNodo(){
	return estenodo;
}

void cajitahijos::setSiguiente(cajitahijos* hermano){
	siguiente = hermano;
}

cajitahijos*& cajitahijos::getSiguiente(){
	return siguiente;
}
