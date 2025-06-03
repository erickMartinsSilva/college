#include <stdio.h>

int calcula_soma (int a, int b, int c) {
    return a + b + c;
}
int calcula_media (int a, int b, int c) {
    return (a + b + c) / 3;
}
int main() {
    int a, b, c;
    printf("Insira tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Soma = %d\n", calcula_soma(a,b,c));
    printf("Media = %d\n", calcula_media(a,b,c));
    return 0;
}