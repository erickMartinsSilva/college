#include <stdio.h>

float pagamento_dinheiro(float val) {
    float vp;
    printf("Insira o valor pago: R$");
    scanf("%f", &vp);
    if (vp == val) {
        printf("Nao ha troco");
    }
    else {
        printf("Troco = R$%.2f", vp - val);
    }
    return 0;
}
int main() {
    float val;
    char met;
    int op;
    printf("CALCULADORA DE TROCO\n");
    printf("Insira o valor da despesa a ser paga: R$");
    scanf("%f", &val);
    printf("Insira a forma de pagamento: \n");
    printf("1. Credito\n");
    printf("2. Debito\n");
    printf("3. Dinheiro\n");
    scanf("%d", &op);
    printf("Valor a ser pago: R$%.2f\n", val);
    if (op == 1) {
        printf("Metodo de pagamento: Credito\n");
        printf("Nao ha troco");
    }
    else if (op == 2) {
        printf("Metodo de pagamento: Debito\n");
        printf("Nao ha troco");
    }
    else if (op == 3) {
        printf("Metodo de pagamento: Dinheiro\n");
        int p = pagamento_dinheiro(val);
    }
    return 0;
}