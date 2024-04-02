// Nome: Erick Martins Silva
// Data: 05/03/24
// Instituição: CEFET/RJ
// Descrição: O programa abaixo informa para o usuário o número de parlamentares de determinado estado com base no número de cidadãos do mesmo

#include <stdio.h>

int main()
{
    float popuf, numdep;
    printf("Para saber o numero de parlamentares, entre com o numero de cidadoes de seu estado: ");
    scanf("%f", &popuf);
    numdep = popuf * 513.0 / 190755799.0;
    if (numdep <= 8)
    {
        printf("Numero de parlamentares: 8");
    }
    else if (numdep > 8 && numdep <= 70)
    {
        printf("Numero de parlamentares: %.0f", numdep);
    }
    else
    {
        printf("Numero de parlamentares: 70");
    }
    return 0;
}