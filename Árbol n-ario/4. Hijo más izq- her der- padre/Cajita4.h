#ifndef CAJITAHHDP_H_INCLUDED
#define CAJITAHHDP_H_INCLUDED
#include <iostream>
using namespace std;

class cajita4{

private:

    cajita4* hijoMasIzq;
    cajita4* herDer;
    cajita4* padre;
    int etiqueta;

public:

    cajita4() : hijoMasIzq(0), herDer(0), padre(0){}

    cajita4(int e, cajita4* p) : hijoMasIzq(0), herDer(0), padre(p), etiqueta(e){}

    ~cajita4(){}

    void setHijoMasIzq(cajita4* c){
        hijoMasIzq = c;
    }

    cajita4* getHijoMasIzq(){
        return hijoMasIzq;
    }

    void setHerDer(cajita4* c){
        herDer = c;
    }

    cajita4* getHerDer(){
        return herDer;
    }

    void setPadre(cajita4* p){
        padre = p;
    }

    cajita4* getPadre(){
        return padre;
    }

    void setEtiqueta(int e){
        etiqueta = e;
    }

    int getEtiqueta(){
        return etiqueta;
    }

};

#endif // CAJITA_H_INCLUDED
