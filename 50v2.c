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
int main(){
    LInt a=newLInt(5,NULL);
    LInt d=newLInt(3,a);
    LInt c=newLInt(1,d);
    imprimeL(c);
    printf("%d\n",removeOneOrd(&c,5));
    imprimeL(c);
    return 0;
} 
