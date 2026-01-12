// calcula_numero_deputados.c: calcula o número máximo de parlamentares de um estado com base na sua população

#include <stdio.h>

int main()
{
    float populacao_estado, numero_deputados;

    printf("Entre com o numero de cidadoes do estado: ");
    scanf("%f", &populacao_estado);

    numero_deputados = populacao_estado * 513.0 / 190755799.0;
    
    // um estado deve ter entre 8 e 70 deputados
    if (numero_deputados <= 8)
    {
        printf("Numero de deputados: 8");
    }
    else if (numero_deputados > 8 && numero_deputados <= 70)
    {
        printf("Numero de deputados: %.0f", numero_deputados);
    }
    else
    {
        printf("Numero de deputados: 70");
    }
    return 0;
}
