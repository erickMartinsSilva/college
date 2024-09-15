#include <stdio.h>
#include <math.h>

float areaCorporalMosteller(float h, float p) {
    float a = sqrt(p*h)/60;
    return a;
}
float aumentouDiminuiuOuManteve(float h1, float p1, float h2, float p2) {
    if (areaCorporalMosteller(h1,p1) < areaCorporalMosteller(h2,p2)) {
        printf("Aumentou a area corporal");
    }
    else if (areaCorporalMosteller(h1,p1) > areaCorporalMosteller(h2,p2)) {
        printf("Diminuiu a area corporal");
    }
    else if (areaCorporalMosteller(h1,p1) == areaCorporalMosteller(h2,p2)) {
        printf("Manteve area inalterada");
    }
    return 0;
}
int main() {
    float h1, p1, h2, p2;
    printf("CALCULADORA DE AREA CORPORAL COM BASE NA FORMULA DE MOSTELLER\n");
    printf("Insira sua altura e peso no inicio do ano: ");
    scanf("%f %f", &h1, &p1);
    printf("Insira sua altura e peso no fim do ano: ");
    scanf("%f %f", &h2, &p2);
    printf("Area corporal no inicio do ano = %.3f m^2\n", areaCorporalMosteller(h1,p1));
    printf("Area corporal no fim do ano = %.3f m^2\n", areaCorporalMosteller(h2,p2));
    int a = aumentouDiminuiuOuManteve(h1,p1,h2,p2);
    return 0;
}