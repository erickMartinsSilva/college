#include <stdio.h>

int calcula_soma (int a, int b, int c) {
    return a + b + c;
}
int calcula_media (int soma) {
    return soma / 3;
}
int main() {
    int a, b, c, soma;
    printf("Insira tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);
    soma = calcula_soma(a,b,c);
    printf("Soma = %d\n", soma);
    printf("Media = %d\n", calcula_media(soma));
}