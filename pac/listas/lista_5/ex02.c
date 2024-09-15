#include <stdio.h>

int menu() {
    int op;
    printf("\n1. Quadrado\n");
    printf("2. Retangulo\n");
    printf("3. Triangulo\n");
    printf("4. Trapezio\n");
    printf("5. Fim\n");
    printf("Escolha uma opcao: ");
    do {
        scanf("%d", &op);
        if (op > 5 || op < 1) {
            printf("Opcao invalida! Tente novamente: ");
        }
    } while (op > 5 || op < 1);
    return op;
}
float quadrado() {
    float l;
    printf("Opcao escolhida: Quadrado\n");
    printf("Insira o valor do lado: ");
    scanf("%f", &l);
    return l*l;
}
float retangulo() {
    float b, h;
    printf("Opcao escolhida: Retangulo\n");
    printf("Insira, respectivamente, o valor da base e da altura: ");
    scanf("%f %f", &b, &h);
    return b * h;
}
float triangulo() {
    float b, h;
    printf("Opcao escolhida: Triangulo\n");
    printf("Insira, respectivamente, o valor da base e da altura: ");
    scanf("%f %f", &b, &h);
    return (b * h) / 2;
}
float trapezio() {
    float b_M, b_m, h;
    printf("Opcao escolhida: Trapezio\n");
    printf("Insira, respectivamente, o valor da base maior, da base menor e da altura: ");
    scanf("%f %f %f", &b_M, &b_m, &h);
    return (b_M + b_m) * h / 2;
}
int main() {
    float m, a;
    do {
        m = menu();
        if (m == 1) {
            a = quadrado();
        }
        else if (m == 2) {
            a = retangulo();
        }
        else if (m == 3) {
            a = triangulo();
        }
        else if (m == 4) {
            a = trapezio();
        }
        else {
            break;
        }
        printf("Area = %.2f", a);
    } while (m != 5);
}