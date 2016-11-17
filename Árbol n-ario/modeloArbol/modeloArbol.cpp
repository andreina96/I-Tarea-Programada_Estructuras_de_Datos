#include "modeloArbol.h"
#include "modeloCola.cpp"
#include "modeloPila.cpp"
#include "cajita.h"
/* ======================= Arbol1 : arreglo con señalador al padre ============================== */
//#include "arbol1.cpp"
/* ======================= Arbol2 : lista de hijos ============================================== */
//#include "arbol2.cpp"
//#include "cajitahijos.cpp"
//#include "cajitaprincipal.cpp"
/* ======================= Arbol3 : hijo más izquierdo- hermano derecho ========================= */
//#include "arbol3.cpp"
/* ======================= Arbol4 : hijo más izquierdo- hermano derecho- puntero al padre ======= */
#include "arbol4.cpp"

typedef cajitapila* caPi;

/*================================================Operadores básicos====================================================*/
/*======================================================================================================================*/

//Los operadores básicos nada más llaman a su respectivo operador básico según la implementacion que se utilice.

modeloArbol::modeloArbol(){}

modeloArbol::~modeloArbol(){}

arbol& modeloArbol::devolverArbol(int i){
    if(i == 1)
        return a;
    else if(i == 2)
        return b;
    else
        return c;
}

void modeloArbol::crear(arbol &ar){
    ar.crear();
}

void modeloArbol::destruir(arbol &ar){
    ar.destruir();
}

void modeloArbol::vaciar(arbol &ar){
    ar.vaciar();
}

bool modeloArbol::vacio(arbol &ar){
    return ar.vacio();
}

void modeloArbol::poneRaiz(int etiqueta, arbol &ar){
    ar.poneRaiz(etiqueta);
}

void modeloArbol::agregarHijo(int etiqueta, int posicion, nodo n, arbol &ar){
    ar.agregarHijo(etiqueta, posicion, n);
}

void modeloArbol::borrarHoja(nodo n, arbol &ar){
    ar.borrarHoja(n);
}

void modeloArbol::modifEtiqueta(int etiqueta, nodo n, arbol &ar){
    ar.modifEtiqueta(etiqueta, n);
}

nodo modeloArbol::raiz(arbol &ar){
    return ar.raiz();
}

nodo modeloArbol::padre(nodo n, arbol &ar){
    return ar.padre(n);
}

nodo modeloArbol::hijoMasIzq(nodo n, arbol &ar){
    return ar.hijoMasIzq(n);
}

nodo modeloArbol::herDer(nodo n, arbol &ar){
    return ar.herDer(n);
}

int modeloArbol::etiqueta(nodo n, arbol &ar){
    return ar.etiqueta(n);
}

nodo modeloArbol::traNodo(int etiqueta, arbol &ar){
    return ar.traNodo(etiqueta);
}

/*====================================================Algoritmos========================================================*/
/*======================================================================================================================*/

 nodo modeloArbol::herIzq(nodo n, arbol &ar){  //este algoritmo se va al padre y de ahí busca entre todos sus hijos al que se llamo
	nodo nh = ar.hijoMasIzq(ar.padre(n));      //quien tenga a este nodo como hermano derecho es su hermano izquierdo.
	if(nh == n)
		return nodoNulo;
	else{
		while(ar.herDer(nh) != n){
			nh = ar.herDer(nh);
		}
        return nh;
    }
    return nodoNulo;
 }

bool modeloArbol::etiquetasRepetidas(arbol &ar){    //este algoritmo realiza dos recorridos en preOrden, el primero para pararse una vez en cada nodo
	bool resultado = false;                         //el segundo para una vez estando en ese nodo, comparar su etiqueta con la de todos los demás nodos.
	if(!ar.vacio())
		etiquetasRec1(ar.raiz(), ar, resultado);
	return resultado;
}

void modeloArbol::etiquetasRec1(nodo n, arbol &ar, bool &resultado){
	if(resultado == 1)
		return;
	etiquetasRec2(ar.raiz(), n, ar, resultado);
	nodo nh = ar.hijoMasIzq(n);
	while(nh != nodoNulo){
		etiquetasRec1(nh, ar, resultado);
		nh = ar.herDer(nh);
	}
}

void modeloArbol::etiquetasRec2(nodo n1, nodo n2, arbol &ar, bool &resultado){
	if((ar.etiqueta(n1) == ar.etiqueta(n2)) && (n1 != n2))   //compara el nodo con el que se entro a este llamado recursivo (N1) y el noo por el nos vamos moviendo (N2)
        resultado = 1;                                       //ademas pregunta si no son iguales, porque si lo fueran de fijo tienen la misma etiqueta.
	if(resultado)
		return;
	nodo nh = ar.hijoMasIzq(n1);
	while(nh != nodoNulo){
		etiquetasRec2(nh, n2, ar, resultado);
		nh = ar.herDer(nh);
	}
}

int modeloArbol::altura(nodo n, arbol &ar){  //recorrido en PreOrden llevando un contador de altura temporal que compara con la altura maxima
	int altura = 0;                          //que llevemos hasta el momento.
	if(n != nodoNulo)
		alturaRec(n, altura,  0, a);
	return altura;
}

void modeloArbol::alturaRec(nodo np, int &altura, int alturaTemporal, arbol &ar){
	if(ar.hijoMasIzq(np) != nodoNulo){
		nodo nh = ar.hijoMasIzq(np);
		alturaTemporal++;             //cada llamado hacia un hijo le suma uno a la altura temporal.
		while(nh != nodoNulo){
			alturaRec(nh,altura ,alturaTemporal, a);
			nh = ar.herDer(nh);
		}
	}
	else{
		if(alturaTemporal > altura) //si al llegar a una hoja la altura temporal es mayor a la maxima, entonces la altura maxima sera la temporal.
			altura = alturaTemporal;
	}
}

int modeloArbol:: profundidad(nodo n, arbol &ar){  //pregunta cuantos llamados al padre tuvo que hacer para llegar hasta la raiz.
    int profundidad = 0;
    while (ar.padre(n) != nodoNulo){
        n = ar.padre(n);
        profundidad++;
    }
    return profundidad;
}

int modeloArbol::niveles(arbol &ar){            //pregunta por la altura de la raiz.
    return 1 + altura(ar.raiz() ,a);
}

void modeloArbol::listarEtiquetasDelNivel(int nivel, arbol &ar){    //realiza un recorrido en preorden
    if(!ar.vacio())
        listarEtiquetasDelNivelRec(nivel, 1, ar.raiz(), ar);
}

void modeloArbol::listarEtiquetasDelNivelRec(int nivel, int nivelActual, nodo n, arbol &ar){
    if(nivel == nivelActual)                       //imprime solamente si esta en el nivel deseado
        cout << ar.etiqueta(n) << ".";
    nodo nh = ar.hijoMasIzq(n);
    nivelActual++;
    while(nh != nodoNulo && nivelActual <= nivel){  //solamente hace mas llamados si el nivelActual es menor o igual al nivel deseado para ser más optimo
        listarEtiquetasDelNivelRec(nivel, nivelActual, nh, ar);
        nh = ar.herDer(nh);
    }
}

void modeloArbol::listarEtiquetasHijos(nodo papa, arbol &ar){   //se va al papa y de ahi lista a todos los hijos
    nodo nh = ar.hijoMasIzq(papa);
	while(nh != nodoNulo){
		cout << ar.etiqueta(nh) << "." ;
		nh = ar.herDer(nh);
	}
}

int modeloArbol::cantidadNodos(arbol &ar){ //recorrido en preorden
    int cantidad = 1;
    if(!ar.vacio()){
        cantidadNodosRec(ar.raiz(), cantidad, ar);
        return cantidad;
    }
    else return 0;
}

void modeloArbol::cantidadNodosRec(nodo n, int &cantidad, arbol &ar){
    nodo nh = ar.hijoMasIzq(n);
    while(nh != nodoNulo){
        cantidad++;                      //se actualiza antes del llamado.
        cantidadNodosRec(nh, cantidad, ar);
        nh = ar.herDer(nh);
    }
}

void modeloArbol::borrarSubArbol(nodo n, arbol &ar){   //recorrido en post orden del arbol
    if(!ar.vacio())
        borrarSubArbolRec(n, ar);
}

void modeloArbol::borrarSubArbolRec(nodo n, arbol &ar){
	nodo nh = ar.hijoMasIzq(n);
	while(nh != nodoNulo){
		nodo na = ar.herDer(nh);
		borrarSubArbolRec(nh, ar);
		nh = na;
	}
	ar.borrarHoja(n);     //se borra hasta despues de haber borrado a todos sus hijos recursivamente
}

void modeloArbol::borrarNodoMoverSubArboles(nodo aBorrar, arbol& ar){
    int p = 1;
    arbol auxiliar = arbol();   //se crea un arbol auxiliar
    copiarGeneral(ar, aBorrar, auxiliar, nodoNulo, 0);   //copia el sub arbol generado a partir del nodo al nuevo arbol auxiliar
    nodo n = ar.hijoMasIzq(ar.padre(aBorrar));
    while (n != aBorrar){                              //modifica p para que se la posicion del primer hijo del nodo que borramos en su nuevo pare.
        n = ar.herDer(n);                              //para ello recorre todos los hijos del padre del nodo que vamos a borrar hasta encontrarse con este
        p++;
    }
    nodo nh = auxiliar.hijoMasIzq(auxiliar.raiz());
    while (nh != nodoNulo){                           //copia a todos los hijos del nodo que vamos a borrar a su nuevo padre
        copiarGeneral(auxiliar, nh, ar, ar.padre(aBorrar), p);
        nh = auxiliar.herDer(nh);
        p++;
    }
    auxiliar.destruir();
    borrarSubArbol(aBorrar, ar);   //finalmente borramos todo el sub arbol
}

void modeloArbol::copiarGeneral(arbol &ar1, nodo raizSubArbol, arbol &ar2, nodo nuevoPadre, int nuevaPosicion){
    int posicion;                             //este copiar general es muy parecido al copiar solamente que no copia todo el arbol, si no solamente desde un nodo deseado.
    modeloCola c1 = modeloCola();             //y no lo copia a un arbol vacio, si no que lo copia como un hijo de otro arbol en una cierta posicion.
    modeloCola c2 = modeloCola();
    c1.crear();
    c2.crear();
    c1.agregar(raizSubArbol);
    if(nuevoPadre == nodoNulo){       //si no queremos un nuevo padre, el copiar es igual.
        ar2.poneRaiz(ar1.etiqueta(raizSubArbol));
        c2.agregar(ar2.raiz());
    }
    else{                             //sii queremos un nuevo padre, le agregamos este nodo al nuevo padre y en la cola dos lo metemos al, en vez de a la raiz.
        ar2.agregarHijo(ar1.etiqueta(raizSubArbol), nuevaPosicion, nuevoPadre);
        nodo n = ar2.hijoMasIzq(nuevoPadre);
        for(int i = 1; i < nuevaPosicion; i++){
            n = ar2.herDer(n);
        }
        c2.agregar(n);
    }
    while(!c1.vacia()){     //a partir de aquí funciona igual al copiar
        posicion = 1;
        nodo np1 = c1.frente();
        nodo np2 = c2.frente();
        c1.sacar();
        c2.sacar();
        nodo nh1 = ar1.hijoMasIzq(np1);
        while (nh1 != nodoNulo){
            ar2.agregarHijo(ar1.etiqueta(nh1), posicion, np2);
            c1.agregar(nh1);
            nodo nh2 = ar1.hijoMasIzq(np2);
            for(int i = 1; i < posicion; i++){
                nh2 = ar2.herDer(nh2);
            }
            c2.agregar(nh2);
            posicion++;
            nh1 = ar1.herDer(nh1);
        }
    }
}

void modeloArbol::copiarEn(arbol &ar1, arbol &ar2){  //este copiar es basicamente un recorrido en niveles por dos arboles
    if(!ar1.vacio()){
        int posicion;
        modeloCola c1 = modeloCola();
        modeloCola c2 = modeloCola();
        c1.crear();
        c2.crear();
        c1.agregar(ar1.raiz());                //la cola 1 simula el recorrido por niveles del primer arbol
        ar2.poneRaiz(ar1.etiqueta(ar1.raiz()));
        c2.agregar(ar2.raiz());               //la cola 2 simula el recorrido por niveles del segundo arbol.
        while(!c1.vacia()){                   //esta cola va atrasada y sus elementos siempre se meten luego de que se ha metido un hijo al arbol nuevo
            posicion = 1;
            nodo np1 = c1.frente();
            nodo np2 = c2.frente();
            c1.sacar();
            c2.sacar();
            nodo nh1 = ar1.hijoMasIzq(np1);       //tomamos el frente de la cola como el padre de los nuevos hijos que vamos a insertar en la cola
            while(nh1 != nodoNulo){
                ar2.agregarHijo(ar1.etiqueta(nh1), posicion, np2);  //metemos al hijo en el nevo arbol
                c1.agregar(nh1);                                   //agregamos a TODOS los hijos de nh1
                nodo nh2 = ar1.hijoMasIzq(np2);
                for(int i = 1; i < posicion; i++){                //tenemos que buscar en que posicion metimos al nodo
                    nh2 = ar2.herDer(nh2);
                }
                c2.agregar(nh2);                                 //una vez encontrada la posicion, agregamos a este ultimo nuevo nodo a la segunda cola
                posicion++;
                nh1 = ar1.herDer(nh1);
            }
        }
        c1.destruir();
        c2.destruir();
    }
}

bool modeloArbol::iguales(arbol &ar1, arbol &ar2){    //un recorrido en preOrden por dos arboles
    bool igualesb = true;
    if(!(ar1.vacio() && ar2.vacio())){
        if(!(cantidadNodos(ar1) == cantidadNodos(ar2))){
            igualesb = false;
        }
        else{
            igualesRec(ar1.raiz(), ar2.raiz(), ar1, ar2, igualesb);
        }
    }
    return igualesb;
}

void modeloArbol::igualesRec(nodo n1, nodo n2, arbol &ar1, arbol &ar2, bool &igualesb){
    if((ar1.etiqueta(n1)) != (ar2.etiqueta(n2)))
        igualesb = false;
    if(igualesb == false)
        return;
    nodo nh1 = ar1.hijoMasIzq(n1);
    nodo nh2 = ar2.hijoMasIzq(n2);
	while((nh1 != nodoNulo) && (nh2 != nodoNulo)){
		igualesRec(nh1, nh2, ar1, ar2, igualesb);
		nh1 = ar1.herDer(nh1);
		nh2 = ar2.herDer(nh2);
	}
}

void modeloArbol::listarPreOrden(arbol &ar){      //recorrido en preorden
    if(!ar.vacio())
        listarPreOrdenRec(ar.raiz(), ar);
}

void modeloArbol::listarPreOrdenRec(nodo n, arbol &ar){
    cout <<  ar.etiqueta(n) << ".";
    nodo nh = ar.hijoMasIzq(n);
    while(nh != nodoNulo){
        listarPreOrdenRec(nh, ar);
        nh = ar.herDer(nh);
    }
}

void modeloArbol::listarPostOrden(arbol &ar){   //recorrido en preorden pero llamando al final de llamar a todos sus hijos
    if(!ar.vacio())
        listarPostOrdenRec(ar.raiz(), ar);
}

void modeloArbol::listarPostOrdenRec(nodo n, arbol &ar){
    nodo nh = ar.hijoMasIzq(n);
    while(nh != nodoNulo){
        listarPostOrdenRec(nh, ar);
        nh = ar.herDer(nh);
    }
    cout << ar.etiqueta(n) << ".";
}

void modeloArbol::listarInOrden(arbol &ar){   //recorrido en preorden pero llamandose hasta luego de haber llamado a su hijo izquierdo
    if(!ar.vacio())
        listarInOrdenRec(ar.raiz(), ar);
}

void modeloArbol::listarInOrdenRec(nodo n, arbol &ar){
    nodo nh = ar.hijoMasIzq(n);
    if(nh != nodoNulo)
        listarInOrdenRec(nh, ar);
    cout << ar.etiqueta(n) << ".";
    if(nh != 0){
        nh = ar.herDer(nh);
        while(nh != nodoNulo){
            listarInOrdenRec(nh, ar);
            nh = ar.herDer(nh);
        }
    }
}

void modeloArbol::listarPorNivelesCola(arbol &ar){  //recorrido utilizando la pila
    if(!ar.vacio()){
        modeloCola c1 = modeloCola();
        c1.crear();
        c1.agregar(ar.raiz());
        while(!c1.vacia()){                       //cada vez que se saca un elemento, este mete a TODOS sus hijos
            nodo np1 = c1.frente();
            cout << ar.etiqueta(np1) << ".";
            c1.sacar();
            nodo nh1 = ar.hijoMasIzq(np1);
            while(nh1 != nodoNulo){
                c1.agregar(nh1);
                nh1 = ar.herDer(nh1);
            }
        }
        c1.destruir();
    }
}

void modeloArbol::listarPreOrdenPila(arbol &ar){    //se usa la pila para simular el recorrido en preorden
    modeloPila p = modeloPila();
    p.crear();
    p.poner(ar.raiz());
	while(!p.vacia()){
        caPi cp = p.tope();
        nodo n = cp->getElemento();               //cp es el nodo que esta en la pila
		if(cp->getVisitado() == false){           //si es la primera vez que pasamos por este nodo los imprimimos y metemos a su hijo mas izquierdo
			cout << ar.etiqueta(n)<< "." << endl;
			if(ar.hijoMasIzq(n) != nodoNulo){
				p.poner(ar.hijoMasIzq(n));
			}
			cp->setVisitado(true);
		}
		else if(ar.herDer(n) != nodoNulo){        //si ya pasamos, entonces lo sacamos de la pila y ponemos a su hermano derecho
			nodo nh = ar.herDer(n);
			p.quitar();
			p.poner(nh);
		}
		else{
            p.quitar();
            cp->setVisitado(true);
		}
	}
	p.destruir();
}

nodo modeloArbol::buscarNodo(int etiqueta, arbol &ar){   //recorrido en preorden que compara las etiquetas con la del nodo que nos pidieron
    nodo n = 0;
    if(!ar.vacio())
        buscarNodoRec(etiqueta, ar.raiz(), n, ar);
    return n;
}

void modeloArbol::buscarNodoRec(int etiqueta, nodo n1, nodo &n2, arbol &ar){
    if(ar.etiqueta(n1) == etiqueta)
        n2 = n1;
    if(n2 != 0)
        return;
    nodo nh = ar.hijoMasIzq(n1);
    while(nh != nodoNulo){
        buscarNodoRec(etiqueta, nh, n2, ar);
        nh = ar.herDer(nh);
    }
}
