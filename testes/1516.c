#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


char *mystrcpy (char *dest, char source[]){
    int i;
    for (i=0;source[i]!='\0';i++){
        *(dest+i)=source[i];
    }
    *(dest+i)=source[i];
    return dest;
}

void moves(char s[]){
    int i;
    for (i=0;s[i]!='\0';i++){
        s[i]=s[i+1];
    }
}


void strnoV (char s[]){
    int i=0;
    while(s[i]!='\0'){
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            moves(s+i);
        }
        else i++;
    }
}
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
    } *ABin;

int dumpAbin (ABin a, int v[], int N){
    int escrever=0;
    if(a){
        if(escrever<N) escrever+=dumpAbin(a->esq,v,N);
        if(escrever<N) v[escrever++] = a->valor;
        if(escrever<N) escrever+=dumpAbin(a->dir,v,N);
    }
    return escrever;
}
int lookupAB (ABin a, int x){
    int r=0;
    while (a){
        if(a->valor==x){
            r=1;
            break;
        }
        else if(a->valor>x){
            a=a->esq;
        }
        else a=a->dir;
    }
    return r;
}

typedef struct listaP{
    char *pal;
    int cont;
    struct listaP *prox;
    } Nodo, *Hist;



Hist newHist(char *pal,int cont,Hist a){
    Hist n;
    n->pal=pal;
    n->cont=cont;
    n->prox=a;
    return n;
}
int maiormenorigual(char s1[],char s2[]){
    int i=0,r=0;
    while(s1[i]!='\0' && s2[i]!='\0'){
        if(s1[i]>s2[i]){
            r=1;break;
        }
        else if(s1[i]<s2[i]){
            r=-1;break;
        }
    }
    if(r==0){
        if(s1[i]) r=1;
        else if (s2[i]) r=-1; 
    }
    return r;
}


int inc(Hist *h, char *pal){
    int r=0,aux;
    Hist temp;
    while(*h && (*h)->prox){
        aux=maiormenorigual(pal,(*h)->pal);
        if(aux==0){
            (*h)->cont+=1;r=(*h)->cont;break;
        }
        else if(aux=1){
            if(maiormenorigual(pal,(*h)->prox->pal)==-1){
                temp=(*h)->prox;
                (*h)->prox=newHist(pal,1,temp);
                r=1;
                break;
            }
            else h=&((*h)->prox);
        }
        else{
            temp=*h;
            *h=newHist(pal,1,temp);
            r=1;
            break;
        }
    }
    if(!r){
        if(*h){
            (*h)->prox=newHist(pal,1,NULL);r=1;
        }
        else{
            *h=newHist(pal,1,NULL);r=1;
        }
    }
    return r;
}


int maximum(Hist h){
    int max=0;
    while(h){
        if (h->cont>max) max=h->cont;
        h=h->prox;
    }
    return max;
}


char *remMaisFreq(Hist *h, int *count){
    Hist temp;
    char *r=NULL;
    *count = maximum(*h);
    if(*h){
        if((*h)->cont==*count){
            r=(*h)->pal;
            *h=(*h)->prox;
        }
        else{
            while (*h && (*h)->prox){
                if((*h)->prox->cont==*count){
                    r=(*h)->prox->pal;
                    (*h)->prox=(*h)->prox->prox;break;
                }
                else h=&((*h)->prox);
            }
        }
    }
    return r;
}

void strnoN(char s[]){
    int i=0;
    while(s[i]!='\0'){
        if(!isalpha(s[i])){
            moves(s+i);
        }
        else i++;
    }
}
void passaCaps(char s[]){
    for(int i = 0;s[i]!='\0';i++){
        if(islower(s[i])){
            s[i]=toupper(s[i]);
        }
    }
}


void destroy(Hist *h){
    Hist aux;
    while(*h){
        aux=*h;
        *h=(*h)->prox;
        free(aux);
    }
}


void imprime(){
    char input[60],*saida;
    Hist baseDeDados;
    int c,count;
    while(scanf("%s\n",&input)){
        strnoN(input);
        passaCaps(input);
        if(strlen(input)>3){
            c=inc(&baseDeDados,input);
        }
    }
    for(c=0;c<10;c++){
        saida=remMaisFreq(&baseDeDados,&count);
        printf("&s &d\n",saida,count);
    }
    free(saida);
    destroy(&baseDeDados);
}

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

int main(){
    srand(time(NULL));
    int v[15]={1,2,3,4,5,6,7,8,9,10,111,12,13,14,15},c[15];
    ABin a1=RandArvFromArray(v,15);
    dumpABin2(a1);
    printf("\n");
    int c1 = dumpAbin(a1,c,15);
    for(int i=0;i<15;i++) printf("%d",c[i]);
    return 0;
}