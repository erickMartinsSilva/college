#include <stdio.h>

float calculaValor(float vl, float qtdl) {
    float valor = vl * qtdl;
    return valor;
}
int main() {
    float vl, qtdl, valor;
    printf("Insira o valor do litro de um combustivel: R$");
    scanf("%f", &vl);
    printf("Insira a quantidade de litros abastecida por um cliente: ");
    scanf("%f", &qtdl);
    valor = calculaValor(vl, qtdl);
    printf("Valor a ser pago: R$%.2f", valor);
    return 0;
}