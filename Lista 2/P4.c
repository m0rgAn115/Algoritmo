#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nombre[30];
    char apellido_pa[30];
    char apellido_ma[30];
    int unidades;
    float precio;
    char estado[15];
    
}clientes;



clientes *crearArreglo(int n){
    return (clientes *)malloc(sizeof(clientes)*n);
}

void llenarRegistro(clientes *clientes,int n){
    getchar();
    for(int i=0;i<n;i++){
        printf("\n---Ingrese los datos del cliente[%d]",i);

        printf("\nNombre: ");
        scanf("%[^\n]",clientes[i].nombre);
        getchar();

        printf("\nApellido Paterno: ");
        scanf("%[^\n]",clientes[i].apellido_pa);
        getchar();

        printf("\nApellido Materno: ");
        scanf("%[^\n]",clientes[i].apellido_ma);
        getchar();

        printf("\nUnidades: ");
        scanf("%d",&clientes[i].unidades);
        getchar();

        printf("\nPrecio por unidad: ");
        scanf("%f",&clientes[i].precio);
        getchar();

        printf("\nEstado: ");
        scanf("%[^\n]",clientes[i].estado);
        getchar();
    }
}



void main(){
    
}