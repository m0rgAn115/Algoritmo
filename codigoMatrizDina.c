#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int*);
int **crearMatriz(int ,int );
void darDatosMtz(int **,int fil, int );
void mostrarMtz(int **, int , int );
void liberarMtz(int **, int );
void Mensajes(int );


void main(){
	int fil,col, **mtz;
	
	darDim(&fil,&col);
	mtz=crearMatriz(fil,col);
	darDatosMtz(mtz,fil,col);
	mostrarMtz(mtz,fil,col);
	liberarMtz(mtz,fil);
}

void darDim(int *fil, int*col){
	printf("Indique el numero de filas \n");
	scanf("%d", fil);
	printf("Indique el numero de columnas \n");
	scanf("%d",col);
}

int **crearMatriz(int fil,int col){
	int **mtz,i;
	mtz = (int**) malloc(fil*sizeof(int*));
	
	if(mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	
	for(i=0;i<fil;i++)
		mtz[i] = (int*) malloc(sizeof(int) * col);
		
	return mtz;
}

void darDatosMtz(int **mtz,int fil, int col){
	int i,j;
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
		printf("Dato[%d][%d]=",i+1,j+1);
		scanf("%d",&mtz[i][j]);
	}
	}	
}

void mostrarMtz(int **mtz, int fil, int col){
	int i,j;
	printf("Los datos de la Matriz son: \n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("\t %d",mtz[i][j]);
		}
		printf("\n");
	}
}

void liberarMtz(int **mtz, int fil){
	int i;
	
	for(i=0;i<fil;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] = {"NO hay memoria disponible \n",
				"Memoria liberada \n"};
	
	printf("%s", mensaje[msg]);
}
