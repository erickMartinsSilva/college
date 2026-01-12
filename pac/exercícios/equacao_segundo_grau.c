// equacao_segundo_grau.c: Resolve equações do segundo grau pela fórmula de Bhaskara
#include <stdio.h>
#include <math.h>

int main() {
    // a, b, c -> coeficientes da equação
    float a, b, c, delta;

    printf("Digite valores para A, B e C: ");
    scanf("%f %f %f", &a, &b, &c); 

    delta = b*b - 4*a*c;
    if (delta > 0) {
        // delta positivo -> duas raízes reais
        float raiz1, raiz2;
        raiz1 = (-b + sqrt(delta)) / (2*a);
        raiz2 = (-b - sqrt(delta)) / (2*a);
        printf("A equacao possui 2 raizes reais, sendo elas %f e %f", raiz1, raiz2);
    }
    if (delta == 0) {
        // delta zero -> uma raiz real
        float raiz;
        raiz = -b/(2*a);
        printf("A equacao possui 1 raiz real, sendo ela %f", raiz);
    }
    if (delta < 0) {
        printf("A equacao nao possui raizes reais");
    }
    return 0;
}
