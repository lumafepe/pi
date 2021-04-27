#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            printf("#");
        }
        printf("\n");
    }
}