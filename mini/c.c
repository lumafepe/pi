#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo * prox;
} *LInt;

LInt newLInt (int x, LInt xs){
    LInt r = malloc (sizeof(struct nodo));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

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

LInt cria() {
    LInt a=NULL;
    int c=0;
    for (int i =0;i<10;i++){
        inserefim(&a,c);
        c+=7;
    }
}
void imprimeL (LInt a){
    while (a){
        printf("%d\n",a->valor);
        a=a->prox;
    }
}
int main(){
    LInt a=newLInt(70,NULL);
    LInt b =newLInt(63,a);
    LInt c=newLInt(56,b);
    LInt d =newLInt(49,c);
    LInt e=newLInt(42,d);
    LInt f =newLInt(35,e);
    LInt g=newLInt(28,f);
    LInt h =newLInt(21,g);
    LInt i =newLInt(14,h);
    LInt j=newLInt(7,i);
    LInt k =newLInt(0,j);
    imprimeL(k);
    return 0;
}