#include "abin.h"

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
int constroiEspinhaAux (ABin *a, ABin *ult){
    int r=0;
    ABin aux;
    if(*a){
        if(!(*a)->esq && !(*a)->dir){
            *ult = *a;
            r++;
        }
        else if (!((*a)->esq)){
            r=r + 1 + constroiEspinhaAux(&((*a)->dir),ult);
            }
        else{ 
            r = r + 1 + constroiEspinhaAux(&((*a)->esq),&aux);
            if (!(*a)->dir) *ult = *a;
            else{
                r = r + constroiEspinhaAux(&((*a)->esq),ult);  
            }
            aux->dir=*a;
            aux = (*a)->esq;
            (*a)->esq=NULL;
            *a=aux;
        }
    }
    else (*ult)=NULL; 
    
    
    
    
    return r;
}
int constroiEspinha2 (ABin *a){
    ABin ult;
    return (constroiEspinhaAux (a,&ult));
}
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


void dumpABin (ABin a, int N){
    if (a){
        dumpABin(a->esq,N);
        printf("%d ",a->valor);
        dumpABin(a->dir,N);
    }
}