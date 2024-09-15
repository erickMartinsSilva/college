#include <stdio.h>

float salarioBase (float vh, float qtdh) {
    float sb = vh * qtdh;
    return sb;
}
float descontoINSS (float sb) {
    float inss = (sb * 0.11);
    if (inss > 450.27) {
        inss = 450.27;
    }
    return inss;
}
float descontoIRPF (float sb) {
    float irpf;
    if (sb < 1800.00) {
        irpf = 0;
    }
    else if (sb > 1800.00 && sb <= 2900.00) {
        irpf = sb * 0.15;
    }
    else if (sb > 2900.00) {
        irpf = sb * 0.275;
    }
    return irpf;
}
int main() {
    int mat;
    float vh, qtdh, sb, inss, irpf, sl;
    printf("CALCULADORA DE PAGAMENTO DO FUNCIONARIO\n");
    printf("Insira a matricula do funcionario: ");
    scanf("%d", &mat);
    printf("Insira o valor da hora de trabalho: ");
    scanf("%f", &vh);
    printf("Insira a quantidade de horas trabalhadas: ");
    scanf("%f", &qtdh);
    sb = salarioBase(vh, qtdh);
    inss = descontoINSS(sb);
    irpf = descontoIRPF(sb);
    sl = (sb - inss) - irpf;
    printf("-----------------------------------------\n");
    printf("Matricula: %d\n", mat);
    printf("Salario base: R$%.2f\n", sb);
    printf("Desconto do INSS: R$%.2f\n", inss);
    printf("Desconto do imposto de renda: R$%.2f\n", irpf);
    printf("Salario liquido: R$%.2f", sl);
    return 0;
}