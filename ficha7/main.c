#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras , Celula;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

void libertaLista (Palavras l){
    if (l) libertaLista(l->prox);
    free(l);
}

int quantasP (Palavras l){
    if (l) return 1+quantasP(l->prox);
    else return 0;
}

void listaPal (Palavras l){ // versao recursiva
    if (l){
        printf("%s - %d\n",l->palavra,l->ocorr);
        listaPal(l->prox);
    }
}
void listaPal2 (Palavras l){ // versao iterativa
    while (l){
        printf("%s - %d\n",l->palavra,l->ocorr);
        l=l->prox;
    }
}


char * ultima (Palavras l){
    while (l && l->prox) l=l->prox;
    return l?l->palavra:NULL;
}
char * ultima2 (Palavras l){
    if (l) return NULL;
    else if (l->prox==NULL) return l->palavra;
    else ultima2(l->prox);  
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras a = malloc(sizeof(Celula));
    a->palavra = strdup(p);
    a->ocorr = 1;
    a->prox=l;
    return a;
}
Palavras acrescentaFim (Palavras l, char *p){ // iterativa;
    Palavras a = l;
    while (l && l->prox) l = l->prox;
    
    if (l) l->prox = acrescentaInicio(l->prox,p);
    else a = acrescentaInicio(a,p); 
    
    return a;
}
Palavras acrescenta (Palavras l, char *p){
    if (!l || strcmp(l->palavra,p)<0) l = acrescentaInicio(l,p);
    else if (strcmp(l->palavra,p) == 0) l->ocorr++;
    else l->prox = acrescenta(l->prox,p);
    return l;
}
Palavras maisFreq (Palavras l){
    int max=0;
    Palavras a = NULL;
    while (l){
        if (l->ocorr > max){
            a = l; 
            max=l->ocorr;
        }
        l=l->prox;
    }
    return a;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}

