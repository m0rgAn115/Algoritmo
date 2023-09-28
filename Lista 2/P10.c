#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nombre[25];
    int boleta;
    char semestre[15];
    char sexo;
    int calificaciones[5];
} Alumno;

typedef struct {
    int key;
    float val;
} Map;

Alumno *crearRegistro(int n){
    return (Alumno *) malloc(sizeof(Alumno)*n);
}

Map *crearMap(int n){
    return (Map *) malloc(sizeof(Map)*n);
}

void llenarRegistro(Alumno *registro, int n,Map *promedio){
    for (int i = 0; i < n; i++){
        getchar();
        printf("\nIngrese los datos del estudiante [%d]",i);
        printf("\nNombre: ");
        scanf("%[^\n]",registro[i].nombre);
        getchar();
        printf("\nSemeste: ");
        scanf("%[^\n]",registro[i].semestre);
        getchar();
        printf("\nBoleta: ");
        scanf("%d",&registro[i].boleta);
        getchar();
        printf("\nSexo: ");
        scanf("%c",&registro[i].sexo);
        getchar();

        for (int j = 0; j < 5; j++){
            printf("\nCalificacion [%d]: ",j);
            scanf("%d",&registro[i].calificaciones[j]);
        }
        promedio[i].key = i;
    }
}

void guardarPromedio(Alumno *registro, int n,Map *promedio){
    int suma;

    for (int i = 0; i < n; i++){
        suma=0;
        for (int j = 0; j < 5; j++){
            suma += registro[i].calificaciones[j];
        }
        promedio[i].val = suma/5;
    }
}

void MorganSortAsc(Map *arr, int n){
    int p=0;
    Map aux;

    while(p<n){
        for (int i = 0; i < n; i++){
            if(arr[p].val>arr[i].val){
                aux = arr[p];
                arr[p] = arr[i];
                arr[i] = aux;
                i=0;
            }
        }
        p++;
    }
}

void imprimirMayorPromedio(Alumno *registro, int n,Map *promedio){
    for (int i = 0; i < n; i++){   
        printf("\n\nALUMNO [%d]",i);
        printf("\nNombre alumno: %s",registro[promedio[i].key].nombre);
        printf("\nBoleta: %i",registro[promedio[i].key].boleta);
        printf("\nPromedio: %f",promedio[i].val);

    }
    
}

void imprimirMap(Map *map,int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n\nPOS [%d]",i);
        printf("\nKey: %d",map[i].key);
        printf("\nVal: %f",map[i].val);
    }
    
}
 
void main(){
    Alumno *registro;
    Map *promedio;
    int n;

    printf("\nIngrese la cantidad de alumnos: ");
    scanf("%d",&n);

    registro = crearRegistro(n);
    promedio = crearMap(n);

    llenarRegistro(registro,n,promedio);
    guardarPromedio(registro,n,promedio);

    imprimirMap(promedio,n);

    MorganSortAsc(promedio,n);

    imprimirMap(promedio,n);

    imprimirMayorPromedio(registro,n,promedio);
    
}