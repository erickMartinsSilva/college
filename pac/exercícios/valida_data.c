// valida_data.c: cria uma data com base num número de 8 algarismos informado pelo usuário e valida ela

#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int dia, mes, ano;
} Data;

void print_data(Data data) {
  printf("%d/%d/%d", data.dia, data.mes, data.ano);
}

bool is_ano_bissexto (int ano)
{
    return ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0);
}

bool is_data_valida (Data data)
{
    if (data.mes == 2)
    {
        if (is_ano_bissexto(data.ano))
        {
            if (data.dia <= 29)
            {
                return true;
            }
            else
            {
                printf("Data invalida: no mes de fevereiro, para este ano, o dia deve estar entre 1 e 29\n");
                return false;
            }
        }
        else
        {
            if (data.dia <= 28)
            {
                return true;
            }
            else
            {
                printf("Data invalida: no mes de fevereiro, para este ano, o dia deve estar entre 1 e 28\n");
                return false;
            }
        }
    }
    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        if (data.dia <= 31)
        {
            return true;
        }
        else
        {
            printf("Data invalida: para o mes %d, o dia deve estar entre 1 e 31\n", data.mes);
            return false;
        }
    }
    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    {
        if (data.dia <= 30)
        {
            return true;
        }
        else
        {
            printf("Data invalida: para o mes %d, o dia deve estar entre 1 e 30\n", data.mes);
            return false;
        }
    }
    printf("Data invalida: o mes deve estar entre 1 e 12\n");
    return false;
}

int main()
{
    int input;
    Data data;

    do
    {
        printf("Escreva uma data (DDMMAAAA) ou -1 para encerrar: ");
        scanf("%d", &input);
        
        if (input != -1)
        {
            data.ano = input % 10000;
            data.mes = (input / 10000) % 100;
            data.dia = input / 1000000;

            if(is_data_valida(data)) {
              print_data(data);
              printf(" | Data valida!\n");
            }
        }
    } while (input != -1);
    return 0;
}
