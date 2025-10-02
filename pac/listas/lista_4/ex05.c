#include <stdio.h>

float somaSalariosDep(float cod, float qtdf) {
    int mat;
    float sal, salt = 0;
    for (int k = 1; k <= qtdf; k++) {
        printf("Insira a matricula do %do funcionario: ", k);
        scanf("%d", &mat);
        printf("Insira o salario do %do funcionario: R$", k);
        scanf("%f", &sal);
        salt += sal;
    }
    printf("Codigo do departamento: %.0f\n", cod);
    printf("Soma dos salarios do departamento: R$%.2f\n", salt);
    return salt;
}
int main() {
    float cod, qtdf, s, aux = 0;
    for (int i = 1; i <= 30; i++) {
        printf("Insira o codigo do departamento: ");
        scanf("%f", &cod);
        printf("Insira o numero de funcionarios do departamento: ");
        scanf("%f", &qtdf);
        s = somaSalariosDep(cod,qtdf);
        aux += s;
    }
    printf("Soma do salario de todos os departamentos: R$%.2f", aux);
    return 0;
}