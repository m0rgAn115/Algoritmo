#include<stdio.h>
#include<stdlib.h>
#include"cadena.h"

void manejaMsg(int);

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}

CADENA numCaracteres(){
    int n;
    printf("\nIngrese el numero de caracteres de la cadena: ");
    scanf("%d",&n);
    return crearCadena(n);
}

void leeCadena(CADENA c){
    getchar();
    printf("\nIngrese la cadena: ");
    scanf("%[^\n]",c->cad);
}

CADENA codificarCadena(CADENA c){
    CADENA cadCod = crearCadena(tamaño(c));
    for(int i=0;i<tamaño(c);i++){
        switch(obtenComponente(c,i)){
            case 'a': ponComponente(cadCod,i,'1');
                break;
            case 'A': ponComponente(cadCod,i,'1');
                break;
            case 'e' : ponComponente(cadCod,i,'2');
                break;
            case 'E' : ponComponente(cadCod,i,'2');
                break;
            case 'i' : ponComponente(cadCod,i,'3');
                break;
            case 'I' : ponComponente(cadCod,i,'3');
                break;
            case 'o' : ponComponente(cadCod,i,'4');
                break;
            case 'O' : ponComponente(cadCod,i,'4');
                break;
            case 'u' : ponComponente(cadCod,i,'5');
                break;
            case 'U' : ponComponente(cadCod,i,'5');
                break;
            default: ponComponente(cadCod,i,obtenComponente(c,i));
        }
    }
    return cadCod;
}

CADENA decodificarCadena(CADENA c){
    CADENA cadCod = crearCadena(tamaño(c));
    for(int i=0;i<tamaño(c);i++){
        switch(obtenComponente(c,i)){
            case '1': ponComponente(cadCod,i,'a');
                break;
            case '2': ponComponente(cadCod,i,'e');
                break;
            case '3': ponComponente(cadCod,i,'i');
                break;
            case '4': ponComponente(cadCod,i,'o');
                break;
            case '5': ponComponente(cadCod,i,'u');
                break;
            default: ponComponente(cadCod,i,obtenComponente(c,i));
        }
    }
    return cadCod;
}

void mostrarCadenas(CADENA c1, CADENA c2,CADENA c3){
    printf("\nCADENA 1 ORIGINAL:");
    for(int i=0;i<tamaño(c1);i++){
        printf("%c",obtenComponente(c1,i));
    }
    printf("\nCADENA 2 CODIFICADA:");
    for(int i=0;i<tamaño(c2);i++){
        printf("%c",obtenComponente(c2,i));
    }
    printf("\nCADENA 3 DECODIFICADA CAD 2:");
    for(int i=0;i<tamaño(c2);i++){
        printf("%c",obtenComponente(c3,i));
    }
}

void liberarMemoria(CADENA c1,CADENA c2,CADENA c3){
    free(c1);
    free(c2);
    free(c3);

    manejaMsg(1);
}
void main(){
    CADENA c1,c2,c3;
    c1 = numCaracteres();

    leeCadena(c1);
    c2 = codificarCadena(c1);
    c3 = decodificarCadena(c2);

    mostrarCadenas(c1,c2,c3);
}
