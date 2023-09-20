#include <stdio.h>
#include <string.h>
int copiaTexto(FILE* sal){
    int i=0,c=0;
    char text[100];
    while ((text[i]=getchar()) != '@')
    {
        fputc(text[i++],sal);
        c++;
    }

    return c;
}

void EliminarPal(FILE* ent,FILE* sal,char palabra[]){
    char pal[20];
    int i=0;
    while((fscanf(ent,"%s",pal)) != EOF){
        if(strcmp(pal,palabra)){
            fprintf(sal,"%s ",pal);
        }
    }
}

void OrdenaArch(FILE* ent, FILE* sal){
    char* pals[200], pal[20];
    int i=0,n;
    while (fscanf(ent,"%s",pal) != EOF){
        pals[i]=(char*)malloc(20);
        strcpy(pals[i++],pal);
    }

    fprintf(sal,"%s",pals[1]);
    
}

void Divide(FILE* arch1, FILE* arch2, FILE* arch3, char palabra[20]){
    char pal[20];
    
    while(fscanf(arch1,"%s",pal) != EOF){
        if(strcmp(pal,palabra) <= 0){
            fprintf(arch2,"%s ",pal);
        }else fprintf(arch3,"%s ",pal);
    }

}
int main(int argc, char *argv[]){
    FILE* sal = fopen("sal.txt","w");
    FILE* ent = fopen("ent.txt","r");
    FILE* arch1 = fopen("arch1.txt","r");
    FILE* arch2 = fopen("arch2.txt","w");
    FILE* arch3 = fopen("arch3.txt","w");

    char pal[20];

    printf("Digita una palabra: ");
    scanf("%s",pal);

    // OrdenaArch(ent,sal);
    // EliminarPal(ent,sal,pal);
    Divide(arch1,arch2,arch3,pal);
    return 0;
}