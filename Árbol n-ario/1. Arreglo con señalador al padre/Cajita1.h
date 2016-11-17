#ifndef CAJITA1_H_INCLUDED
#define CAJITA1_H_INCLUDED

//esta es la cajita de la que esta hecho el array, contiene un señalador al padre que en este caso en un int y su propia etiqueta.

class cajita1{

private:

    int etiqueta;
    int padre;

public:

    void setEtiqueta(int e){
        etiqueta = e;
    }

    int getEtiqueta(){
        return etiqueta;
    }

    void setPadre(int p){
        padre = p;
    }

    int getPadre(){
        return padre;
    }
};

#endif // CAJITA_H_INCLUDED
