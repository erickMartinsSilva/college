// O programa, com base no salário de uma pessoa física, calcula seu imposto de renda e salário líquido

#include <stdio.h>

int main()
{
    float sb,sl,ali,vd,irfp;
    printf("Informe seu salario atual: ");
    scanf("%f", &sb);
    if (sb <= 1903.98)
    {
        ali = 0;
        vd = 0;
    }
    else if (sb > 1903.98 && sb <= 2826.65)
    {
        ali = 0.075;
        vd = 142.05;
    }
    else if (sb > 2826.65 && sb <= 3751.05)
    {
        ali = 0.15;
        vd = 354.08;
    }
    else if (sb > 3751.05 && sb <= 4664.68)
    {
        ali = 0.225;
        vd = 636.13;
    }
    else
    {
        ali = 0.275;
        vd = 869.36;
    }
    irfp = (sb * ali) - vd;
    sl = sb - irfp;
    printf("Imposto de renda: %.2f\n", irfp);
    printf("Salario liquido: %.2f", sl);
    return 0;
}
