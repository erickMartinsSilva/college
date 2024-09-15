#include <stdio.h>

void umDepartamento(int qtdf, float *maior, int *qtdm) {
    int mat;
    float sal;
    for (int i = 1; i <= qtdf; i++) {
        printf("====== Funcionario %d ======\n", i);
        printf("Insira a matricula: ");
        scanf("%d", &mat);
        printf("Insira o salario: R$");
        scanf("%f", &sal);
        if (i == 1 || *maior < sal) {
            *maior = sal;
            *qtdm = 1;
        }
        else if (*maior == sal) {
            (*qtdm)++;
        }
    }
}

int main() {
    int cod, qtdf, qtdm;
    float maior;
    do {
        printf("Insira o codigo do departamento: ");
        scanf("%d", &cod);
        if (cod == 0) {
            return 0;
        }
        printf("Insira a quantidade de funcionarios do departamento: ");
        scanf("%d", &qtdf);
        umDepartamento(qtdf, &maior, &qtdm);
        printf("===========================\n");
        printf("Maior salario do departamento: R$%.2f\n", maior);
        printf("Numero de funcionarios beneficiados por esse salario: %d\n", qtdm);
        printf("===========================\n");
    } while (cod != 0);
}