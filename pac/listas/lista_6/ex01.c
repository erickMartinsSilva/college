#include <stdio.h>

int leValidaTipo() {
    int t;
    printf("Insira o tipo do produto: \n");
    printf("1. Fruta\n");
    printf("2. Legume\n");
    printf("3. Verdura\n");
    do {
        scanf("%d", &t);
        if (t > 3 || t < 1) {
            printf("Opcao invalida! Tente novamente: ");
        }
    } while (t > 3 || t < 1);
    return t;
}
void processaProdutos (int qtdp, int *fruta, int *legume, int *verdura) {
    *fruta = 0, *legume = 0, *verdura = 0;
    int cod;
    for (int i = 1; i <= qtdp; i++) {
        printf("Insira o codigo do produto %d: ", i);
        scanf("%d", &cod);
        int t = leValidaTipo();
        if (t == 1) {
            (*fruta)++;
        }
        if (t == 2) {
            (*legume)++;
        }
        if (t == 3) {
            (*verdura)++;
        }
    }
}
int main() {
    int qtdp, fruta, legume, verdura;
    printf("Insira a quantidade de produtos comercializados: ");
    scanf("%d", &qtdp);
    processaProdutos(qtdp, &fruta, &legume, &verdura);
    printf("Qtd frutas: %d\n", fruta);
    printf("Qtd legumes: %d\n", legume);
    printf("Qtd verduras: %d\n", verdura);
    return 0;
}

