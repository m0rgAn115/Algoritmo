#include<stdlib.h>
#include "pila.h"

void manejaMsg(int);

PILA crearPila(){
    PILA S;
    S = (PILA) malloc(sizeof(Pila));
    if(S==NULL){
        manejaMsg(0);
        exit(0);
    }

    S->tope = -1;
    return S;
}

int esVacia(PILA S){
    return S->tope<0 ? TRUE : FALSE;
}

void apilar(PILA S,int e){
    if(S->tope == TAMPILA-1){
        manejaMsg(2);
        exit(0);
    }

    S->tope++;
    S->pila[S->tope] = e;
}

int desapilar(PILA S){
    int v;
    if(esVacia(S) == TRUE){
        manejaMsg(3);
        exit(0);
    }

    v = S->pila[S->tope--];
    return v;
}

int elemTope(PILA S){
    int v;
    if(esVacia(S)==TRUE){
        manejaMsg(3);
        exit(0);
    }
    v= desapilar(S);
    apilar(S,v);
    return v;
}