#include <stdio.h>

int le_calcula_soma (int a, int b, int c) {
    scanf("%d %d %d", &a, &b, &c);
    int soma = a + b + c;
    return soma;
}
int calcula_media (int soma) {
    return soma / 3;
}
int main() {
    int a, b, c, soma;
    printf("Insira tres numeros: ");
    soma = le_calcula_soma(a,b,c);
    printf("Soma = %d\n", soma);
    printf("Media = %d\n", calcula_media(soma));
    return 0;
}