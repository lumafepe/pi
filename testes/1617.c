#include <stdio.h>
#include <stdlib.h>
typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int comprimento(char c[]){
    int i;
    for(i =0;c[i]!=0;i++);
    return i;
}

void movetudo(char c[]){
    for(int i=0;c[i]!='\0';i++){
        c[i]=c[i+1];
    }
}


int limpaEspacos (char t[]){
    int i;
    for(i=0;t[i]!=0;i++){
        if (t[i]==' ' && t[i+1]==' ') movetudo(t+i);
    }
    return i;
}
void transposta (int N, float m [N][N]){
    int i,j;
    float aux;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            if(j>i){
            aux=m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=aux;}
        }
    }
}


int main(){
    int i,j;
    float a[3][3];
    for(i=0;i<3;i++)for(j=0;j<3;j++) a[i][j]=i*j+j+i;
    for(i=0;i<3;i++){for(j=0;j<3;j++) printf("%d ",a[i][j]);printf("\n");}
    transposta(3,a);
    for(i=0;i<3;i++){for(j=0;j<3;j++) printf("%d ",a[i][j]);printf("\n");}
    return 0;
}

int nivelV2 (ABin a, int n, int v[],int n1){
    if(a){
        if (n==1){
           v[n1]=a->valor;
           return 1; 
        }
        else{
            n1+=nivelV2(a->esq,n-1,v,n1);
            n1+=nivelV2(a->dir,n-1,v,n1);
            return n1;
        }
    }
    else return 0;
}

int nivelV (ABin a, int n, int v[]){
    nivelV2(a,n,v,0);
}


void removeMaiorA (ABin *a){
    ABin b;
    while (*a && (*a)->dir){
        a=&((*a)->dir);
    }
    if(*a){
        *a=(*a)->esq;
    }
}