// NOME: Erick Martins Silva
// DATA: 09/03/2024
// DESCRICAO: O programa, com base na média das notas de duas provas, verifica se o aluno está aprovado, de prova final ou reprovado

#include <stdio.h>

int main()
{
    float p1, p2, pf, media;
    printf("Entre com as notas da P1 e P2 do aluno: ");
    scanf("%f %f", &p1, &p2);
    media = (p1 + p2) / 2;
    printf("Media: %.2f\n", media);
    if (media >= 7)
    {
        printf("Situacao: Aprovado");
    }
    else if (media < 7 && media >= 5)
    {
        printf("Situacao: Prova final\n");
        printf("Nota da prova final: ");
        scanf("%f", &pf);
        if (pf >= 5)
        {
            printf("Situacao final: Aprovado");
        }
        else
        {
            printf("Situacao final: Reprovado");
        }
    }
    else
    {
        printf("Situacao: Reprovado");
    }
    return 0;
}