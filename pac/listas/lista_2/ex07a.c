#include <stdio.h>

float calculaVolumeCaixa (float a, float b, float c) {
    return a * b * c;
}
int main() {
    float a, b, c;
    printf("Insira os lados de uma caixa: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Volume = %.2f", calculaVolumeCaixa(a,b,c));
    return 0;
}