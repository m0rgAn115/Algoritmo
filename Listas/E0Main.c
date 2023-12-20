#include<stdlib.h>
#include<stdio.h>
#include"E0.h"

void manejaMsg(int msg){
     char * mensajes[] = {"\nNo hay memoria disponible . . .","\nSe ha liberado la memoria . . .  ","\nCOLA VACIA","\nCOLA LLENA","","\nLISTA VACIA","\nPOSICION NO EXISTE"};
     printf("%s", mensajes[msg] );
}

LISTA llenarLista(LISTA L){
    int opc,i=1;
    Producto prod;
    printf("\nLLENAR LISTA");
    do
    {   
        prod.clave = i++;
        printf("\nIngrese la clave el producto: ");
        scanf("%d",&prod.clave);
        getchar();
        printf("Ingrese el nombre del producto: ");
        scanf("%[^\n]",prod.nombre);
        printf("Ingrese el precio del producto: ");
        scanf("%f",&prod.precio);
        L = insertar(L,prod);

        printf("\nDesea agregar otro producto? 1-SI 0-NO");
        scanf("%d",&opc);
        
    } while (opc !=0);

    return L;
    
}

void MorganSort2(LISTA L, int n){
    char menor;
    Producto prod;
     int posOrd = 0, pos =0, posMenor;
    Nodo_Lista * actual = L, *sig = L;
    LISTA ordenada = crearLista();

    menor = actual->dato.nombre[0];
    while(posOrd < n){
        
        while(pos < n-posOrd){
            if(menor > sig->dato.nombre[0]){
                menor = sig->dato.nombre[0];
                posMenor = pos;
            }
            sig = sig->siguiente;
            pos ++;
        }
        posOrd ++;
    }

}

void MorganSort(int arr[], int n){
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
}





void main(){
    LISTA L = crearLista();
    L = llenarLista(L);

    printf("LLENO = %d",obtenTamLista(L));
    buscarElem(L,1);
    MorganSort2(L,obtenTamLista(L));
    buscarElem(L,1);

    Producto a;
    a.clave = 5;
    a.precio = 543.5;

    insertarEnPosicion(L,2-1,a);

    buscarElem(L,5);



    
}