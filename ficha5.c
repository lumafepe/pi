#include <stdio.h>
#include <math.h>

typedef struct aluno{
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
    } Aluno;

int nota (Aluno a){
    float s=0;
    int i;
    for (i=0;i<6;i++){
        s+=a.miniT[i]*10;
    }
    if (s/6<8||a.teste<8) return 0;
    else{
        s=(s/6)*0.3+a.teste*0.7;
        return round(s);
    }
}

int procuraNum (int num, Aluno t[], int N){
    int i = 0;
    while (t[i++].numero<num && i<N);
    if (t[i].numero==num) return i;
    else return -1;
}

void ordenaPorNum (Aluno t [], int N){
    int i=1;
    Aluno a;
    while (i<N){
        if ( t[i-1].numero>t[i].numero ){
            a = t[i];
            t[i]=t[i-1];
            t[i-1]=a;
            if (i>1) i-=2;
        }
        i++;
    }
}

void ordenaPorNum2 (Aluno t [], int N){
    int i=1,j=1;
    Aluno a;
    while (j){
        j=0;
        i=1;
        while (i<N){
            if ( t[i-1].numero>t[i].numero ){
                a = t[i];
                t[i]=t[i-1];
                t[i-1]=a;
                j=1;
            }
            i++;
        }
    }
}





int in(int a[],int b,int N){
    int i;
    for (i=0;i<N;i++){
        if (a[i]==b) return 1;
    }
    return 0;
}



void criaIndPorNum2(Aluno t [], int N, int ind[]){
    int s=0,i,minp,minn;
    while (s<N){
        minp=0;
        minn=11111;
        for (i=0;i<N;i++){
            if (t[i].numero<minn && !in(ind,i,s)) {
                minn=t[i].numero;
                minp=i;
            }
        }
        ind[s]=minp;
        s++;
    }
}


void imprimeTurma (int ind[], Aluno t[], int N){
    int i,j;
    for (i=0;i<N;i++){
        Aluno a =t[ind[i]];
        printf("nº:%d,Nome:%s,NotasM:",a.numero,a.nome);
        for (j=0;j<6;j++){
            printf("%d ",a.miniT[j]);
        }
        printf(",Teste:%g",a.teste);
        printf("\n");
    }
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    int i,j;
    for (i=0;i<N && num<t[ind[i]].numero ;i++){}
    if (t[ind[i]].numero==num) return ind[i];
    else return -1;
}

int maior (char a[],char b[]){
    int i;
    for(i=0;a[i]!='\0' && b[i]!='\0';i++){
        if (a[i]<b[i]) return 1;
        else if (a[i]>b[i]) return 0;
    }
    if (a[i]!='\0' || (a[i]=='\0' && b[i]=='\0')) return 0;
    else return 1;
}


void criaIndPorNome (Aluno t [], int N, int ind[]){
        int s=0,i,j;
    while (s<N){
        int minp=0;
        char minn[100];
        minn[0]='~';
        for (i=0;i<N;i++){
            if (maior(t[i].nome,minn) && !in(ind,i,s)) {
                for (j=0;t[i].nome[j]!='\0';j++){
                    minn[j]=t[i].nome[j];
                }
                minn[j]='\0';
                minp=i;
            }
        }
        ind[s]=minp;
        s++;
    }
}


int main(){
    Aluno Turma1 [4] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                      ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
                      ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                      ,{7777, "Luis", {2,2,2,2,2,2}, 20}
                      };
    int a[4];
    ordenaPorNum(Turma1,4);
    printf("%d",nota(Turma1[3]));
    return 0;
}