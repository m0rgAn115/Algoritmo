#ifndef _listaSimple_
#define _listaSimple_

#define TRUE 1
#define FALSE 0

typedef struct{
    int clave;
    char nombre[30];
    float precio;
} Producto;

typedef struct Nodo_Lista{
    Producto dato;
    struct Nodo_Lista * siguiente; 
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

LISTA crearLista();
int es_vaciaLista(LISTA);
Nodo_Lista * crearNodoLista();
LISTA insertar(LISTA , Producto );
void visualizaLista(LISTA );
void  buscarElem(LISTA , int );
LISTA borrar(LISTA , int );
void mostrar(int , int , int );
LISTA insertarEnPosicion(LISTA , int , Producto );
int obtenTamLista(LISTA);


#endif