// O programa informa ao usuário o número máximo de deputados por UF com base em certos parâmetros

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