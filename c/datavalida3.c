// Nome: Erick Martins SIlva
// Instituição: Cefet/RJ
// Período: 1
// Descrição: O programa obtém uma data na forma de um número inteiro de 8 algarismos (DDMMAAAA), valida ela e retorna o resultado para o usuário final

#include <stdio.h>

int anoBissexto (int data)
{
    int ano = data % 10000;
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validaData (int data)
{
    int ano = data % 10000;
    int mes = (data / 10000) % 100;
    int dia = data / 1000000;
    if (mes == 2)
    {
        if (anoBissexto(ano) == 1)
        {
            if (dia <= 29)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (dia <= 28)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia <= 31)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia <= 30)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int data;
    do
    {
        printf("Escreva uma data (DDMMAAAA) ou -1 para encerrar: ");
        scanf("%d", &data);
        int ano = data % 10000;
        int mes = (data / 10000) % 100;
        int dia = data / 1000000;
        if (data != -1)
        {
            if (validaData(data) == 1)
            {
            printf("Data valida: %d/%d/%d\n", dia, mes, ano);
            }
            else if (validaData(data) == 0)
            {
            printf("Data invalida: %d/%d/%d\n", dia, mes, ano);
            }
        }
    } while (data != -1);
    return 0;
}
