#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int*);
int **crearMatriz(int ,int );
void darDatosMtz(int **,int fil, int );
void mostrarMtz(int **, int , int );
void liberarMtz(int **, int );
void Mensajes(int);

int* crearArreglo(int);
void sumaArreglos(int **,int *, int *, int );
void mostrarArr(int* ,int);
void liberar(int *);

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
    liberar(arr1);
    liberar(arr2);
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
	char * mensaje[] = {"\nNO hay memoria disponible \n",
				"\nMemoria liberada "};
	
	printf("%s", mensaje[msg]);
}

int *crearArreglo(int n){

	int *arr1 = (int*) malloc(sizeof(int)*n);
	
	
	return arr1;
}

void sumaArreglos(int **mtz,int *arr1, int *arr2, int n){
	
	int o=0,p=0,b=n-1,k=0;
    while(o<n){
        arr1[o]=1;
        arr2[o]=1;
        p=o;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((p==0)&&(j==i)){
                    arr1[o] *= mtz[i][j];
                }else if((p==i)&&(i==(j+o))){
                    arr1[o] *= mtz[i][j];
                    p++;
                }

                if(0==(b-j)){
                    while(b>=0){
                        arr2[o] *= mtz[k++][b--];
                    }
                }
            }
        }
        o++;b=(n-1-o);k=0;
    }
	
    
}

void mostrarArr(int *arr,int n){
	printf("\nContenido del arreglo: ");
	for(int i=0;i<n;i++){
		printf("[%d], ",arr[i]);
	}
}


void liberar(int *A){
	free(A);
	Mensajes(1);
}
