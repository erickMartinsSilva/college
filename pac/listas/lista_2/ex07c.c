#include <stdio.h>
#include <math.h>

float calculaVolumeCaixa (float a, float b, float c) {
    return a * b * c;
}
float calculaVolumeCilindro (float r, float h) {
    return 3.14 * h * pow(r,2);
}
int main() {
    float a, b, c, r, h;
    printf("Insira os valores de lado de uma caixa: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Nessa caixa, ha um furo de formato cilindrico. Insira o raio e altura dele: ");
    scanf("%f %f", &r, &h);
    printf("Volume da caixa = %.2f", calculaVolumeCaixa(a,b,c) - calculaVolumeCilindro(r,h));
    return 0;
}