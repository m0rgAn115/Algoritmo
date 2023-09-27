#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    float x;
    float y;
}Punto;

Punto *crearPunto(){
    Punto *P;

    P = (Punto*) malloc(sizeof(Punto));

    printf("\nDigite los valores [x,y] del punto A: ");
    scanf("%f%f",&P->x,&P->y);
    return P;
}

void puntoMedio(Punto *A,Punto *B){
    printf("\nEl punto medio entre A(%.1f,%.1f) y B(%.1f,%.1f) es: (%.1f,%.1f) ",A->x,A->y,B->x,B->y,((A->x+B->x)/2),((A->y,B->y)/2));
}

void distanciaEntrePuntos(Punto *A,Punto *B){
    float distancia;
    distancia = sqrt(((pow((B->x-A->x),2)))+pow((B->y,A->y),2));
    printf("\nLa distancia entre A(%.1f,%.1f) y B(%.1f,%.1f) es: %.1f ",A->x,A->y,B->x,B->y,distancia);
}
void main(){
    Punto *A, *B;
    
    A = crearPunto();
    B = crearPunto();

    puntoMedio(A,B);
    distanciaEntrePuntos(A,B);

}