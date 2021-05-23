#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct posicao {
    int x, y;
    } Posicao;
typedef struct slist {
    int valor;
    struct slist *prox;
    } *LInt;
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
    } *ABin;


int iguais(char s1[], char s2[]){
    int r=1;
    for(int i=0;s2[i]!=0;i++){
        if(s2[i]!=s1[i]){
            r=0;
            break;
        }
    }
    return r;
}

char *strstr (char s1[], char s2[]){
    int i;
    char *r=NULL;
    for(i=0;s1[i]!=0;i++){
        if(iguais(s1+i,s2)){
            r=s1+i;
            break;
        }
    }
    return r;
}

void movetudo(char s[]){
    for(int i=0;s[i]!=0;i++) s[i]=s[i+1];
}

void truncW (char t[], int n){
    int ler,nesc=0;
    for(ler=0;t[ler]!=0;ler++){
        if (t[ler]==' ') nesc=0;
        else if (nesc<n) nesc++;
        else{
            movetudo(t+ler);
            ler--;
        }
    }
}

int maisCentral (Posicao pos[],int N){
    int p=-1;
    double dist=-1,temp;
    for(int i = 0;i<N;i++){
        temp=sqrt(pos[i].x^2+pos[i].y^2);
        if (dist<0 || temp<dist){
            dist = temp;
            p=i;
        }
    }
    return p;
}

LInt newLInt(int x,LInt l){
    LInt a;
    a->valor=x;
    a->prox=l;
    return a;
}


void adiciona( LInt l,int x){
    LInt a = newLInt(x,NULL);
    while(l && l->prox){
        l=l->prox;
    }
    if (l) l->prox=a;
    else l=a; 
}

LInt somasAcL (LInt l){
    LInt a;
    int somatorio=0;
    while (l){
        somatorio+=l->valor;
        adiciona(a,somatorio);
    }
    return a;
}
ABin newABin(int x,ABin e,ABin d){
    ABin elem;
    elem->valor=x;
    elem->esq=e;
    elem->dir=d;
}
int addOrd (ABin *a, int x){
    int r=0;
    ABin elem=newABin(x,NULL,NULL);
    while(*a){
        if(x>(*a)->valor){
            if((*a)->dir) a=&((*a)->dir);
            else {
                (*a)->dir=elem;
                break;
            }
        }
        else if (x<(*a)->valor){
            if((*a)->esq) a=&((*a)->esq);
            else {
                (*a)->esq=elem;
                break;
            }
        }
        else {
            r=1;
            break;
        }
    }
    return r;
}
typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e){
    int i;
    for (i=0;s[i]==' ' && s[i]!='\0';i++);
    *e=i;
    if (s[i]=='\0') return 0;
    else{
        for (i;s[i]!=' ' && s[i]!='\0';i++);
        return i-(*e);
    }
}
Palavras newPalavras(char *palavra,int comp,Palavras prox){
    Palavras a;
    a->comp=comp;
    a->palavra=palavra;
    a->prox=prox;
} 

void adicionafimP(char *palvara,int comp,Palavras a){
    while(a && a->prox){
        a=a->prox;
    }
    if(a) a->prox=newPalavras(palvara,comp,NULL);
    else a==newPalavras(palvara,comp,NULL);
}

Palavras words (char *texto){
    Palavras p=NULL;
    int compT=0,inicio,comp;
    while(texto[compT]!='\0'){
        comp=daPalavra(texto+compT,&inicio);
        adicionafimP(texto+compT+inicio,comp,p);
        compT=compT+inicio+comp;
    }
    return p;
}

void adicionafimPa(Palavras o,Palavras d){
    while(o && o->prox){
        o=o->prox;
    }
    if(o) o->prox=d;
    else o==d;
}

Palavras menor(Palavras t,int n){
    Palavras a=NULL;
    int comp=n;
    while (t){
        if (t->comp<comp) a=t;
        t=t->prox;
    }
}
void remove(Palavras *a,Palavras b){
    if (*a==b) *a=(*a)->prox; // logo de estoura
    else{
        while((*a)->prox){   //esta mais para a frente
            if ((*a)->prox==b) {
                (*a)->prox==(*a)->prox->prox;
                break;
            }
            a=&((*a)->prox);
        }
    }
}
Palavras daLinha (Palavras t, int n){
    Palavras a=NULL,aux;
    int somatorio=0;
    while(somatorio<n){
        aux=menor(t,n);
        if (aux->comp+somatorio>n) break;
        else{
            adicionafimPa(a,aux);
            remove(&t,aux);
        }
    }
    aux=t;
    t=a;
    return aux;
}

void escreveLinha (Palavras p, int n){
    
}


int main(){
    char c[]=" liberdade, igualdade e fraternidade";
    int e,i=daPalavra(c,&e);
    printf("%d,%d\n",i,e);
    return 0;
}