#include <stdio.h>

int estoqueMaisQueMil(int qtda) {
    int cod, qtde, ctd = 0;
    for (int i = 1; i <= qtda; i++) {
        printf("Insira o codigo do %do modelo: ", i);
        scanf("%d", &cod);
        printf("Insira a quantidade em estoque do %do modelo: ", i);
        scanf("%d", &qtde);
        if (qtde > 1000) {
            ctd++;
        }
    }
    printf("Quantidade de carros diferentes com mais de 1000 un. em estoque: %d", ctd);
    return 0;
}
int main() {
    int qtda;
    printf("Insira a quantidade de automoveis diferentes produzidos por uma empresa: ");
    scanf("%d", &qtda);
    int e = estoqueMaisQueMil(qtda);
    return 0;
}