#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int edad;
    char nombre[30];
    char telefono[10];
}datos;

datos *crearArreglo(int n){
    return (datos *)malloc(sizeof(datos)*n);
}

void llenarRegistro(datos *datos,int n){
    for(int i=0;i<n;i++){
        printf("\n---Ingrese los datos de la persona %d",i);
        printf("\nEdad: ");
        scanf("%d",&datos[i].edad);
        getchar();
        printf("\nNombre: ");
        scanf("%[^\n]",datos[i].nombre);
        getchar();
        printf("\nTelefono: ");
        scanf("%[^\n]",datos[i].telefono);
        getchar();
    }
}

void imprimirRegistro(datos *arr, int n){
    for(int i=0;i<n;i++){
        printf("\n\n---Datos de la persona [%d]---",i);
        printf("\nEdad: %d",arr[i].edad);
        printf("\nNombre: %s",arr[i].nombre);
        printf("\nTelefono: %s",arr[i].telefono);
    }
}

void MorganSort(datos *arr, int n){
    int p=0;
    datos aux;

    while(p<n){
        for (int i = 0; i < n; i++){
            if(arr[p].edad<arr[i].edad){
                aux = arr[p];
                arr[p] = arr[i];
                arr[i] = aux;
                i=0;
            }
        }
        p++;
    }
    
    imprimirRegistro(arr,n);
}

void main(){
    int n;
    datos *registro;
    printf("Ingrese la cantidad de registros a ingresar: ");
    scanf("%d",&n);
    registro = crearArreglo(n);
    llenarRegistro(registro,n);
    MorganSort(registro,n);
}

