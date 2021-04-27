#include <stdio.h>

void swapM (int *x, int *y){
    int a;
    a = *x;  // a tem o valor contido no pointer x
    *x = *y; // x tem o valor contido no pointer y
    *y = a;  // y tem o valor contido em a
}
void swap (int v[], int i, int j){
    int a;
    a=v[i];
    v[i]=v[j];
    v[j]=a;
}
int soma (int v[], int N){
    int somatorio=0,i;
    for(i=0;i<N;i++){somatorio+=v[i];}
    return somatorio;
}
void inverteArray (int v[], int N){
    int i;
    N--;
    for (i=0;i<N;i++){
        swap(v,i,N);
        N--;
    }
}
void inverteArray2 (int v[], int N){
    int i;
    N--;
    for (i=0;i<N;i++){
        swapM(v+i,v+N);
        N--;
    }
}

int maximum (int v[], int N, int *m){
    int i,max;
    if(N>0){
        max=v[0];
        for (i=1;i<N;i++){
            if (v[i]>max) max=v[i];
        }
        *m = max;
        return 0;
    }
}
void quadrados (int q[], int N){
    int i;
    q[0]=0;
    for (i=0;i<N-1;i++){
        q[i+1]=q[i]+(2*i+1);
    }
}

void pascal (int v[], int N){
    int q[N-1],i;
    v[0]=1;
    v[N-1]=1;
    if (N>1){
        pascal(q,N-1);
        for (i=1;i<N-1;i++){
            v[i]=q[i-1]+q[i];
        }
    }
}


void pascal2 (int N){
    int i,j,c;
    for (i=1;i<=N;i++){
        c=1;
        for(j=1;j<=i;j++){
            printf("%d ",c);
            c = c*(i-j)/j;
        }
        printf("\n");
    }
}



int main(){
    int x[6]={1,2,3,4,5,6};
    pascal2(10);
    return 0;
}