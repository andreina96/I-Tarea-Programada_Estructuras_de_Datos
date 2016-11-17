#include "cajitaprincipal.h"
#include <iostream>

cajitaprincipal::cajitaprincipal() : siguiente(0), primero(0){}

cajitaprincipal::cajitaprincipal(int e) : etiqueta(e), siguiente(0), primero(0){}

cajitaprincipal::~cajitaprincipal(){}

void cajitaprincipal::setEtiqueta(int e){
	etiqueta = e;
}

int cajitaprincipal::getEtiqueta(){
	return etiqueta;
}

void cajitaprincipal::setSiguiente(cajitaprincipal* s){
	siguiente = s;
}

cajitaprincipal* cajitaprincipal::getSiguiente(){
	return siguiente;
}

void cajitaprincipal::setPrimero(cajitahijos* p){
	primero = p;
}

cajitahijos* cajitaprincipal::getPrimero(){
	return primero;
}
