#include <stdio.h>
#include<stdlib.h>

typedef struct {
    float *componentes;
    int tam;
} Vector;

typedef Vector* VECTOR;

VECTOR crearVector(int n){
    VECTOR v = (VECTOR) malloc(sizeof(Vector));
    v->componentes = (float*) calloc(n,sizeof(float));
    v->tam = n;
    return v;
}

float calcularProductoPunto(VECTOR v1, VECTOR v2){
    int suma = 0;
    for (int i = 0; i < v1->tam; i++){
        suma+=v1->componentes[i]*v2->componentes[i];
    }
    
    return suma;
}

VECTOR calcularProyeccion(VECTOR u,VECTOR v){
    VECTOR proy = crearVector(u->tam);
    
    for (int i = 0; i < u->tam; i++){
        proy->componentes[i] = v->componentes[i] * (calcularProductoPunto(u,v)/calcularProductoPunto(v,v));
    }

    return proy;
}

void restaVectores(VECTOR *vectores,int n,VECTOR res){
    if(n==1){
        for (int i = 0; i < vectores[0]->tam; i++){
            res->componentes[i] -= vectores[n-1]->componentes[i];
        }
        return;
    }else{
        for (int i = 0; i < vectores[0]->tam; i++){
            res->componentes[i] -= vectores[n-1]->componentes[i];
        }
        restaVectores(vectores,n-1,res);
    }
}

VECTOR *crearArregloVectores(int n){
    return (VECTOR*) malloc(sizeof(VECTOR)*n);
}

void llenarArregloVectores(VECTOR *arr,VECTOR *vectores,VECTOR *vectoresRes,int n,int aux){
    
    if(n==1){
        arr[n-1] = vectores[aux-1];
        return;
    }else{
        arr[n-1] = calcularProyeccion(vectores[n-1],vectoresRes[n-2]);
        llenarArregloVectores(arr,vectores,vectoresRes,n-1,aux);
    }
    
}
VECTOR *calcularProcesoGramSchmidt(VECTOR *vectores,VECTOR *vectoresRes,int n,int aux){
    if(n==aux){
        VECTOR *arr = crearArregloVectores(n);
        llenarArregloVectores(arr,vectores,vectoresRes,0,n);
    }else if(n==0){
        vectoresRes[n] = vectores[n];
    }else if(n<aux){
        VECTOR *arr = crearArregloVectores(n);
        llenarArregloVectores(arr,vectores,vectoresRes,0,n);
        restaVectores(arr,n,&vectoresRes[n]);
        calcularProcesoGramSchmidt(vectores,vectoresRes,n-1,aux);
    }
}

void main(){
    VECTOR *mtz = crearArregloVectores(2);
    printf(" %d ",&mtz[0]);
}