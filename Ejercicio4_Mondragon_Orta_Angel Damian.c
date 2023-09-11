#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num_folio;
	char nombre_cliente[30];
	char tramite;
	float costo;
} Expediente;

Expediente* crearMem();
void llenarExpediente(Expediente* exp);
void mostrarExpediente(Expediente* exp);
void Mensajes(int msg);
void liberar(Expediente *A);

void main(){
	Expediente *exp;
	exp = crearMem();
	llenarExpediente(exp);
	mostrarExpediente(exp);
	liberar(exp);
	
}

Expediente* crearMem(){
	Expediente *nvo;
	nvo = (Expediente*) malloc(sizeof(Expediente));
	
	return nvo;
}

void llenarExpediente(Expediente* exp){
	printf("Introduzca el numero de folio: \n");
	scanf("%d",&exp->num_folio);
	getchar();
	printf("Introduzca el nombre del cliente: \n");
	scanf("%[^\n]",exp->nombre_cliente);
	getchar();
	printf("Introduzca el tipo de tramite [P/D]: \n");
	scanf("%c",&exp->tramite);
	getchar();
	printf("Introduzca el costo: \n");
	scanf("%f",&exp->costo);
}

void mostrarExpediente(Expediente* exp){
	printf("\nDatos del tramite");
	printf("Numero de folio: %d \n",exp->num_folio);
	printf("Nombre del cliente: %s \n",exp->nombre_cliente);
	printf("Tramite: %c \n",exp->tramite);
	printf("Costo: %.2f \n",exp->costo);
}

void Mensajes(int msg){
	char * mensaje[] = {"\nNO hay memoria disponible \n",
				"\nMemoria liberada "};
	
	printf("%s", mensaje[msg]);
}

void liberar(Expediente *A){
	free(A);
	Mensajes(1);
}

