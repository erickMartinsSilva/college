#include <stdio.h>

int leValidaClassificacao() {
    int c;
    do {
        scanf("%d", &c);
        if (c > 4 || c < 1) {
            printf("Opcao invalida! Tente novamente: ");
        }
    } while (c > 4 || c < 1);
    return c;
}
void classe(int c, int *qtdmin, int *qtdmax) {
    if (c == 1) {
        *qtdmin = 100;
        *qtdmax = 120;
    }
    if (c == 2) {
        *qtdmin = 150;
        *qtdmax = 180;
    }
    if (c == 3) {
        *qtdmin = 200;
        *qtdmax = 250;
    }
    if (c == 4) {
        *qtdmin = 250;
        *qtdmax = 300;
    }
}
int main() {
    int cod, qtdmin, qtdmax;
    printf("===== PROCESSA PECAS DE AUTOMOVEL =====\n");
    for (int i = 1; i <= 4; i++) {
        printf("Insira o codigo do produto: ");
        scanf("%d", &cod);
        printf("Insira sua classificacao: ");
        int c = leValidaClassificacao();
        classe(c, &qtdmin, &qtdmax);
        printf("===================================\n");
        printf("Codigo do produto: %d\n", cod);
        printf("Qtd minima em estoque: %d\n", qtdmin);
        printf("Qtd maxima em estoque: %d\n", qtdmax);
        printf("===================================\n");
    }
    return 0;
}