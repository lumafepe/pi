#include <stdio.h>

int main() {
    int n,m;
    printf("1º numero: ");
    scanf("%d",&n);
    printf("2º numero: ");
    scanf("%d",&m);
    while (m!=n){
        if (n>m){
            n=n-m;
        }
        else{
            m=m-n;
        }
    }
    printf("e o preço da montra final é: %d\n",n);
    return 0;
}
