// calcula_mdc.c: utiliza o algoritmo de Euclides para calcular o mínimo divisor comum (MDC) entre dois números inteiros.

#include <stdio.h>

int mdc(int numero1, int numero2)
{
    if (numero1 < numero2)
    {
        printf("Como o segundo numero e maior que o primeiro, trocaremos os valores entre eles.");
        int aux = numero1;
        numero1 = numero2;
        numero2 = aux;
        printf("O primeiro numero passa ser %d e o segundo passa a ser %d.\n", numero1, numero2);
    }
    int resto_divisao = numero1 % numero2;
    printf("O resto da divisao entre os dois numeros equivale a %d.\n", resto_divisao);
    while (resto_divisao != 0)
    {
        printf("Como o resto nao equivale a zero, trocaremos o primeiro numero pelo segundo e o segundo pelo resto da divisão entre eles.\n");
        int aux = numero1;
        numero1 = numero2;
        numero2 = aux % numero2;
        resto_divisao = numero1 % numero2;
        printf("Assim, o primeiro numero passa a ser %d e o segundo passa a ser %d e ", numero1, numero2);
        printf("O resto da divisao entre A e B equivale a %d.\n", resto_divisao);
    }
    return numero2;
}
int main()
{
    int numero1, numero2, resto;
    printf("Insira dois numeros: ");
    scanf("%d %d", &numero1, &numero2);
    int mdc_numero1_numero2 = mdc(numero1,numero2);
    printf("Logo, o MDC entre %d e %d = %d.", numero1, numero2, mdc_numero1_numero2);
}
