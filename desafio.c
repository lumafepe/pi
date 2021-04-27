#include <stdio.h>

int main(){
    int x=21,in,out=0;
    while (x>1){
        printf("esta em: %d\n",x);
        printf("manda vir: ");
        scanf("%d",&in);
        out=5-in;
        printf("eu reduzo: %d\n",out);
        x=x-5;
    }
    printf("esta em: %d\n",x);
    if(x==1) printf("perdes-te\n");
    else printf("ganhas-te wtf \n");
    return 0;
}
