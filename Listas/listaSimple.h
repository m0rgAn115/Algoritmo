#ifndef _listaSimple_
#define _listaSimple_

#define TRUE 1
#define FALSE 0

typedef struct Nodo_Lista{
    int dato;
    struct Nodo_Lista * siguiente; 
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

LISTA crearLista();
int es_vaciaLista(LISTA);
Nodo_Lista * crearNodoLista();
LISTA insertar(LISTA , int );
void visualizaLista(LISTA );
void  buscarElem(LISTA , int );
LISTA borrar(LISTA , int );
void mostrar(int , int , int );
LISTA insertarEnPosicion(LISTA , int , int );
int obtenTamLista(LISTA);


#endif