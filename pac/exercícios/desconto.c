// desconto.c: calcula o valor de desconto e o valor final a ser pago por um cliente
// O cálculo do desconto funciona da seguinte forma:
// - Para compras entre 200 e 399 reais, é descontado 10% do valor;
// - Para compras entre 400 e 599 reais, é descontado 15% do valor;
// - Para compras de 600 para cima, é descontado 20% do valor.

#include <stdio.h>

int main()
{
    // valor padrão de desconto é zero, caso o valor_total não se encaixe em nenhuma das opções
    float valor_total, desconto = 0, valor_final;
    printf("Insira o valor total de suas compras: ");
    scanf ("%f", &valor_total);
    if (valor_total >= 200 && valor_total < 400) 
    {
        printf("Desconto obtido: 10%%\n");
        desconto = valor_total * 0.1;
    }
    else if (valor_total >= 400 && valor_total < 600) 
    {
        printf("Desconto obtido: 15%%\n");
        desconto = valor_total * 0.15;
    }
    else if (valor_total >= 600) 
    {
        printf("Desconto obtido, 20%%\n");
        desconto = valor_total * 0.2;
    } else {
        printf("Valor inelegível para desconto\n");
    }
    printf("Valor total das compras: R$%.2f\n", valor_total);
    printf("Valor descontado: R$%.2f\n", desconto);
    valor_final = valor_total - desconto;
    printf("Total a ser pago: R$%.2f", valor_final);
    return 0;
}
