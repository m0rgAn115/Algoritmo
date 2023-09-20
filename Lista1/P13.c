#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void contarApariciones(char *cadena){
    int n = strlen(cadena),p,conteo=0;
    char apariciones[30],aux;

    while(p<n){
        for(int i=0;i<n;i++){
            aux = cadena[p];
            if(aux==cadena[i]){
                conteo++;
            }
        }
        p++;
        printf("\n El digito %c aparece: %d",aux,conteo);
        conteo=0;
    }
    
}

void imprimirArreglo(int *arr, int n){
    printf("\n[");
    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]");    
    
}

int *crearArreglo(int n){
    int *arr;

    arr = (int*) malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    return arr;
    
}

void imprimirApariciones(int *arr,int n){

    printf("\nDigitos encontrados:");

    for (int i = 0; i < n; i++){
        if(arr[i]>0){
            printf(" %d",i);
        }
    }

    printf("\nY aparecen:");
    
    for (int i = 0; i < n; i++){
        if(arr[i]>0){
            printf(" %d-%d",i,arr[i]);
        }
    }
    
}

void contarAparicionesNumeros(char *cadena){
    int n = strlen(cadena),p,conteo=0;

    int *apariciones = crearArreglo(10);

    
        for(int i=0;i<n;i++){
            if(cadena[i]>='0' && cadena[i]<='9'){
                apariciones[cadena[i]-'0'] += 1;
            }
        }
    
    imprimirApariciones(apariciones,10);
}

void main(){
    char arr[30];
    printf("Digite la cadena: ");
    scanf("%[^\n]",arr);

    contarAparicionesNumeros(arr);
}