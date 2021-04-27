#include <stdio.h>

int main() {
    int numero=1,maximo=0;
    while (numero != 0) {
        scanf("%d", &numero);
        if (numero>maximo){
            maximo=numero;
        }
    }
    printf("%d\n",maximo);
    return 0;
}