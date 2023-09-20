#include<stdio.h>
#include<stdlib.h>





int *crearVector(int n){
    printf("\nVECTOR CREADO CON %d POSICIONES",n);
    return (int *) malloc(sizeof(int)*n);
}

void llenarVector(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("\nIntroduzca el numero de la posicion[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    
}

void imprimirArreglo(int arr[], int n){
    printf("\n[");
    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("]\n");    
    
}

void MorganSortAsc(int *arr, int n){
    int p=0,aux;

    while(p<n){
        for (int i = 0; i < n; i++){
            if(arr[p]<arr[i]){
                aux = arr[p];
                arr[p] = arr[i];
                arr[i] = aux;
                i=0;
            }
        }
        p++;
    }

    printf("\nVECTOR ORDENADO DE FORMA CRECIENTE");
}

void MorganSortDes(int *arr, int n){
    int p=0,aux;

    while(p<n){
        for (int i = 0; i < n; i++){
            if(arr[p]>arr[i]){
                aux = arr[p];
                arr[p] = arr[i];
                arr[i] = aux;
                i=0;
            }
        }
        p++;
    }

    printf("\nVECTOR ORDENADO DE FORMA DECRECIENTE");
    
}

void menu(){
    int respuesta,n, *vector;

    while(respuesta!=-1){
        printf("\n\nMenu: \n1)Dar tamanio del vector \n2)Llenar Vector \n3)Ordenar crecienter \n4)Ordenar decreciente \n5)Mostrar Vector\n0)Salir\nIntroduzca una opcion: ");
        scanf("%d",&respuesta);
        switch (respuesta){
    case 1: printf("\nIntroduzca la cantidad de elementos del vector: ");
            scanf("%d",&n);
            vector = crearVector(n);
        break;
    
    case 2: llenarVector(vector,n);
        break;
    
    case 3: MorganSortAsc(vector,n);
        break;
    
    case 4: MorganSortDes(vector,n);
        break;

    case 5: imprimirArreglo(vector,n);
        break;

    case 0: respuesta= -1;
        break;
    default: printf("\nIntroduzca una opcion valida!: ");
        break;
    }
    }
    
}


void main(){
    menu();
}