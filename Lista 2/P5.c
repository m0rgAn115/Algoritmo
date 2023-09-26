#include<stdio.h>
#include<stdlib.h>


typedef struct{
    int real;
    int compleja;
}num_imaginario;



num_imaginario *crearNumeroImaginario(){
    return (num_imaginario*) malloc(sizeof(num_imaginario));
}

void asignarValoresNumeroImaginario(num_imaginario *num){
    printf("\nIngrese la parte real del numero: ");
    scanf("%d",&num->real);
    printf("\nIngrese la parte compleja del numero: ");
    scanf("%d",&num->compleja);

    printf("\nNumero Imaginario creado (%d + %di)!",num->real,num->compleja);
}

void sumaImaginarios(num_imaginario *num1,num_imaginario *num2){
    printf("\nEl resultado de la suma de (%d + %di) y (%d + %di) es: %d + %di",num1->real,num1->compleja,num2->real,num2->compleja,num1->real+num2->real,num1->compleja+num2->compleja);
}

void restaImaginarios(num_imaginario *num1,num_imaginario *num2){
    printf("\nEl resultado de la resta de (%d + %di) y (%d + %di) es: %d + %di",num1->real,num1->compleja,num2->real,num2->compleja,num1->real-num2->real,num1->compleja-num2->compleja);
}

void productoImaginarios(num_imaginario *num1,num_imaginario *num2){
    int fac1,fac2,fac3,fac4;
    fac1 = num1->real*num2->real;
    fac2 = num1->real*num2->compleja;
    fac3 = num1->compleja * num2->real;
    fac4 = -1*(num1->compleja * num2->compleja);
    printf("\nEl resultado del producto de (%d + %di) y (%d + %di) es: %d + %di",num1->real,num1->compleja,num2->real,num2->compleja,fac1+fac4,fac2+fac3);
}

void divisionImaginarios(num_imaginario *num1,num_imaginario *num2){
    num_imaginario aux1;
    num_imaginario aux2;

    int fac1,fac2,fac3,fac4;
    fac1 = num1->real*num2->real;
    fac2 = num1->real*(-1*num2->compleja);
    fac3 = num1->compleja * num2->real;
    fac4 = -1*(num1->compleja * (-1*num2->compleja));

    num_imaginario numerador_i;

    numerador_i.real = fac1+fac4;
    numerador_i.compleja = fac2+fac3;

    num_imaginario denominador_i;
    fac1 = num2->real*num2->real;
    fac2 = num2->real*(-1*num2->compleja);
    fac3 = num2->compleja * num2->real;
    fac4 = -1*(num2->compleja * (-1*num2->compleja));

    denominador_i.real = fac1+fac4;
    denominador_i.compleja = fac2+fac3;

    printf("\nEl resultado de la division de (%d + %di) y (%d + %di) es: %d + %di / %d",num1->real,num1->compleja,num2->real,num2->compleja,numerador_i.real,numerador_i.compleja,denominador_i.real);
}

void menu(num_imaginario *num1,num_imaginario *num2){
    int respuesta,n, *vector;

    while(respuesta!=-1){
        printf("\n\nMenu: \n1)Suma \n2)Resta \n3)Multiplicacion \n4)Division \n0)Salir\nIntroduzca una opcion: ");
        scanf("%d",&respuesta);
        switch (respuesta){
    case 1: sumaImaginarios(num1,num2);
        break;
    
    case 2: restaImaginarios(num1,num2);
        break;
    
    case 3: productoImaginarios(num1,num2);
        break;
    
    case 4: divisionImaginarios(num1,num2);
        break;

    case 0: respuesta= -1;
        break;
    default: printf("\nIntroduzca una opcion valida!: ");
        break;
    }
    }
    
}


void main(){
    num_imaginario *num1, *num2;

    num1 = crearNumeroImaginario();
    num2 = crearNumeroImaginario();

    asignarValoresNumeroImaginario(num1);
    asignarValoresNumeroImaginario(num2);


    menu(num1,num2);
}