#include<stdio.h>
#include "vector.h"
#include<stdlib.h>

void mostrarVector(VECTOR);
void manejaMsg(int);

void main(){
    VECTOR v1,v2,v3,v4;
    v1 = crearVector(3,1);
    v2 = crearVector(3,1);

    mostrarVector(v1);
    asignaComponente(v1,0,9);
    mostrarVector(v1);
    printf("\nEl tamanio de v1 es: %d",obtenTam(v1));

    v3 = sumaVector(v1,v2);
    mostrarVector(v1);
    mostrarVector(v2);
    printf("\nLa suma del v1 y v2 es: ");
    mostrarVector(v3);

    v3 = restaVector(v1,v2);
    printf("\nLa resta del v1 y v2 es: ");
    mostrarVector(v3);

    printf("\nEl producto Punto de v1 y v2 es: %d",productoPunto(v1,v2));

    printf("\nCOMP = %d",obtenTam(v1));
}

void mostrarVector(VECTOR v){
    printf("\n[");
    for (int i = 0; i < obtenTam(v); i++)
    {
        printf(" %d ",v->componentes[i]);
    }
    printf("]");
}