#include <stdio.h>

int isvogal(char s){
    char c[]={"aeiou"};
    for(int i=0;i<5;i++){
        if (s==c[i]) return 1;
    }
    return 0;
}

int vogaisiguais(char s,char s1){
    if (s1==s && isvogal(s)) return 1;
    else return 0;
}

int contaVogais (char *s){
    int i=0,j;
    for (j=0;s[j] != '\0';j++){
        i+=isvogal(s[j]);
    }
    return i;
}

int retiraVogaisRep (char *s){
    int j,i=0,c=0;
    for (j=0;s[j] != '\0';j++){
        if ( !vogaisiguais(s[j],s[i-1])){
            s[i]=s[j];
            i++;
        }
    }
    s[i]='\0';
    return j-i;

}
void movetudo(char *s,int i){
    char c,j;
    c=s[i];
    for (i+=1;s[i]!='\0';i++){
        j=s[i];
        s[i]=c;
        c=j;
    }
    s[i]=c;
    s[i+1]='\0';
}
int duplicaVogais (char *s){
    int i,j=0;
    for(i=0;s[i]!='\0';i++){
        if (isvogal(s[i])){
            j++;
            movetudo(s,i);
            i++;
        }
    }
    return j;
}
int ordenado (int v[], int N){
    for(int i=1;i<N;i++){
        if (v[i]<v[i-1]) return 0;
    }
    return 1;
}
void merge (int a[], int na, int b[], int nb, int r[]){
    int ia=0,ib=0;
    for(int i=0;i<na+nb;i++){
        if (ia<na){//a tem elems
            if (ib<nb){ //tem ambos elems
                if (a[ia]>b[ib]){
                    r[i]=b[ib];
                    ib++;
                }
                else{
                    r[i]=a[ia];
                    ia++;
                }
            }
            else{ //so a tem elems
                r[i]=a[ia];
                ia++;
            }
        }
        else{ //so b tem elems
            r[i]=b[ib];
            ib++;
        }
    }
}
int proximo(int v[],int i, int N, int x){
    for(i;i<N;i++){
        if (v[i]<=x) return i;
    }
    return 0;
}
void swap (int v[], int i, int j){
    int a;
    a=v[i];
    v[i]=v[j];
    v[j]=a;
}
int partition (int v[], int N, int x){
    int c,j=0;
    for(int i=0;i<N;i++){
        c=proximo(v,i+1,N,x);
        if (v[i]>x && c!=0){
            swap(v,i,c);
        }
        else if (c==0) break;
        j++;
    }
    return j;
}
int main(){
    char c[100]="fuck life";
    duplicaVogais(c);
    printf("%s\n",c);
    return 0;
}
