// situacao_aluno.c: calcula a média final de um aluno considerando média mínima 7 para aprovação
#include <stdio.h>

int main()
{
    float nota_p1, nota_p2, nota_pf, media;
    printf("Entre com as notas da P1 e P2 do aluno: ");
    scanf("%f %f", &nota_p1, &nota_p2);
    media = (nota_p1 + nota_p2) / 2;
    printf("Media: %.2f\n", media);
    if (media >= 7)
    {
        printf("Situacao: Aprovado");
    }
    else if (media < 7 && media >= 5)
    {
        printf("Situacao: Prova final\n");
        printf("Insira a nota da prova final do aluno: ");
        scanf("%f", &nota_pf);
        if (nota_pf >= 5)
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
