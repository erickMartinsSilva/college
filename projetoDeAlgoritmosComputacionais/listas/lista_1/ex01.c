#include <stdio.h>

int somaNumeros (int a, int b) {
    printf("Soma de %d e %d = %d", a, b, a + b);
    return a + b;
}
int main() {
    int a, b, s;
    printf("Insira dois numeros: ");
    scanf("%d %d", &a, &b);
    s = somaNumeros(a,b);
    return 0;
}