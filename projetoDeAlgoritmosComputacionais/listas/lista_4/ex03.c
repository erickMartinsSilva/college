#include <stdio.h>

int valorPostos() {
    int cod;
    float va;
    float vt = 0;
    float vm = 0;
    for (int i = 1; i <= 20; i++) {
        printf("Insira o codigo do %do posto: ", i);
        scanf("%d", &cod);
        printf("Insira o valor arrecadado pelo %do posto: R$", i);
        scanf("%f", &va);
        vt += va;
        if (vm < va) {
            vm = va;
        }
    }
    printf("Maior valor arrecadado: R$%.2f\n", vm);
    printf("Valor total arrecadado pelos 20 postos: R$%.2f\n", vt);
    return 0;
}
int main() {
    printf("PROCESSAMENTO DOS POSTOS\n");
    int v = valorPostos();
    return 0;
}