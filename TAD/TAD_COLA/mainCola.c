#include<stdio.h>
#include "cola.h"

void llenarCola(COLA S){
    int n;
    printf("\nIngrese datos para la pila (Si ingresa -1 dejara de ingresar): ");
    while(n!=-1){
        printf("\nIngrese el dato: ");
        scanf("%d",&n);
        if(n!=-1)
            encolar(S,n);
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","COLA VACIA","COLA LLENA"};
     printf("%s", mensajes[msg] );
}

void mostrarCola(COLA C){
    Cola copia = *C;

    printf("\n[");
    while(!es_vaciaCola(&copia)){
        printf("%d",desencolar(&copia));
    }
    printf("\n]");
}

void main(){
    COLA C = crearCola();

    llenarCola(C);
    mostrarCola(C);
}