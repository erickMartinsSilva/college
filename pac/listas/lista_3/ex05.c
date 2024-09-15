#include <stdio.h>

int maiorNumero (int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else if (c > a && c > b) {
        return c;
    }
}
int main() {
    int a, b, c;
    printf("Insira tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("O maior numero do conjunto (%d, %d, %d) e %d", a, b, c, maiorNumero(a,b,c));
}