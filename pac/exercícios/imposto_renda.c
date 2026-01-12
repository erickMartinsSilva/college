// imposto_renda.c: calcula o salário líquido de uma pessoa com base nas alíquotas referentes ao primeiro semestre de 2024

#include <stdio.h>

int main()
{
    float salario_bruto, salario_liquido, aliquota, valor_deduzido, imposto_renda;
    printf("Informe seu salario atual: R$");
    scanf("%f", &salario_bruto);
    if (salario_bruto <= 1903.98)
    {
        // menor que 1903.98 -> isento
        aliquota = 0;
        valor_deduzido = 0;
    }
    else if (salario_bruto > 1903.98 && salario_bruto <= 2826.65)
    {
        aliquota = 0.075;
        valor_deduzido = 142.05;
    }
    else if (salario_bruto > 2826.65 && salario_bruto <= 3751.05)
    {
        aliquota = 0.15;
        valor_deduzido = 354.08;
    }
    else if (salario_bruto > 3751.05 && salario_bruto <= 4664.68)
    {
        aliquota = 0.225;
        valor_deduzido = 636.13;
    }
    else
    {
        aliquota = 0.275;
        valor_deduzido = 869.36;
    }
    imposto_renda = (salario_bruto * aliquota) - valor_deduzido;
    salario_liquido = salario_bruto - imposto_renda;
    printf("Imposto de renda: R$%.2f\n", imposto_renda);
    printf("Salario liquido (apos impostos): R$%.2f", salario_liquido);
    return 0;
}
