#include <stdio.h>

int main() {
    int input, x;
    scanf("%d", &input);
    x = input ^ 2;
    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            if (x % 2 == 0) {
                printf("_");
            } else {
                printf("#");
            }
            x--;
        }
        printf("\n");
    }
}