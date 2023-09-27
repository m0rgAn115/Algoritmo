#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int codigo_libro;
    int cantidad;
    char autor[30];
    char titulo[30];
}libro;

libro *crearRegistro(int n){
    return (libro *) malloc(sizeof(libro)*n);
}

void llenarRegistros(libro *registro,int n){
    for (int i = 0; i < n; i++){
        registro->codigo_libro=i+1;
        printf("\nIntroduzca los datos del libro [%d]: ",i+i);
        printf("\nEjemplares disponibles: ");
        scanf("%d",&registro[i].cantidad);
        getchar();
        printf("\nAutor: ");
        scanf("%[^\n]",registro[i].autor);
        getchar();
        printf("\nTitulo: ");
        scanf("%[^\n]",registro[i].titulo);
        getchar();
    }
    
}


void prestamoLibro(libro *registro,int n){
    int id;
    printf("\nPRESTAMO DE LIBRO");
    printf("\nDigite el codigo del libro: ");
    scanf("%d",&id);

    if(id>n+1 || id<1){
        printf("\nCodigo de libro no valido!");
    }else{
        if(registro[id-1].cantidad > 1){
            registro[id-1].cantidad--;
            printf("\nPrestamo exitoso!");
        }else printf("\nSolo queda el ejemplar de lectura en sala!");
    }
}

void devolucionLibro(libro *registro,int n){
    int id;
    printf("\nPRESTAMO DE LIBRO");
    printf("\nDigite el codigo del libro: ");
    scanf("%d",&id);

    if(id>n+1 || id<1){
        printf("\nCodigo de libro no valido!");
    }else{
        registro[id-1].cantidad++;
        printf("\nDevolucion exitosa!");
    }
}

void menu(libro *registro, int n){
    int opc;
    do{
        printf("\n\tMENU\n1) Solicitar un prestamo\n2) Devolver un libro\n3) Salir\nDigite una opcion: ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1: prestamoLibro(registro,n);
            break;
        
        case 2: devolucionLibro(registro,n);
            break;

        case 3: return ;
            break;
        default: printf("\nDigite una opcion valida!");
            break;
        }
    }while(opc!=3);
}

void main(){
    int n;
    libro *registro;
    printf("\nIngrese la cantidad de libros a registrar: ");
    scanf("%d",&n);

    registro = crearRegistro(n);
    llenarRegistros(registro,n);

    menu(registro,n);

}