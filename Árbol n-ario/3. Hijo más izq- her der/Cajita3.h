#ifndef CAJITAHMI_HD_H_INCLUDED
#define CAJITAHMI_HD_H_INCLUDED

//cajita de la implementacion hijo más izquierdo hermano derecho, este es el nodo de cada arbol
//tiene su etiqueta, un señalador a su hijo mas izquierdo y un señalador a su hermano derecho.

class cajita3{

private:

    int etiqueta;
    cajita3* hijoMasIzq;
    cajita3* herDer;

public:

    cajita3() : hijoMasIzq(0), herDer(0){}

    cajita3(int e) : etiqueta(e), hijoMasIzq(0), herDer(0){}

    ~cajita3(){}

     void setEtiqueta(int e){
        etiqueta = e;
    }

    int getEtiqueta(){
        return etiqueta;
    }

    void setHijoMasIzq(cajita3* c){
        hijoMasIzq = c;
    }

    cajita3* getHijoMasIzq(){
        return hijoMasIzq;
    }

    void setHerDer(cajita3* c){
        herDer = c;
    }

    cajita3* getHerDer(){
        return herDer;
    }

};

#endif // CAJITAHMI__H_INCLUDED
