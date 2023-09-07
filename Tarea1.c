#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int*);
int **crearMatriz(int ,int );
void darDatosMtz(int **,int fil, int );
void mostrarMtz(int **, int , int );
void liberarMtz(int **, int );
void Mensajes(int );

int* crearArreglo(int);
void sumaArreglos(int **,int *, int *, int );
void mostrarArr(int* ,int);

void main(){
	int fil,col, **mtz,*arr1,*arr2;
	
	darDim(&fil,&col);
	mtz=crearMatriz(fil,col);
	darDatosMtz(mtz,fil,col);
	arr1 = crearArreglo(fil);
	arr2 = crearArreglo(fil);
	sumaArreglos(mtz,arr1,arr2,fil);
	mostrarMtz(mtz,fil,col);
	mostrarArr(arr1,fil);
	mostrarArr(arr2,fil);
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

int *crearArreglo(int n){

	int *arr1 = (int*) malloc(sizeof(int)*n);
	
	
	return arr1;
}

void sumaArreglos(int **mtz,int *arr1, int *arr2, int n){
	
	for(int k=0;k<n;k++){
		arr1[k]=1;
		arr2[k]=1;
	}
	
	int o=0,u=0;
	int p=0;
	while(p<n){
	
		for(int i=p; i< n;i++){
		for(int j=p-1; j<n ; j++){
			printf("[i][j] = [%d][%d] \n",i,j);
			
				if((i==j)){
				
					
					arr1[p] *= mtz[i][j];
					printf("MTZ[%d] \n",mtz[i][j]);
					printf("Arreglo1[$d] = %d \n",arr1[p]);
					j=0;i++;
				}
				
			
			
				if((j+i)==n-1){
					arr2[p] *= mtz[i][j];
					printf("MTZ[%d] \n",mtz[i][j]);
					printf("Arreglo2 = %d \n",arr1[p]);
				}
			
			
		}
	} p++;
	}
	
		printf("Arreglos sum");
}

void mostrarArr(int *arr,int n){
	printf("\nContenido del arreglo: ");
	for(int i=0;i<n;i++){
		printf("[%d], ",arr[i]);
	}
}

