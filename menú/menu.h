#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "modeloArbol.h"
#include "modeloCola.h"
#include "modeloPila.h"
#include "ColaPrueba.h"
#include "PilaPrueba.h"
#include <string>
#include <sstream>
using namespace std;

class prueba{

public:

    modeloArbol a;
    prueba();
    ~prueba();
    void menu();

};

#endif // MENU_H_INCLUDED
