#include <stdio.h>

int main() {
    int n, m, bin = 0;
    printf("1º numero: ");
    scanf("%d", &n);
    printf("2º numero: ");
    scanf("%d", &m);
    while (n !=0&& m!=0) {
        if (n % 2 == 0) {
            if (m % 2 == 0) {
                bin++;
                n = n >> 2;
                m = m >> 2;
            } else n = n >> 2;
        } else {
            if (m % 2 == 0) m = m >> 2;
            else {
                if (n >= m) n = (n - m) >> 2;
                else m = (m - n) >> 2;
            }
        }
    }
    if (n == 0) printf("e o preço da montra final é: %d\n", m<<(2^bin));
    else printf("e o preço da montra final é: %d\n", n<<(2^bin));
    return 0;
}