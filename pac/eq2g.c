// O programa resolve uma equação do segundo grau, com base em três números, por meio da fórmula de Bhaskara

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2, x; 
    printf("Digite valores para A, B e C: ");
    scanf("%f %f %f", &a, &b, &c); 
    delta = b*b - 4*a*c;
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("A equacao possui 2 raizes reais, sendo elas %f e %f", x1, x2);
    }
    if (delta == 0) {
        x = -b/(2*a);
        printf("A equacao possui 1 raiz real, sendo ela %f",x);
    }
    if (delta < 0) {
        printf("A equacao nao possui raizes reais");
    }
    return 0;
}
