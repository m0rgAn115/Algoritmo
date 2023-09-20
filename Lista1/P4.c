#include<stdio.h>
#include<stdlib.h>

int **crearMatriz(int n,int m){
    int **mtz;
    mtz = (int **) malloc(sizeof(int*)*n);

    for(int i=0;i<m;i++)
        mtz[i] = malloc(sizeof(int)*m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mtz[i][j] = 0;
        }
    }

    return mtz;
}

void llenarMatriz(int **mtz,int n,int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("\nIngrese el valor de [%d][%d]: ",i,j);
            scanf("%d",&mtz[i][j]);
        }
        
    }
}

void multiplicarMatrizEscalar(int **mtz,int n,int m,int numero){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            *(*(mtz+j)+i) *= numero;
        }
        
    }
}

int **sumaMatrices(int **mtz1,int **mtz2,int n,int m){
    int **mtzSuma;
    mtzSuma = crearMatriz(n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mtzSuma[i][j] = mtz1[i][j] + mtz2[i][j];
        }
        
    }

    return mtzSuma;
    
}

int **restaMatrices(int **mtz1,int **mtz2,int n,int m){
    int **mtzSuma;
    mtzSuma = crearMatriz(n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mtzSuma[i][j] = mtz1[i][j] - mtz2[i][j];
        }
        
    }

    return mtzSuma;
    
}

int** multiplicarMatrizporMatriz(int **mtz1,int **mtz2,int n1,int m1,int n2,int m2){
    int** mtzRes;
    
        mtzRes = crearMatriz(n1,m2);

        for(int i=0;i<n1;i++){
            
            for(int j=0;j<m2;j++){
                
                for(int k=0;k<n2;k++){
                    mtzRes[i][j] += (mtz1[i][k] * mtz2[j][k]);
                }
                
            }
            
        }
    

    return mtzRes;

    
}

void imprimirMatriz(int **mtz,int n,int m){
    for (int i = 0; i < n; i++){
        printf("\n[");
        for (int j = 0; j < m; j++){
            printf(" %d ",mtz[i][j]);
        }
        printf("]");
    }
}

void sumatoriaEscalar(int **mtz1,int **mtz2, int p, int q,int n, int m){
    int  **mtzRes;
    multiplicarMatrizEscalar(mtz1,p,n,m);
    multiplicarMatrizEscalar(mtz2,q,n,m);
    mtzRes = sumaMatrices(mtz1,mtz2,n,m);
    printf("\n---SUMATORIA---");
    printf("\nEl resultado de %d(A) y %d(B) es: ",p,q);
    imprimirMatriz(mtzRes,n,m);

}

void diferenciaEscalar(int **mtz1,int **mtz2, int p, int q,int n, int m){
    int  **mtzRes;
    multiplicarMatrizEscalar(mtz1,q,n,m);
    multiplicarMatrizEscalar(mtz2,p,n,m);
    mtzRes = restaMatrices(mtz1,mtz2,n,m);
    printf("\n---DIFERENCIA---");
    printf("\nEl resultado de %d(A) y %d(B) es: ",p,q);
    imprimirMatriz(mtzRes,n,m);

}

void productoMtz(int **mtz1,int **mtz2, int p, int q,int n1, int m1,int n2, int m2){
    int  **mtzRes;
    multiplicarMatrizEscalar(mtz1,p,n1,m1);
    multiplicarMatrizEscalar(mtz2,q,n2,m2);
    mtzRes = multiplicarMatrizporMatriz(mtz1,mtz2,n1,m1,n2,m2);
    printf("\n---DIFERENCIA---");
    printf("\nEl resultado de %d(A) y %d(B) es: ",p,q);
    imprimirMatriz(mtzRes,n1,m1);

}

void Menu(int **mtz1,int **mtz2,int p, int q,int n1,int m1,int n2, int m2){
    int respuesta=0;
    while(respuesta != 4){
        printf("\n---Digite la operacion--\n1) pA+qB\n2)qA-pB\n3)pA*qB\n4)Salir\n--------------------");
        scanf("%d",&respuesta);
        switch (respuesta)
        {
        case 1: (n1==n2 && m1==m2) ? sumatoriaEscalar(mtz1,mtz2,p,q,n1,m1) : printf("\nPara esta operacion la matrices deben ser de las mismas dimensiones!");
            break;
        case 2: (n1==n2 && m1==m2) ? diferenciaEscalar(mtz1,mtz2,p,q,n1,m1) : printf("\nPara esta operacion la matrices deben ser de las mismas dimensiones!");
            break;
        case 3: (m1==n2) ? productoMtz(mtz1,mtz2,p,q,n1,m1,n2,m2) : printf("\nPara esta operacion m1 debe ser igual a n2!");
            break;
        case 4: respuesta=4;
        default: printf("\nIngrese una opcion valida!");
            break;
        }
    }
    
    
}

void main(){
    int p,q,**mtz1,**mtz2,n1,m1,n2,m2;

    
    printf("Digite el valor de [n] y [m] de la Matriz A: ");
    scanf("%d%d",&n1,&m1);
    mtz1 = crearMatriz(n1,m1);
    llenarMatriz(mtz1,n1,m1);
    printf("\nDigite el valor de [n] y [m] de la Matriz B: ");
    scanf("%d%d",&n2,&m2);
    mtz2 = crearMatriz(n2,m2);
    llenarMatriz(mtz2,n2,m2);
    printf("\nDigite el valor de [p] y [q]: ");
    scanf("%d%d",&p,&q);

    Menu(mtz1,mtz2,p,q,n1,m1,n2,m2);


}