#include <stdio.h>
#include <math.h>

float calculaVolumeCilindro (float r, float h) {
    return 3.14 * h * pow(r,2);
}
int main() {
    float r, h;
    printf("Insira os valores de raio e altura do cilindro: ");
    scanf("%f %f", &r, &h);
    printf("Volume = %.2f", calculaVolumeCilindro(r,h));
    return 0;
}