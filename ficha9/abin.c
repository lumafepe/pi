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

void dumpABin (ABin a, int N){
    if (a){
        dumpABin(a->esq,N);
        printf("%d ",a->valor);
        dumpABin(a->dir,N);
    }
}
void dumpABin2 (ABin a){
    if (a){
        dumpABin2(a->esq);
        printf("%d ",a->valor);
        dumpABin2(a->dir);
    }
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
        if(l==1) printf("%d ",a->valor);
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
int dupQueue (DQueue q) {
	int r = 0, i;
	ABin *t = malloc (2*q->size*sizeof(ABin));
	if (t == NULL) r = 1;
	else {
		for (i=0; i<q->size; i++) 
			t[i] = q->values[i];
		free (q->values);
		q->values = t;
		q->size*=2;
	}
	return r;
}

void DinitQueue (DQueue q) {
	q->front=0;
    q->size=Max;
    q->length=0;
    q->values=(ABin *) malloc(sizeof(ABin)*q->size);
}

int  DisEmptyQ (DQueue s) {
	return s->length == 0;
}

int  Denqueue (DQueue q, ABin x){
	int r = 0;
    if (q->length == q->size) r=dupQueue(q);
    if (!r) q->values[(q->front + q->length++) % q->size] =x;
	return r;
}

int  Ddequeue (DQueue q, ABin *x){
	int r=0;
    if (!DisEmptyQ(q)){
        *x=q->values[q->front++];
        q->length--;
        q->front = q->front%Max;
    }
    else r=1;
	return r;
}



void imprimeArvAux(DQueue q){
    ABin x;
    Ddequeue(q,&x);
    if (x){
        printf("%d ",x->valor);
        Denqueue(q,x->esq);
        Denqueue(q,x->dir);
    }
}

void imprimeA(ABin x){
    DQueue q;
    DinitQueue(q);
    while (!DisEmptyQ(q)){
        imprimeArvAux(q);
    }
}