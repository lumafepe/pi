#include <stdio.h>

int main() {
    int numero=1,somatorio=0,cont=-1;
    while (numero != 0) {
        scanf("%d", &numero);
        somatorio=somatorio+numero;
        cont++;
    }
    printf("%d\n",somatorio/cont);
    return 0;
}