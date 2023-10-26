#ifndef _matriz_
#define  _matriz_

typedef  struct{
    int **elementos;
    int filas;
    int columas;
}Matriz;

typedef Matriz* MATRIZ;

//operaciones
MATRIZ crearMatriz(int,int);
int obtenValor(MATRIZ,int,int);
MATRIZ asignaValor(MATRIZ,int,int,int);
int tamFilas(MATRIZ);
int tamColumnas(MATRIZ);
MATRIZ sumaMatriz(MATRIZ,MATRIZ);
MATRIZ restaMatriz(MATRIZ,MATRIZ);
MATRIZ multiplicacionMatriz(MATRIZ,MATRIZ);
MATRIZ transpuesta(MATRIZ);


#endif