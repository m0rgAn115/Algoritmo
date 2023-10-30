#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int pila[TAMPILA];
    int tope;
} Pila;

typedef Pila *PILA;

PILA crearPila();
int esVacia(PILA);
void apilar(PILA,int);
int desapilar(PILA);
int elemTope(PILA);

#endif