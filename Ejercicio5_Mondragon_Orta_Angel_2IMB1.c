#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char direccion[30];
	char ciudad[30];
	char provincial[30];
	int cod_postal;
}info_dir;

typedef struct{
	char estado_paciente[30];
}c_paciente;

typedef struct{
	char *nombre;
	int edad;
	char sexo;
	info_dir direccion;
	c_paciente *condicion;
}info_paciente;

info_paciente *crearPacientes(int );
c_paciente *crearMemCon();
void llenarPacientes(info_paciente *,int );
void mostrarPacientesFiltro(info_paciente *,int );
void liberarMem(info_paciente *);

void main(){
	int m;
	info_paciente *pacientes;
	printf("Introduza la cantidad de pacientes a registrar: ");
	scanf("%d",&m);
	pacientes = crearPacientes(m);
	llenarPacientes(pacientes,m);
	mostrarPacientesFiltro(pacientes,m);
	liberarMem(pacientes);
	
	
}

info_paciente *crearPacientes(int m){
	info_paciente *pacientes;
	pacientes = (info_paciente *) malloc(sizeof(info_paciente)*m);
	
	return pacientes;
}

c_paciente *crearMemCon(){
	return (c_paciente *) malloc(sizeof(c_paciente));
}

void llenarPacientes(info_paciente *pacientes,int m){
	for(int i=0;i<m;i++){
		pacientes[i].nombre = (char*) malloc(sizeof(char)*30); 
	
		
		printf("\n---PACIENTE [%d]---",i);
		printf("\nIntroduzca el nombre del paciente: ");
		scanf("%[^\n]", pacientes[i].nombre);
		getchar();
		printf("\nIntroduzca la edad del paciente: ");
		scanf("%d",&pacientes[i].edad);
		getchar();
		printf("\nIntroduzca el sexo del paciente: ");
		scanf("%c",&pacientes[i].sexo);
		getchar();
		
		printf("\nIntroduzca la direccion del paciente: ");
		scanf("%[^\n]",pacientes[i].direccion.direccion);
		getchar();
		printf("\nIntroduzca la ciudad del paciente: ");
		scanf("%[^\n]",pacientes[i].direccion.ciudad);
		getchar();
		printf("\nIntroduzca la provincial del paciente: ");
		scanf("%[^\n]",pacientes[i].direccion.provincial);
		getchar();
		printf("\nIntroduzca el codigo postal del paciente: ");
		scanf("%d",&pacientes[i].direccion.cod_postal);
		getchar();
		
		pacientes[i].condicion = crearMemCon();
		
		printf("\nIntroduzca la condicion del paciente: ");
		scanf("%[^\n]",pacientes[i].condicion->estado_paciente);
		getchar();
		
		
	}
}

void mostrarPacientesFiltro(info_paciente *pacientes,int m){
	for(int i=0; i<m;i++){
		
 		if(!(strcmp(pacientes[i].condicion->estado_paciente,"grave"))){
			printf("\n---PACIENTE [%d]---",i);
			printf("\nNombre del paciente: %s",pacientes[i].nombre);
			printf("\nCiudad del paciente: %s",pacientes[i].direccion.ciudad);
		}
	}
}

void liberarMem(info_paciente *lista){
	free(lista);
}


