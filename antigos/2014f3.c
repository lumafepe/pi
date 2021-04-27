#include <stdio.h>

void swap(int *x, int *y);

int main() {

    int x = 3, y = 5;
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;

}

void swap(int *x, int *y) {
    int j = *y;
    *y=*x;
    *x=j;
}