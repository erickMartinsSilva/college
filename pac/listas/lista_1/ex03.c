#include <stdio.h>

float aumento20porc(float pu) {
    float npu = pu * 1.2;
    return npu;
}
int main() {
    float pu, npu;
    printf("Insira o preco unitario de um produto: ");
    scanf("%f", &pu);
    npu = aumento20porc(pu);
    printf("Novo preco unitario (c/ aum. de 20 por cento) = %.2f", npu);
    return 0;
}