#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//types

typedef struct lligada {
    int valor;
    struct lligada *prox;
    } *LInt;








//funçoes

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

//1
int length (LInt a){
    int r=0;
    while (a){
        r++;
        a=a->prox;
        }
    return r;
}
//2
void freeL (LInt a){
    LInt b;
    while(a && a->prox){
        if(a){
            b=a;
            a=a->prox;
            free(b);
        }
    }
}
//3
void imprimeL (LInt a){
    while (a){
        printf("%d\n",a->valor);
        a=a->prox;
    }
}
//4
LInt reverseL (LInt a){
    LInt b=NULL;
    LInt c;
    while (a){
        c=a->prox;
        a->prox=b;
        b=a;
        a=c;
    }
    return b;
}
//5 esta com bugs
void insertOrd (LInt *a, int x){
    LInt elem = newLInt(x,NULL);
    LInt aux;
    LInt pesquisa=*a;
    int B=1;
    while(pesquisa && pesquisa->prox){
        if (B && pesquisa->valor>x){
            aux=pesquisa->prox;
            pesquisa->prox=elem;
            elem->prox=aux;
            B=0;
        }
        pesquisa=pesquisa->prox;
    }
    if(pesquisa){
        pesquisa->prox = elem;
    }
}
//6
int removeOneOrd (LInt * a , int x){
    int B=1;
    LInt pesquisa=*a;
    LInt ant=NULL;
    while(pesquisa){
        if (pesquisa->valor==x){
            if(ant){
                ant->prox=pesquisa->prox;
                B=0;
                break;
            }
            else{
                *a=(*a)->prox;
                B=0;
                break;
            }
        }
        ant=pesquisa;
        pesquisa = pesquisa->prox;
    }
    return B;
}
//7

void inserefim(LInt *a,int x){
    LInt aux=*a;
    while (aux && aux->prox){
        aux=aux->prox;
    }
    if(aux){
        aux->prox=newLInt(x,NULL);
    }
    else{
        *a=newLInt(x,NULL);
    }
}
void merge (LInt *r, LInt a, LInt b){
    LInt aux;
    while(a && b){
        if (a->valor<b->valor){
            inserefim(r,a->valor);
            a=a->prox;
        }
        else{
            inserefim(r,b->valor);
            b=b->prox;
        }
    }
    if (a){
        while(a){
           inserefim(r,a->valor);
            a=a->prox; 
        }
    }
    else{
      while(b){
           inserefim(r,b->valor);
            b=b->prox; 
        }  
    }
}
//8
void inserefimElem(LInt *a,LInt b){
    LInt aux=*a;
    while (aux && aux->prox){
        aux=aux->prox;
    }
    if(aux){
        aux->prox=b;
    }
    else{
        *a=b;
    }
    b->prox=NULL;
}
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt aux;
    while(l){
        aux = l;
        if(l->valor<x){
            inserefimElem(mx,aux);
        }
        else{
            inserefimElem(Mx,aux);
        }
        l=l->prox;
    }
}
//9
LInt parteAmeio (LInt *l){
    LInt x=NULL,p;
    int comp=length(*l)%2;
    while(comp){
        if(x){
            p=x;
            while(p->prox){
                p=p->prox;
            }
            p->prox=*l;
            p->prox->prox=NULL;
        }
        else{
            x=*l;
            x->prox=NULL;
        }
        *l=(*l)->prox;
        comp--;        
    }
}
//10
int removeAll (LInt *a, int x){
    LInt b=NULL;
    int r=0;
    while (*a && (*a)->valor==x){
        *a=(*a)->prox;
        r++;
    }
    while (*a && (*a)->prox){
        if ((*a)->prox->valor==x){
            b=(*a)->prox;
            (*a)->prox=(*a)->prox->prox;
            free(b);
            r++;
        }
        else a=&((*a)->prox);
    }
    return r;
}
//11
int removeDups (LInt *a){
    int r=0;
    while(*a){
        r+=removeAll(&((*a)->prox),(*a)->valor);
        a=&((*a)->prox);
    }
    return r;
}

//12
int maximo(LInt a){
    int r=0;
    while (a){
        if ((a)->valor>r) r = (a)->valor;
        a=a->prox;
    }
    return r;
}
void removePrimeiraOccor(LInt *a,int x){
    if (*a && (*a)->valor==x){
        *a=(*a)->prox;
    }
    else {
        LInt ant = *a;
        a=&((*a)->prox);
        while ((*a)->valor!=x){
            ant = *a;
            a=&((*a)->prox);
        }
        LInt b = *a;
        ant->prox=(*a)->prox;
        free(b);
    }
}
int removeMaiorL (LInt *a){
    int r = maximo(*a);
    removePrimeiraOccor(a,r);
    return r;
}
//13
void init (LInt *a){
    LInt b;
    if(*a){
        if ((*a)->prox){
            while ((*a)->prox->prox) a=&((*a)->prox);
            b=(*a)->prox;
            (*a)->prox=NULL;
            free(b);
        }
        else *a=NULL;
    }
}
//14
void appendL (LInt *a, int x){
    LInt b=newLInt(x,NULL);
    if (*a){
        while ((*a)->prox) a=&((*a)->prox);
        (*a)->prox=b;
    }
    else *a=b;
}
//15
void concatL (LInt *a, LInt b){
    if (*a){
        while ((*a)->prox) a=&((*a)->prox);
        (*a)->prox=b;
    }
    else *a=b;
}
//16
LInt cloneL (LInt o){
    LInt c=NULL;
    while (o){
        appendL(&c,o->valor);
        o=o->prox;
    }
    return c;
}
//17
LInt appendR(LInt a,int x){
    LInt b=newLInt(x,a);
    return b;
}

LInt cloneRev (LInt a){
    LInt b=NULL;
    while (a){
        b=appendR(b,a->valor);
        a=a->prox;
    }
    return b;
}
//18 esta na 12
//19
void liberta(LInt *a){
    LInt b;
    while (*a){
        b=*a;
        a=&((*a)->prox);
        free(b);
    }
}
int take (int n, LInt *a){
    int r  = 0;
    LInt b;
    while (*a){
        if(n-1>0){
            a=&((*a)->prox);
            n--;
            r++;
        }
        else{
            r++;
            liberta(&((*a)->prox));
            (*a)->prox=0;
            break;    
        }
    }
    return r;
}
//20
int drop (int n, LInt *l){
    LInt b;
    int r=0;
    while(n>0 && *l){
        b = *l;
        *l=(*l)->prox;
        free(b);
        n--;
        r++;
    }
    return r;
}
//21
LInt NForward (LInt l, int N){
    while(N){
        l=l->prox;
        N--;
    }
    return l;
}
//22
int listToArray (LInt l, int v[], int N){
    int i=0,r=0;
    while(l && i<N){
        v[i++]=l->valor;
        l=l->prox;
        r++;
    }
    return r;
}
//23
LInt arrayToList (int v[], int N){
    LInt a;
    for(int i =0;i<N;i++){
        appendL(&a,v[i]);
    }
    if (!N) a=NULL;
    return a;
}
//24
LInt somasAcL (LInt l){
    LInt a=NULL;
    int r=0;
    while (l){
        r+=l->valor;
        appendL(&a,r);
        l=l->prox;
    }
    return a;
}
//25
void remreps (LInt l){
    LInt aux;
    while (l){
        if (l->valor==l->prox->valor){
            aux=l->prox->prox;
            free(l->prox);
            l->prox=aux;
        }
        else l=l->prox;
    }
}
//26
LInt rotateL (LInt l){
    LInt aux,i=l;
    if (l && l->prox){
        aux=l;
        i=l->prox;
        while (l->prox) l=l->prox;
        aux->prox=NULL;
        l->prox=aux;
    }
    return i;
}
//27
LInt parte (LInt l){
    int i=1;
    LInt a=NULL,aux;
    while(l){
        if(!(i%2)){



        }
    }
}
//arv
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
    } *ABin;

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}
//28
int max(int a,int b){
    return a>b?a:b;
}

int altura (ABin a){
    return a?1 + max(altura(a->esq),altura(a->dir)):0;
}
//29 nop
ABin cloneAB (ABin o){
    ABin a;
    if (o){
        a->valor=o->valor;
        a->esq=cloneAB(o->esq);
        a->dir=cloneAB(o->dir);
    }
    else a=NULL;
    return a;
}
//30
void mirror (ABin *a){
    if (*a){
    ABin x=(*a)->esq;
    (*a)->esq=(*a)->dir;
    (*a)->dir=x;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
    }
}
//31
void inorder (ABin a, LInt *l){
    if(a){
        inorder(a->esq,l);
        appendL(l,a->valor);
        inorder(a->dir,l);
    }
}
//32
void preorder (ABin a, LInt *l){
    if(a){
        appendL(l,a->valor);
        preorder(a->esq,l);
        preorder(a->dir,l);
    }
}
//33
void posorder (ABin a, LInt *l){
    if(a){
        posorder(a->esq,l);
        posorder(a->dir,l);
        appendL(l,a->valor);
    }
}
//34
int min(int a,int b){
    if(a==-1) return b;
    else if (b==-1) return a;
    else return a<b?a:b;
}
int depth (ABin a, int x){
    int e,d;
    if(a){
        if (a->valor==x){
            return 1;
        }
        else{
            e=depth(a->esq,x);
            d=depth(a->dir,x);
            if (min(e,d)!=-1) return 1 + min(e,d);
        }
    }
    return -1;
}
//35
int freeAB (ABin a){
    int r=0;
    if(a){
        r+=freeAB(a->esq);
        r+=freeAB(a->dir);
        free(a);
        r++;
    }
    return r;
}
//36
int pruneAB (ABin *a, int l){
    int r=0;
    if (*a && l!=0){
        r+=pruneAB(&((*a)->dir),l-1);
        r+=pruneAB(&((*a)->esq),l-1);
    }
    else{
        r+=freeAB(*a);
        *a=NULL;
    }
    return r;
}
//37
int iguaisAB (ABin a, ABin b){
    if(!a && !b) return 1;
    else if(a && b) return a->valor==b->valor?iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir):0;
    else return 0;
}
//38
LInt nivelL (ABin b, int n){
    LInt a=NULL;
    if (b){
    if (n!=1){
        merge(&a,nivelL(b->esq,n-1),nivelL(b->dir,n-1));
    }
    else a=newLInt(b->valor,NULL);
    }
    return a;
}
//40
int dumpAbin (ABin a, int v[], int N){
    while(a)
}

int main(){
    LInt a;
    ABin b = newABin(5,NULL,NULL);
    ABin c = newABin(7,NULL,NULL);
    ABin d = newABin(6,b,c);
    inorder(d,&a);
    return 0;
} 
