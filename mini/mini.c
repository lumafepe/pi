#include <stdio.h>
#include <stdlib.h>

typedef struct slist {

  int valor;
  struct slist * prox;
} *LInt;


LInt newLInt (int x, LInt xs) {
  LInt r = malloc (sizeof(struct slist));
  if (r!=NULL) {
    r->valor = x;
    r->prox = xs;
  }
  return r;
}

LInt clone (LInt l) {
  LInt r,a,b;
  r = a = b = NULL;
  while (l) {
    a = newLInt(l->valor,NULL);
  if (!b) r = a; if (b) a->prox = a; b = a;
    l = l->prox;
  }
  return r;
}

void printLInt(LInt l){
   while (l) {
     printf("%d ",l->valor);
     l=l->prox;
   }
}
int init (LInt *l){
  int r = 0;
  if (*l == NULL) r = 1;
  else {
  while ((*l)->prox) l = &((*l)->prox);
    free (*l); *l = NULL;
  } 
  return r;
}
int main(){
  LInt a,b,c;
  a= newLInt(3,NULL);
  c=newLInt(5,a);
  b=newLInt(6,c);
  printLInt(b);
  init(&c);
  printf("\n");
  printLInt(b);
  return 0;
}