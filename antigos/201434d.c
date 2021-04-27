#include <stdio.h>

int main() {
    int numero=1,maximo=0,maximo2=0;
    while (numero != 0) {
        scanf("%d", &numero);
        if (numero>maximo){
            maximo2=maximo;
            maximo=numero;
        }
        else{
            if (numero>maximo2 || maximo2==0){
                maximo2=numero;
            }
        }
    }
    printf("%d\n",maximo2);
    return 0;
}