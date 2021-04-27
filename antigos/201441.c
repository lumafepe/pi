#include <stdio.h>

int main() {
    int numero1,numero2,sum=0;
    printf("1º numero: ");
    scanf("%d",&numero1);
    printf("2º numero: ");
    scanf("%d",&numero2);
    for(int i=0;i<numero1;i++){
        sum=sum+numero2;
    }
    printf("é igual a: %d\n",sum);
    return 0;
}