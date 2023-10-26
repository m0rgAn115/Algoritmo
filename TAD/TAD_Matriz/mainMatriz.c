#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

void manejaMsg(int);

void llenarMatriz(MATRIZ m){
    printf("\n--LLENAR MATRIZ--\nIngrese los elementos de la matriz. \n");
    for (int i = 0; i < m->filas; i++){
        for (int j = 0; j < m->columas; j++){
            printf("[%d][%d]: ",i+1,j+1);
            scanf("%d",&m->elementos[i][j]);
        }
    }
    
}

void imprimirMatriz(MATRIZ m){
    printf("\n");
    for (int i = 0; i < m->filas; i++){
        printf("\n|");
        for (int j = 0; j < m->columas; j++){
            printf("  %d ",m->elementos[i][j]);
        }
        printf("|");

    }
}

void main(){
    MATRIZ m1,m2,m3,m4;
    m1 = crearMatriz(3,3);
    m2 = crearMatriz(3,3);
    m4 = crearMatriz(2,4);

    llenarMatriz(m1);
    llenarMatriz(m2);

    imprimirMatriz(m1);
    asignaValor(m1,0,0,3);
    imprimirMatriz(m1);

    printf("\nResultado de la suma entre m1 y m2");
    imprimirMatriz(sumaMatriz(m1,m2));

    printf("\nResultado de la resta entre m1 y m2");
    imprimirMatriz(restaMatriz(m1,m2));

    printf("\nResultado de la multiplicacion entre m1 y m2");
    imprimirMatriz(multiplicacionMatriz(m1,m2));

    imprimirMatriz(transpuesta(m1));

}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}