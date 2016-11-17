#include <iostream>
#include "menu.h"
#include "modeloArbol.cpp"
#include "ColaPrueba.cpp"
#include "PilaPrueba.cpp"

//Desde esta clase se llaman a los operadores básicos y a los algoritmos.
//Para ellos se le pide al usuario que ingrese los argumentos necesarios para cada llamado.

prueba::prueba(){}

prueba::~prueba(){}

void prueba::menu(){

    string modelo;
    while(true){
        cout << "Con cual modelo deseas trabajar (cola | pila | arbol). Digita \"salir\" para acabar el programa: ";
        cin >> modelo;
        cout << endl;
        if(modelo == "salir"){
            return;
        }
        else if(modelo == "cola"){
            bool b =true;
            ColaPrueba c = ColaPrueba();
            cout << "Decidiste trabajar con el modelo cola, estos son sus operadores basicos: " << endl << endl;
            while (b){
                string operador;
                cout << "===============================================================================" << endl;
                cout << "crear | destruir | vaciar | vacia? | agregar | sacar | frente? | devolverse" << endl;
                cout << "===============================================================================" << endl;
                cout << "Opcion: ";
                cin >> operador;
                cout << endl;

                if(operador == "crear"){
                    c.crear();
                    cout << "La cola ha sido creada" << endl << endl;
                }
                else if(operador == "destruir"){
                    c.destruir();
                    cout << "La cola ha sido destruida" << endl << endl;
                }
                else if(operador == "vaciar"){
                    c.vaciar();
                    cout << "La cola esta ahora vacia" << endl << endl;
                }
                else if(operador == "vacia?"){
                    if(c.vacia())
                        cout << "La cola esta vacia" << endl << endl;
                    else
                        cout << "La cola no esta vacia" << endl << endl;
                }
                else if(operador == "agregar"){
                    int elemento; string selemento;
                    cout << "Que elemento deseas agregar a la cola? ";
                    cin >> selemento; stringstream(selemento) >> elemento;
                    c.agregar(elemento);
                    cout << "El elemento fue agregado correctamente a la cola" << endl << endl;
                }
                else if(operador == "sacar"){
                    c.sacar();
                    cout << "El elemento fue sacado correctamente de la cola" << endl << endl;
                }
                else if(operador == "frente?"){
                    cout << "El frente de la cola, es: " << c.frente() << endl << endl;
                }
                else if (operador == "devolverse"){
                    b = false;
                }
                else{
                    cout << "Digite un operador valido." << endl << endl;
                }
            }
        }
        else if(modelo == "pila"){
            bool b =true;
            PilaPrueba p = PilaPrueba();
            cout << "Decidiste trabajar con el modelo pila, estos son sus operadores basicos: " << endl;
            while (b){
                string operador;
                cout << "===============================================================================" << endl;
                cout << "crear | destruir | vaciar | vacia? | poner | quitar | tope? | devolverse" << endl;
                cout << "===============================================================================" << endl;
                cout << "Opcion : ";
                cin >> operador;
                cout << endl;
                if(operador == "crear"){
                    p.crear();
                    cout << "La pila ha sido creada" << endl << endl;
                }
                else if(operador == "destruir"){
                    p.destruir();
                    cout << "La pila ha sido destruida" << endl << endl;
                }
                else if(operador == "vaciar"){
                    p.vaciar();
                    cout << "La pila esta ahora vacia" << endl << endl;
                }
                else if(operador == "vacia?"){
                    if(p.vacia())
                        cout << "La pila esta vacia" << endl << endl;
                    else
                        cout << "La pila no esta vacia" << endl << endl;
                }
                else if(operador == "poner"){
                    int elemento; string selemento;
                    cout << "Que elemento deseas poner en la pila? ";
                    cin >> selemento;
                    stringstream(selemento) >> elemento;
                    p.poner(elemento);
                    cout << "Se ha puesto el elemento." << endl << endl;
                    cout << "" << endl;
                }
                else if(operador == "quitar"){
                    p.quitar();
                    cout << "Se ha quitado el elemento" << endl << endl;
                }
                else if(operador == "tope?"){
                    cout << "El tope de la pila, es: " << p.tope() << endl << endl;;
                }
                else if (operador == "devolverse"){
                    b = false;
                }
                else{
                    cout << "Digite un operador valido" << endl << endl;
                }
            }
        }
        else if(modelo == "arbol"){
            bool c = true;
            string opcion;
            cout << "Decidiste trabajar en el modelo arbol, deseas utilizar los operadores basicos, los algoritmos o devolverse (operadores | algoritmos | devolverse)? ";
            cin >> opcion;
            cout << endl;
            while(c){
                if(opcion == "operadores"){
                    bool b = true;
                    cout << "Estos son los operadores basicos: (cuenta con los arboles 1, 2 y 3)" << endl << endl;
                    while(b){
                        string operador;
                        cout << "===============================================================================" << endl;
                        cout << "crear | destruir | vaciar | vacio? | poneraiz | agregarhijo | borrarhoja | modificaretiqueta | raiz? | padre? | hijomasizquierdo? | hermanoderecho? | devolverse";
                        cout << "===============================================================================" << endl;
                        cout << "Opcion: ";
                        cin >> operador;
                        cout << endl;
                        if(operador == "crear"){
                            int ar; string sar; cout << "Cual arbol deseas crear (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.crear(a.devolverArbol(ar));
                            cout << "El arbol " << ar  << " ha sido creado" << endl << endl;
                        }
                        else if(operador == "destruir"){
                            int ar; string sar; cout << "Cual arbol deseas destruir (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.destruir(a.devolverArbol(ar));
                            cout << "El arbol " << ar << " ha sido destruido" << endl << endl;
                        }
                        else if(operador == "vaciar"){
                            int ar; string sar; cout << "Cual arbol deseas vaciar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.vaciar(a.devolverArbol(ar));
                            cout << "El arbol "<< ar  << " se ha vaciado" << endl << endl;
                        }
                        else if(operador == "vacio?"){
                            int arbol; string sarbol; cout << "Cual arbol deseas saber si esta vacio (1,2,3)? "; cin >> sarbol; stringstream(sarbol) >> arbol;
                            if(a.vacio(a.devolverArbol(arbol))) cout << "El arbol " << arbol  << " esta vacio" << endl;
                            else cout << "El arbol " << arbol  << " no esta vacio" << endl << endl;
                        }
                        else if(operador == "poneraiz"){
                            int arbol; string sarbol; cout << "A cual arbol ponerle raiz (1,2,3)? "; cin >> sarbol; stringstream(sarbol) >> arbol;
                            int etiqueta; string setiqueta; cout << "Que etiqueta deseas ponerle a la raiz? "; cin >> setiqueta; stringstream(setiqueta) >> etiqueta;
                            a.poneRaiz(etiqueta, a.devolverArbol(arbol));
                            cout << "La raiz " << etiqueta << " fue puesta en el arbol " << arbol << endl << endl;
                        }
                        else if(operador == "agregarhijo"){
                            int ar; string sar; cout << "En cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int pa; string spa; cout << "A que etiqueta deseas agregarle un hijo? "; cin >> spa; stringstream(spa) >> pa;
                            int eti; string seti; cout << "Que etiqueta deseas que lleve el nuevo hijo de " << spa << "? "; cin >> seti; stringstream(seti) >> eti;
                            int po; string spo; cout << "En que posicion deseas que este el nuevo hijo? "; cin >> spo; stringstream(spo) >> po;
                            a.agregarHijo(eti, po, a.traNodo(pa, a.devolverArbol(ar)), a.devolverArbol(ar));
                            cout << "El hijo " << eti << " fue agregado al padre con etiqueta " << pa << ", en el arbol " << ar << endl << endl;
                        }
                        else if(operador == "borrarhoja"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int ho; string sho; cout << "Cual es la etiqueta de la hoja que deseas borrar? "; cin >> sho; stringstream(sho) >> ho;
                            a.borrarHoja(a.traNodo(ho, a.devolverArbol(ar)), a.devolverArbol(ar));
                            cout << "El hoja " << ho << " fue borrada del arbol " << ar  << "." << endl << endl;
                        }
                        else if(operador == "modificaretiqueta"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "Cual es la etiqueta del nodo que deseas modificar? "; cin >> sno; stringstream(sno) >> no;
                            int neti; string sneti; cout << "Cual es la nueva etiqueta? "; cin >> sneti; stringstream(sneti) >> neti;
                            a.modifEtiqueta(neti, a.traNodo(no, a.devolverArbol(ar)), a.devolverArbol(ar));
                            cout << "La etiqueta en el arbol " << ar  << " fue modificada." << endl << endl;
                        }
                        else if (operador == "raiz?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            cout << "La raiz del arbol "<< ar  << " es: " << a.etiqueta(a.raiz(a.devolverArbol(ar)), a.devolverArbol(ar)) << endl << endl;
                        }
                        else if (operador == "padre?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int hi; string shi;cout << "El padre de cual etiqueta desea conocer? "; cin >> shi; stringstream(shi) >> hi;
                            cout << "El padre del nodo en el arbol " << ar  << " es: " << a.etiqueta(a.padre(a.traNodo(hi, a.devolverArbol(ar)), a.devolverArbol(ar)), a.devolverArbol(ar)) << endl << endl;
                        }
                        else if (operador == "hijomasizquierdo?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int pa; string spa; cout << "De que etiqueta deseas conocer el primer hijo? "; cin >> spa; stringstream(spa) >> pa;
                            cout << "El hijo mas izquierdo de " << pa << " en el arbol " << ar  <<" es: " << a.etiqueta(a.hijoMasIzq(a.traNodo(pa, a.devolverArbol(ar)), a.devolverArbol(ar)), a.devolverArbol(ar)) << endl << endl;
                        }
                        else if (operador == "hermanoderecho?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "De que etiqueta deseas conocer el hermano derecho? "; cin >> sno; stringstream(sno) >> no;
                            cout << "El hermano derecho del nodo en el arbol " << ar  << " es: " << a.etiqueta(a.herDer(a.traNodo(no, a.devolverArbol(ar)), a.devolverArbol(ar)), a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(operador == "devolverse"){
                                b = false;
                                cout << "Deseas cambiar de opcion (operadores | algoritmos | devolverse): ";
                                cin >> opcion;
                                cout << endl;
                        }
                        else{
                            cout << "Digite un operador basico valido" << endl << endl;
                        }
                    }
                }
                else if(opcion == "algoritmos"){
                    bool b = true;
                    cout << "Estos son los algoritmos: (cuenta con los arboles 1, 2 y 3)" << endl << endl;
                    while(b){
                        string algoritmo;
                        cout << "===============================================================================" << endl;
                        cout << "hermanoizquierdo? | etiquetasrepetidas? | alturanodo? | profundidadnodo? | nivelesarbol? | etiquetasdelniveli | etiquetashijos | numnodos? | borrarsubarbol | borrarytrasladar | copiararbol | soniguales? | listarpreorden | listarpostorden |listarinorden | listarnivelescola | listarpreordenpila | nodo? | devolverse" << endl;
                        cout << "===============================================================================" << endl;
                        cout << "Opcion: ";
                        cin >> algoritmo;
                        cout << endl;
                        if(algoritmo == "hermanoizquierdo?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "El hermano izquierdo de que nodo desea conocer? "; cin >> sno; stringstream(sno) >> no;
                            cout << "El hermano izquierdo del nodo " << no << ", es: " << a.etiqueta(a.herIzq(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar)),a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "etiquetasrepetidas?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            if(a.etiquetasRepetidas(a.devolverArbol(ar))){
                                cout << "El arbol " << ar << " si tiene etiquetas repetidas" << endl << endl;
                            }
                            else{
                                cout << "El arbol " << ar << " no tiene etiquetas repetidas" << endl << endl;
                            }
                        }
                        else if(algoritmo == "alturanodo?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "La altura de cual nodo desea saber? "; cin >> sno; stringstream(sno) >> no;
                            cout << "La altura del nodo " << no << ", es: " << a.altura(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "profundidadnodo?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "La profundidad de cual nodo desea saber? "; cin >> sno; stringstream(sno) >> no;
                            cout << "La profundidad del nodo " << no << ", es: " << a.profundidad(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "nivelesarbol?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            cout << "Los niveles del arbol " << ar << " son: " << a.niveles(a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "etiquetasdelniveli"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int i; string si; cout << "Las etiquetas de que nivel desea listar? "; cin >> si; stringstream(si) >> i;
                            a.listarEtiquetasDelNivel(i,a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "etiquetashijos"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "Los hijos de que nodo desea listar? "; cin >> sno; stringstream(sno) >> no;
                            a.listarEtiquetasHijos(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "numnodos?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            cout << "El numero de nodos del arbol " << ar << " es: " << a.cantidadNodos(a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "borrarsubarbol"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "A partir de cual nodo desea borrar? "; cin >> sno; stringstream(sno) >> no;
                            a.borrarSubArbol(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar));
                            cout << "El subarbol generado a partir del nodo " << no << " y el nodo " << no << " se han borrado" << endl << endl;
                        }
                        else if(algoritmo == "borrarytrasladar"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int no; string sno; cout << "A partir de cual nodo desea borrar? "; cin >> sno; stringstream(sno) >> no;
                            a.borrarNodoMoverSubArboles(a.traNodo(no,a.devolverArbol(ar)),a.devolverArbol(ar));
                            cout << "El subarbol generado a partir del nodo " << no << " se trasladado al padre de " << no << " y el nodo se ha borrado" << endl << endl;
                        }
                        else if(algoritmo == "copiararbol"){
                            int ar1; string sar1; cout << "Cual sera el primer arbol (1,2,3)? "; cin >> sar1; stringstream(sar1) >> ar1;
                            int ar2; string sar2; cout << "En que arbol se hara la copia (1,2,3)? "; cin >> sar2; stringstream(sar2) >> ar2;
                            a.copiarEn(a.devolverArbol(ar1),a.devolverArbol(ar2));
                            cout << "Ahora el arbol " << ar2 << " es una copia del arbol " << ar1 << endl << endl;
                        }
                        else if(algoritmo == "soniguales?"){
                            int ar1; string sar1; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar1; stringstream(sar1) >> ar1;
                            int ar2; string sar2; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar2; stringstream(sar2) >> ar2;
                            if(a.iguales(a.devolverArbol(ar1),a.devolverArbol(ar2))){
                                cout << "Los arboles " << ar1 << " y " << ar2 << " son iguales" << endl << endl;
                            }
                            else{
                                cout << "Los arboles " << ar1 << " y " << ar2 << " no son iguales" << endl << endl;
                            }
                        }
                        else if(algoritmo == "listarpreorden"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.listarPreOrden(a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "listarpostorden"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.listarPostOrden(a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "listarinorden"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.listarInOrden(a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "listarnivelescola"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.listarPorNivelesCola(a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "listarpreordenpila"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            a.listarPreOrdenPila(a.devolverArbol(ar)); cout << endl << endl;
                        }
                        else if(algoritmo == "nodo?"){
                            int ar; string sar; cout << "Con cual arbol deseas trabajar (1,2,3)? "; cin >> sar; stringstream(sar) >> ar;
                            int eti; string seti; cout << "Cual es la etiqueta del nodo que desea buscar? "; cin >> seti; stringstream(seti) >> eti;
                            cout << "El nodo con etiqueta " << eti << " tiene efectivamente, etiqueta " << a.etiqueta(a.buscarNodo(eti,a.devolverArbol(ar)),a.devolverArbol(ar)) << endl << endl;
                        }
                        else if(algoritmo == "devolverse"){
                            b = false;
                            cout << "Deseas cambiar de opcion (operadores | algoritmos | devolverse): ";
                            cin >> opcion;
                            cout << endl;
                        }
                        else{
                            cout << "Digite un algoritmo valido" << endl << endl;
                        }
                    }
                }
                else if(opcion == "devolverse"){
                    c = false;
                    if(!a.vacio(a.devolverArbol(1)))
                        a.destruir(a.devolverArbol(1));
                    if(!a.vacio(a.devolverArbol(2)))
                        a.destruir(a.devolverArbol(2));
                    if(!a.vacio(a.devolverArbol(3)))
                        a.destruir(a.devolverArbol(3));
                }
                else{
                    cout << "Digite una opcion valida: ";
                    cin >> opcion;
                    cout << endl;
                }
            }
        }
    }
}
