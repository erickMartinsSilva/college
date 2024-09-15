#include <stdio.h>

int situacaoEleitoral(int idade) {
    if (idade < 16) {
        printf("Nao eleitor");
    }
    else if ((idade >= 16 && idade < 18) || idade > 70) {
        printf("Eleitor facultativo");
    }
    else if (idade >= 18 && idade <= 70) {
        printf("Eleitor");
    }
    return 0;
}
int main() {
    int idade;
    printf("SITUACAO ELEITORAL\n");
    printf("Insira sua idade: ");
    scanf("%d", &idade);
    int s = situacaoEleitoral(idade);
    return 0;
}