#include<stdlib.h>
#include<stdio.h>
#include"E0.h"

void manejaMsg(int);

LISTA crearLista(  ){
	LISTA L;
	L = NULL;
        return L;
}

// VERIFICA SI ESTA VACÍA LA LISTA
int es_vaciaLista(LISTA L){
	if( L == NULL)
		return TRUE;
	else
		return FALSE;
}

// CREA UN ELEMENTO DE LA LISTA
Nodo_Lista * crearNodoLista(  ){
   Nodo_Lista * nvo;
   nvo = (Nodo_Lista *)malloc(sizeof(Nodo_Lista));
   if(nvo == NULL){
      manejaMsg(0);
      exit(0); 
   }
   return nvo;
}

LISTA insertar(LISTA L, Producto e){
    Nodo_Lista * nvo;
	Nodo_Lista * actual, *anterior;

    nvo = crearNodoLista( );	
    nvo -> dato = e;
    if(es_vaciaLista(L)==TRUE){
        printf("ENTRO");
        nvo ->siguiente = NULL;
        L = nvo;
    }
    else{
        actual = L;
        while(actual != NULL){
            anterior = actual;
            actual = actual -> siguiente;
        }
    nvo -> siguiente = NULL;
    anterior -> siguiente = nvo;
    }
  
   return L;
}
       
// MOSTRAR LOS ELEMENTOS DE LA LISTA
void visualizaLista(LISTA L){
       Nodo_Lista * actual;
       int pos;
       actual = L;
	if(es_vaciaLista(L)==TRUE){
		manejaMsg(5); //LISTA VACIA
		exit(0);
	}
	pos=1;
       while(actual != NULL){	
          mostrar(actual->dato.clave, 1,pos); 
          pos++;
	   actual = actual -> siguiente;
      }
}


// BUSCAR UN ELEMENTO DE LA LISTA
void  buscarElem(LISTA L, int elem){
   Nodo_Lista * actual;
   int pos=1;
   actual = L;
    if(es_vaciaLista(L)==TRUE){
	manejaMsg(5); //LISTA VACIA
	exit(0);
    }
     while(actual != NULL && elem != actual -> dato.clave){	
	actual = actual -> siguiente;
  	pos++;
     }
     if( actual == NULL)
           mostrar(elem, 0,0);//No se encuentra
else 
	mostrar(elem, 2, pos);//indica la posicion
}

// BORRAR UN ELEMENTO DE LA LISTA
LISTA borrar(LISTA L, int elem){ 
Nodo_Lista * actual,* anterior; 
  
    if(es_vaciaLista(L) == TRUE){ 
      manejaMsg(5); // LISTA VACIA
      exit(0); 
    } 
   actual = L; 
   anterior = L;   
    while(actual != NULL && elem != actual->dato.clave){ 
       anterior = actual; 
       actual = actual -> siguiente; 
  } 
  if(actual == NULL) 
       mostrar(elem, 0, 0); // No se encontro
  else if (anterior == actual){ 
      L = anterior -> siguiente; 
      free(anterior); 
   } 
   else {
       anterior ->siguiente = actual -> siguiente; 
       free(actual); 
   } 
  return L; 
}

void mostrar(int e, int msg, int p){
    int i;

    if(msg == 0)
	 printf("El elemento %d no se encuentra en la lista\n", e);
    else if(msg == 1)
	  printf("\n Nodo %d = %d\n",p,e);
    else
       printf("\nEl elemento %d se encuentra en la posicion %d\n", e, p);
}


LISTA insertarEnPosicion(LISTA L, int pos, Producto e){
    Nodo_Lista * nvo;
    pos = pos-1;
    Nodo_Lista *actual, *anterior;
    int controlPos=0;

    nvo = crearNodoLista();
    nvo->dato = e;
    if(es_vaciaLista(L)==TRUE && pos==0){
        nvo->siguiente = NULL;
        L = nvo;
    }else {
        actual = L;
        while(actual!=NULL || controlPos==pos){
            
            if(actual==NULL)
                manejaMsg(6);//Posicion no existe
            else if(pos==controlPos){
                anterior->siguiente=nvo;
                nvo->siguiente= actual;
                return L;
            }else{
                anterior = actual;
                actual = actual->siguiente;
                controlPos++;
            }
        }
    }
    
    return L;
}

int obtenTamLista(LISTA L){
    Nodo_Lista * actual = L;
    int conteo=0;
    if(es_vaciaLista(L)){
        return 0;
    }else{
        while(!es_vaciaLista(actual)){
            conteo++;
            actual = actual->siguiente;
        }
    }

    return conteo;
}