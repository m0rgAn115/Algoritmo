#include<stdlib.h>
#include<stdio.h>
#include "matriz.h"

void manejaMsg(int);

MATRIZ crearMatriz(int filas, int columans){
    MATRIZ m;
    m = (MATRIZ) malloc(sizeof(Matriz));

    m->filas = filas;
    m->columas = columans;

    m->elementos = (int**) malloc(sizeof(int*)*filas);

    if( m == NULL){
         manejaMsg(0);
         exit(0);
    }

    for (int i = 0; i < filas; i++){
        m->elementos[i] = (int*) malloc(sizeof(int)*columans);
    }

    return m;
}

int obtenValor(MATRIZ m,int fila, int columna){
    return m->elementos[fila][columna];
}

MATRIZ asignaValor(MATRIZ m, int fila, int columna, int valor){
    m->elementos[fila][columna] = valor;
    return m;
}

int tamFilas(MATRIZ m){
    return m->filas;
}

int tamColumnas(MATRIZ m){
    return m->columas;
}

MATRIZ sumaMatriz(MATRIZ m1, MATRIZ m2){
    if((m1->columas == m2->columas) && (m1->filas==m2->filas)){
        MATRIZ mResultante = crearMatriz(m1->filas,m1->columas); 
        for (int i = 0; i < m1->filas; i++){
            for (int j = 0; j < m1->columas; j++){
                mResultante->elementos[i][j] = m1->elementos[i][j] + m2->elementos[i][j];
            }
        }
        return mResultante;
    }else{
        printf("\nNo se puede realizar la suma ya que las matrices no son de las mismas dimensiones!");
        return NULL;
    }
}

MATRIZ restaMatriz(MATRIZ m1, MATRIZ m2){
    if((m1->columas == m2->columas) && (m1->filas==m2->filas)){
        MATRIZ mResultante = crearMatriz(m1->filas,m1->columas); 
        for (int i = 0; i < m1->filas; i++){
            for (int j = 0; j < m1->columas; j++){
                mResultante->elementos[i][j] = m1->elementos[i][j] - m2->elementos[i][j];
            }
        }
        return mResultante;
        
    }else{
        printf("\nNo se puede realizar la resta ya que las matrices no son de las mismas dimensiones!");
        return NULL;
    }
}

MATRIZ multiplicacionMatriz(MATRIZ m1, MATRIZ m2){
    if((m1->columas == m2->columas) && (m1->filas==m2->filas)){
        MATRIZ mResultante = crearMatriz(m1->filas,m1->columas); 
        for (int i = 0; i < m1->filas; i++){
            for (int j = 0; j < m1->columas; j++){
                mResultante->elementos[i][j] = m1->elementos[i][j] * m2->elementos[i][j];
            }
        }
        return mResultante;

    }else{
        printf("\nNo se puede realizar la multiplicacion ya que las matrices no son de las mismas dimensiones!");
        return NULL;
    }
}

MATRIZ transpuesta(MATRIZ m1){
    MATRIZ mResultante = crearMatriz(m1->columas,m1->filas); 

    for (int i = 0; i < m1->filas; i++){
            for (int j = 0; j < m1->columas; j++){
                mResultante->elementos[j][i] = m1->elementos[i][j];
            }
        }
    return mResultante;
}