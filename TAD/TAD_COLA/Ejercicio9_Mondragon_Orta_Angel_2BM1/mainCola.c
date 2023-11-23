#include<stdio.h>
#include<stdlib.h>
#include "cola.h"

void llenarCola(COLA S){
    int n = 0;
    printf("\nIngrese datos para la pila (Si ingresa -1 dejara de ingresar): ");
    while(n!=-1){
        printf("\nIngrese el dato: ");
        scanf("%d",&n);
        if(n!=-1)
            encolar(S,n);
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"\nNo hay memoria disponible . . .","\nSe ha liberado la memoria . . .  ","\nCOLA VACIA","\nCOLA LLENA"};
     printf("%s", mensajes[msg] );
}

void mostrarCola(COLA C){
    Cola copia = *C;
    printf("\n[");
    while(!es_vaciaCola(&copia)){
        printf(" %d ",desencolar(&copia));
    }
    printf("]");
}

int obtenUltimo(COLA C){
    int  ult;
    Cola Copia = *C;

    while(!es_vaciaCola(&Copia)){
        ult = desencolar(&Copia);
    }

    return ult;
}

void intercambia(COLA C){
    
    int prim = primero(C);

    int  ult = obtenUltimo(C);

    COLA aux = crearCola();

    while(!es_vaciaCola(C)){
        int e = desencolar(C);

        if(es_vaciaCola(aux)){
            encolar(aux,ult);
        }else if(es_vaciaCola(C)){
            encolar(aux,prim);
        }else{
            encolar(aux,e);
        }
    }

    *C = *aux;
}



void liberarMemoria(COLA S){
    free(S);
    manejaMsg(1);
}

void main(){
    COLA C = crearCola();

    llenarCola(C);
    mostrarCola(C);
    intercambia(C);
    mostrarCola(C);

    liberarMemoria(C);
}