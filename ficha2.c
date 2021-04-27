#include <stdio.h>

float multInt1 (int n, float m){
    float r=0.0;
    int i;
    for(i = 0;i<n;i++){
        r=r+m;
    }
    return r;
}
float multInt2 (int n, float m){
    float somatorio = 0;
    for (;n>0;n=n/2){
        if (n%2==1) somatorio+=m;
        m*=2;
    }
    return somatorio;
}

int mdc1 (int a, int b){
    if (b<a){
        int c =a;
        a=b;
        b=c;
    }
    int i;
    for (i=a;a>0;i--){
        if (a%i==0&&b%i==0) return i;
    }
}
int mdc2 (int a, int b){
    while(a!=b){
        if (a>b) a-=b;
        if (b>a) b-=a; 
    }
    return a;
}
int mdc4 (int a, int b){
    while(a!=b){
        if (a>b) a%=b;
        if (b>a) b%=a; 
    }
    return a;
}


int fib (int n){
    if (n<2) return 1;
    else return fib(n-1)+fib(n-2);
}
int fastfib(int n){
    int i,a1=1,a2=1,aa2;
    for (i=1;i<n;i++){
        aa2=a2;
        a2=a1;
        a1=aa2+a2;
    }
    return a1;
}
int main() {
    printf("%d %d\n",fib(7),fastfib(7));
    return 0;
}