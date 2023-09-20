#include <stdio.h>
#include <string.h>


void main(){
    char A[30],B[30];

    printf("Digite la cadena: ");
    scanf("%[^\n]",A);
    getchar();
    printf("\nAAA = %s length=%d",A,strlen(A));


    
    int p=0;
    char aux;

    strcpy(B,A);

    while(p<strlen(B)){
        for (int i = 0; i < strlen(B); i++){
            if(B[p]<B[i]){
                aux = B[p];
                B[p] = B[i];
                B[i] = aux;
                i=0;
            }
        }
        p++;
    }

    printf("\nTEXTO: %s",B);
    
}