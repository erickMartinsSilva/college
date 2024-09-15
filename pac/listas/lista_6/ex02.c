#include <stdio.h>

void processaTipo(char tipo, int *nacional, int *importado) {
    if (tipo == 'N') {
        printf("Produto nacional\n");
        (*nacional)++;
    }
    if (tipo == 'I') {
        printf("Produto importado\n");
        (*importado)++;
    }
}
int main() {
    int qtdp, cod, qtde, nacional = 0, importado = 0;
    float pu;
    char tipo;
    printf("Insira a quantidade de produtos a serem processados: ");
    scanf("%d", &qtdp);
    for (int i = 1; i <= qtdp; i++) {
        printf("===== Produto %d =====\n", i);
        printf("Insira o codigo: ");
        scanf("%d", &cod);
        printf("Insira o tipo (N -> Nacional, I -> Importado): ");
        scanf(" %c", &tipo);
        printf("Insira a quantidade em estoque: ");
        scanf("%d", &qtde);
        printf("Insira o preco unitario: R$");
        scanf("%f", &pu);
        printf("=====================\n");
        printf("Codigo do produto: %d\n", cod);
        processaTipo(tipo, &nacional, &importado);
        printf("Valor em estoque: R$%.2f\n", qtde * pu);
        printf("=====================\n");
    }
    printf("Numero de produtos nacionais diferentes processados: %d\n", nacional);
    printf("Numero de produtos importados diferentes processados: %d\n", importado);
    printf("=====================\n");
    return 0;
}