#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mini.h"
//nodo normal 

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

void dumpABin2 (ABin a){
    if (a){
        dumpABin2(a->esq);
        printf("%d ",a->valor);
        dumpABin2(a->dir);
    }
}
// Questão 1
ABin removeMenor (ABin *a){
    ABin r=NULL;
    if ( *a ){
        while((*a)->esq) a = &((*a)->esq);
        r=*a;
        *a = (*a)->dir;
    }
    return r;
}
void removeRaiz (ABin *a){
    ABin menor,aux;
    if ( *a ) {
        if ((*a)->dir) menor = removeMenor(&((*a)->dir));
        aux =*a;
        menor->esq = (*a)->esq;
        menor->dir = (*a)->dir;
        *a = menor;
    }
    else {
        aux=*a;
        (*a)->esq;
    }
    free(aux);
}

int removeElem (ABin *a, int x){
    int r=-1;
    while (*a && r==-1){
        if((*a)->valor==x){
            removeRaiz(a);
            r=0;
        }
        else if((*a)->valor>x){
            a=&((*a)->esq);
        }
        else {
            a=&((*a)->dir);
        }
    }
    return r;
}

// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}
void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}
void promoveMenor (ABin *a){
    if (*a && (*a)->esq){
        promoveMenor(&((*a)->esq));
        rodaDireita(a);
    }
}
void promoveMaior (ABin *a){
    if (*a && (*a)->dir){
        promoveMaior(&((*a)->dir));
        rodaEsquerda(a);
    }
}
ABin removeMenorAlt (ABin *a){
    promoveMenor(a);
    ABin r = *a;
    *a=(*a)->dir;
    return r;
}

// Questão 3

int constroiEspinha (ABin *a){
    int r=0;
    while(*a){
        promoveMenor(a);
        a = &((*a)->dir);
        r++;
    }
    return r;
}

ABin equilibraEspinha (ABin *a, int n) {
    ABin r;
    for (int i = 0;i<n && *a;i++) a=&((*a)->dir);
    r=*a;
    for(int i=0;i<n;i++) promoveMaior(a);
	return r;
}

void equilibra (ABin *a) {
    int n = constroiEspinha(a);
    equilibraEspinha(a,n);
}


void freeABin (ABin a){
    if (a){
        freeABin(a->esq);
        freeABin(a->dir);
        free(a);
    }
}

int max(int a,int b){
    return a>b?a:b;
}

int altura (ABin a){
    return a?1 + max(altura(a->esq),altura(a->dir)):0;
}

int nFolhas (ABin a){
    if (!a) return 0;
    else if (a->dir && a->esq) return 1;
    else return nFolhas(a->dir)+nFolhas(a->esq);
}

ABin maisEsquerda (ABin a){
    if (a){
        if(a->esq) return maisEsquerda(a->esq);
        else return a;
    }
    else return NULL;
}

void imprimeNivel (ABin a, int l){
    if (a){
        if(l==1) printf("%d",a->valor);
        else if (l==2){
          imprimeNivel(a->esq,l-1);
          printf("e ");
          imprimeNivel(a->dir,l-1);
          printf("d ");
        }
        else{
            imprimeNivel(a->esq,l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}

int procuraE (ABin a, int x){
    return a?(a->valor==x || procuraE(a->esq,x) || procuraE(a->dir,x)):0;
}

struct nodo *procura (ABin a, int x){
    if(a){
        if(a->valor==x) return a;
        else if (x<a->valor) return procura(a->esq,x);
        else return procura(a->dir,x);
    }
    else return NULL;
}

int nivel (ABin a, int x){
    int r;
    if(a){
        if (a->valor==x) return 1;
        else{
            r=max(nivel(a->esq,x),nivel(a->dir,x));
            return (r!=-1)?1+r:-1;
        }
    }
    else return -1;
}

void imprimeAte (ABin a, int x){
    if(a){
        if(a->valor==x) dumpABin2(a->esq);
        else if (a->valor > x) imprimeAte(a->esq,x);
        else{
            dumpABin2(a->esq);
            printf("%d ",a->valor);
            imprimeAte(a->dir,x);
        } 
    }
}
void printArvore(ABin a){
  for (int i =0;i<altura(a);i++){
    imprimeNivel(a,i);
    printf("\n");
  }
}





int main(){
  srand(time(NULL));
  int v1[15] = { 1, 3, 5, 7, 9,11,13,15,17,19,21,23,25,27,29},N=15;
  ABin a1 = RandArvFromArray (v1, N);


  printArvore(a1);
  return 0;
}