#include<stdio.h>
#include<stdlib.h>
#include "pila.h"

void llenarPila(PILA S){
    int n;
    printf("\nIngrese datos para la pila (Si ingresa -1 dejara de ingresar): ");
    while(n!=-1){
        printf("\nIngrese el dato: ");
        scanf("%d",&n);
        if(n!=-1)
            apilar(S,n);
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","PILA VACIA","PILA LLENA"};
     printf("%s", mensajes[msg] );
}
void mostrarPila(PILA S){
    PILA Copia = S;
    int e;
    printf("\n[");
    while(!esVacia(Copia)){
        printf("  %d ",desapilar(Copia));
    }
    printf("]");
}

void main(){
    PILA S;
    S=crearPila();
    llenarPila(S);
    mostrarPila(S);
}
