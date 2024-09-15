#include <stdio.h>

int menu() {
    int op;
    printf("\n1. Horista\n");
    printf("2. Contratado\n");
    printf("3. Prestador de servico\n");
    printf("Insira uma opcao: ");
    do {
        scanf("%d", &op);
        if (op > 3 || op < 1) {
            printf("Opcao invalida! Tente novamente: ");
        }
    } while (op > 3 || op < 1);
    return op;
}
float salarioHorista() {
    float vh, qtdh, sh;
    printf("Opcao escolhida: Horista\n");
    printf("Insira o valor da hora de trabalho: R$");
    scanf("%f", &vh);
    printf("Insira a quantidade de horas trabalhadas: ");
    scanf("%f", &qtdh);
    sh = vh * qtdh;
    return sh;
}
float salarioContratado() {
    float sc;
    printf("Opcao escolhida: Contratado\n");
    printf("Insira o salario do contratado: R$");
    scanf("%f", &sc);
    return sc;
}
float salarioPrestador() {
    int qtds;
    float vs;
    float sp = 0;
    printf("Opcao escolhida: Prestador de servicos\n");
    printf("Insira a quantidade de servicos prestados: ");
    scanf("%d", &qtds);
    for (int i = 1; i <= qtds; i++) {
        printf("Insira o valor do %do servico: R$", i);
        scanf("%f", &vs);
        sp += vs;
    }
    return sp;
}
int main() {
    float sal;
    printf("----- CALCULA SALARIO DOS FUNCIONARIOS -----");
    for (int k = 1; k <= 50; k++) {
        int m = menu();
        if (m == 1) {
            sal = salarioHorista();
        }
        if (m == 2) {
            sal = salarioContratado();
        }
        if (m == 3) {
            sal = salarioPrestador();
        }
        printf("Salario do funcionario %d = R$%.2f", k, sal);
    }
    return 0;
}