#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nombre[30];
    char ap_pater[15];
    int edad;
    char carrera[20];
    
}datos;

typedef struct {
    datos pers;
    char deportes[30];
    int medallas;    
}deportista;

deportista *crearArreglo(int n){
    return (deportista *)malloc(sizeof(deportista)*n);
}

void llenarRegistro(deportista *deportista,int n){
    getchar();
    for(int i=0;i<n;i++){
        printf("\n---Ingrese los datos del deportista[%d]",i);

        printf("\nNombre: ");
        scanf("%[^\n]",deportista[i].pers.nombre);
        getchar();

        printf("\nApellido Paterno: ");
        scanf("%[^\n]",deportista[i].pers.ap_pater);
        getchar();

        printf("\nEdad: ");
        scanf("%d",&deportista[i].pers.edad);
        getchar();

        printf("\nCarrera: ");
        scanf("%[^\n]",deportista[i].pers.carrera);
        getchar();
        
        printf("\nDeporte: ");
        scanf("%[^\n]",deportista[i].deportes);
        getchar();

        printf("\nMedallas: ");
        scanf("%d",&deportista[i].medallas);
        getchar();
    }
}

void imprimirRegistro(deportista *arr, int pos){
        printf("\n\n---Datos de la persona---");
        printf("\nNombre: %s",arr[pos].pers.nombre);
        printf("\nTelefono: %s",arr[pos].pers.carrera);
}

int calcularPromedio(deportista *deportista, int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=deportista[i].medallas;
    }

    return suma/n;
}

int mayorAlPromedio(deportista *deportista, int n, int promedio){
    printf("\nentro: ");

    int conteo=0;
    for(int i=0;i<n;i++){
        if(deportista[i].medallas>promedio){
            conteo++;

        }
    }
    printf("\nsalio: ");
    return conteo;
}

void MorganSort(deportista *arr, int n){
    int p=0;
    deportista aux;

    while(p<n){
        for (int i = 0; i < n; i++){
            if(arr[p].medallas<arr[i].medallas){
                aux = arr[p];
                arr[p] = arr[i];
                arr[i] = aux;    
            }
        }
        p++;
    }
}

void main(){
    int n,promedio, mayorProm;
    deportista *registro;
    printf("Ingrese la cantidad de registros a ingresar: ");
    scanf("%d",&n);
    registro = crearArreglo(n);
    llenarRegistro(registro,n);
    promedio = calcularPromedio(registro,n);
    mayorProm = mayorAlPromedio(registro,n,promedio);
    printf("\nprom, mayorProm %d,%d ",promedio,mayorProm);
    
    printf("\nCantidad de estudiantes con medallas mayor al promedio: %d",mayorProm);
    MorganSort(registro,n);
    printf("\n\n---ESTUDIANTE MAYOR NUMERO DE MEDALLAS---");
    imprimirRegistro(registro,0);
    printf("\n\n---ESTUDIANTE MENOR NUMERO DE MEDALLAS---");
    imprimirRegistro(registro,n-1);
}

