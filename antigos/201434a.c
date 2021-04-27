#include <stdio.h>

int main() {
    int numero=1,somatorio=0;
    while (numero != 0) {
        scanf("%d", &numero);
        somatorio=somatorio+numero;
    }
    printf("%d\n",somatorio);
    return 0;
}