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



int movetudo (int v[],int *i,int *N){
    for (int j=*i;j<*N;j++){
        v[j]=v[j+1];
    }
    (*N)--;
    (*i)--;
}
int retiraNeg (int v[], int N){
    for (int i =0;i<N;i++){
        if (v[i]<0) movetudo(v,&i,&N);
    }
    return N;
}

int verifica(char s[],int f){
    int i=0,r=1;
    for (i=0;i<f;)
}


int difConsecutivos (char s[]){
    int i,max;
    for (i=0;s[i]!='\0';i++){

    }
    return max;
}

int maximo (LInt l){
    int max;
    if (l){
        max=l->valor;
        l=l->prox;
        while(l){
            if(max<l->valor) max=l->valor;
            l=l->prox;
        }
    }
    else max=0;
    return max;
}
int removeAll (LInt *l, int x){
    LInt f;
    int r=0;
    while(*l && (*l)->prox){
        if ((*l)->valor==x){
            f=*l;
            *l=(*l)->prox;
            free(f);
            r++;
        }
        else if((*l)->prox->valor==x){
            f=(*l)->prox;
            (*l)->prox=(*l)->prox->prox;
            free(f);
            r++;
            l=&((*l)->prox);
        }
        else l=&((*l)->prox);
    }
    if (*l){
        if ((*l)->valor==x){
            f=*l;
            *l=NULL;
            free(f);
            r++;
        }
    }
    else{
      if((*l)->prox->valor==x){
            f=(*l)->prox;
            (*l)->prox=NULL;
            free(f);
            r++;
        }  
    }
    return r;
}   
LInt newLInt(int x,LInt l){
    LInt a;
    a->valor=x;
    a->prox=l;
    return a;
}

void adicionaAoFim(LInt *l,int x){
    while (*l && (*l)->prox) l=&((*l)->prox);
    if (*l){
        (*l)->prox=newLInt(x,NULL);
    }
    else *l=newLInt(x,NULL);
}

LInt arrayToList (int v[], int N){
    LInt l=NULL;
    for (int i=0;i<N;i++){
        adicionaAoFim(&l,v[i]);
    }
    return l;
}
int minheapOK (ABin a){
    int r=1;
    if(a){
        if (a->esq){
            if (a->esq->valor<a->valor) r=0;
            else r=minheapOK(a->esq);
        }
        if (a->dir){
            if (a->dir->valor<a->valor) r=0;
            else r=minheapOK(a->dir);
        }
    }
    return r;
}
int max(int a,int b){
    return a>b?a:b;
}

int maxHeap (ABin a){
    if(a->esq && a->dir) return max(maxHeap(a->dir),maxHeap(a->esq));
    else if (a->esq) return maxHeap(a->esq);
    else if (a->dir) return maxHeap(a->dir);
    else return a->valor;
}

ABin max2(ABin a,ABin b){
    return a->valor>b->valor?a:b;
}
ABin min(ABin a,ABin b){
    return a->valor<=b->valor?a:b;
}
void insereArv(ABin *a,ABin b){
    ABin aux;
    if(!(*a)->esq) (*a)->esq=b;//nao ha nada a esquerda
    else if(!(*a)->dir) (*a)->dir=b;//nao ha nada a dir
    else if((*a)->esq->valor<b->valor) insereArv(&((*a)->esq),b);//o esquerda é menor
    else if((*a)->dir->valor<b->valor) insereArv(&((*a)->dir),b);//o direita é menor
    else{//dor de cabeça
        aux=(*a)->esq;
        (*a)->esq=b;
        insereArv(&((*a)->esq),aux);
    }
}

void add(ABin *a,int x){
    ABin b;
    b->valor=x;b->esq=NULL;b->dir=NULL;
    if(x>(*a)->valor){
        insereArv(a,b);
    }   
    else{
        b->esq=*a;
        *a=b;
    }
}


void removeMin (ABin *a){
    ABin f=*a,m,M;
    if(!(*a)->esq) *a=(*a)->dir;
    else if(!(*a)->dir) *a=(*a)->esq;
    else{
        m=min((*a)->esq,(*a)->dir);
        M=max2((*a)->esq,(*a)->dir);
        insereArv(&m,M);
        *a=m;
    }
    free(f);
}

void heapSort (int v[], int N){
    ABin a;
    int i;
    for(i=0;i<N;i++){
        add(&a,v[i]);
    }
    for (i=0;i<N;i++){
        v[i]=a->valor;
        removeMin(&a);
    }
}

int kMaior (int v[], int N, int k){
    ABin a;
    int i;
    for (i=0;i<N && i<k;i++){
        add(&a,v[i]);
    }
    for (i=k;i<N;i++){
        if (v[i]>a->valor){
            removeMin(&a);
            add(&a,v[i]);
        }
    }
    return a->valor;
}

void print(ABin a){
    if(a){
        printf("%d ",a->valor);
        print(a->esq);
        print(a->dir);
    }
}


int main(){
    char c[]="abcdf";
    printf("%d\n",difConsecutivos(c));
    return 0;
}