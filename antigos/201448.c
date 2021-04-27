#include <stdio.h>


int fib(int n);

int main() {
    int n, j1 = 1, j2 = 1, ac;
    printf("numero: ");
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        ac = j1;
        j1 = j2 + j1;
        j2 = ac;
    }
    printf("fibonacci %d\n", j1);
    return 0;
}

int fib(int n) {
    if (n < 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}