#include <stdio.h>

int main() {
    int input, x;
    scanf("%d", &input);
    for(int i=1;i<input+1;i++){
        for(int j=0;j<i;j++){
            putchar("#");
        }
        putchar("\n");
    }
    for(int i=input-1;i>0;i--){
        for(int j=0;j<i;j++){
            putchar("#");
        }
        putchar("\n");
    }
    return 0;
}