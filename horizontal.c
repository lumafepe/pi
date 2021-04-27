#include <stdio.h>

int main() {
    int input, x;
    scanf("%d", &input);
    x=input*2-1;
    for(int i = 1;i<x+2;i=i+2){
        for(int j = 0;j<(x-i)/2;j++){
            printf(" ");
        }
        for(int j = 0;j<i;j++){
            printf("#");
        }
        for(int j = 0;j<(x-i)/2;j++){
            printf(" ");
        }
        printf("\n");
    }
}