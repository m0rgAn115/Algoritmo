#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "vector.h"

void manejaMsg(int);

VECTOR crearVector(int n,int opc){
    VECTOR v;
    v = (VECTOR) malloc(sizeof(Vector));
    v->componentes = (int*) malloc(sizeof(int) * n);

    v->tam = n;

    if( v->componentes == NULL){
         manejaMsg(0);
         exit(0);
    }
    if(opc==1)
        for(int i=0;i<obtenTam(v);i++){
            printf("\nIngrese el elemento [%d] del vector: ",i+1);
            scanf("%d",&v->componentes[i]);
        }

    return v;
}

int obtenComponente(VECTOR v,int n){
    return v->componentes[n];
}

VECTOR asignaComponente(VECTOR v, int posicion, int elemento){
    v->componentes[posicion] = elemento;
    return v;
}

int obtenTam(VECTOR v){
    return v->tam;
}

VECTOR sumaVector(VECTOR v1, VECTOR v2){
    if(obtenTam(v1)==obtenTam(v2)){
        VECTOR vResultante = crearVector(obtenTam(v1),0);

        for (int i = 0; i < obtenTam(v1); i++){
            int suma = obtenComponente(v1,i) + obtenComponente(v2,i);
            asignaComponente(vResultante,i,suma);
        }

        return vResultante;
    }else{
        printf("\nLos vectores no son del mismo tamaño!");
        return NULL;
    }
}

VECTOR restaVector(VECTOR v1, VECTOR v2){
    if(obtenTam(v1)==obtenTam(v2)){
        VECTOR vResultante = crearVector(obtenTam(v1),0);

        for (int i = 0; i < obtenTam(v1); i++){
            int resta = obtenComponente(v1,i) - obtenComponente(v2,i);
            asignaComponente(vResultante,i,resta);
        }

        return vResultante;
    }else{
        printf("\nLos vectores no son del mismo tamaño!");
        return NULL;
    }
}

int productoPunto(VECTOR v1, VECTOR v2){
    if(obtenTam(v1)==obtenTam(v2)){
        VECTOR vResultante = crearVector(obtenTam(v1),0);
        int sumatoria = 0;

        for (int i = 0; i < obtenTam(v1); i++){
            sumatoria += v1->componentes[i] * v2->componentes[i];
        }

        return sumatoria;
    }else{
        printf("\nLos vectores no son del mismo tamaño!");
        return 0;
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
