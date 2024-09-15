#include <stdio.h>

int menorQtdCedulas(int valor) {
    if (valor / 100 > 0) {
        printf("%d cedulas de R$100\n", valor/100);
        valor %= 100;
    }
    if (valor / 50 > 0) {
        printf("%d cedulas de R$50\n", valor/50);
        valor %= 50;
    }
    if (valor / 20 > 0) {
        printf("%d cedulas de R$20\n", valor/20);
        valor %= 20;
    }
    if (valor / 10 > 0) {
        printf("%d cedulas de R$10\n", valor/10);
        valor %= 10;
    }
    if (valor / 5 > 0) {
        printf("%d cedulas de R$5\n", valor/5);
        valor %= 5;
    }
    if (valor / 2 > 0) {
        printf("%d cedulas de R$2\n", valor/2);
        valor %= 2;
    }
    if (valor / 1 > 0) {
        printf("%d cedulas de R$1\n", valor);
    }
    return 0;
}
int main() {
    int valor;
    printf("Insira o valor a ser sacado: R$");
    scanf("%d", &valor);
    menorQtdCedulas(valor);
    return 0;
}