#ifndef _vector_
#define _vector_
#include<stdbool.h>

typedef struct {
    int *componentes;
    int tam;
} Vector;

typedef Vector * VECTOR;

//operaciones
VECTOR crearVector(int,int);
int obtenComponente(VECTOR,int);
VECTOR asignaComponente(VECTOR, int, int);
int obtenTam(VECTOR);
VECTOR sumaVector(VECTOR,VECTOR);
VECTOR restaVector(VECTOR,VECTOR);
int productoPunto(VECTOR,VECTOR);
bool esMayorQue(int,int);
VECTOR ordenaVector(VECTOR);

#endif