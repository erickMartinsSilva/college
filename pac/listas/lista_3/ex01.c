#include <stdio.h>

float calculoIDH(float E, float L, float R) {
    float IDH;
    if (E >= L + R) {
        IDH = E * L * R / ((E + L + R)/3);
    }
    else {
        IDH = (E + L + R)/3;
    }
    return IDH;
}
int main() {
    float E, L, R, IDH;
    printf("----- CALCULO INDICE DE DESENVOLVIMENTO HUMANO -----\n");
    printf("Insira o valor da dimensao Educacao: ");
    scanf("%f", &E);
    printf("Insira o valor da dimensao Longevidade: ");
    scanf("%f", &L);
    printf("Insira o valor da dimensao Riqueza: ");
    scanf("%f", &R);
    IDH = calculoIDH(E,L,R);
    printf("IDH = %.2f", IDH);
    return 0;
}