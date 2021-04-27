#include <stdio.h>



int main(){
    int dtres,dcinco;
    for (int c=1;c<=100;c++){
        dtres=c%3,dcinco=c%5;
        if (!dtres && !dcinco) printf("ping-pong\n");
        else if (!dtres) printf("ping\n");
        else if (!dcinco) printf("pong\n");
        else printf("%d\n",c);
    }
    return 0;
}