#include <stdio.h>
#include <math.h>

float distanciaPontos (float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}
int main() {
    float x1, y1, x2, y2, x3, y3, d1, d2, d3, per;
    printf("Insira a primeira coordenada (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Insira a segunda coordenada (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Insira a terceira coordenada (x3 y3): ");
    scanf("%f %f", &x3, &y3);
    d1 = distanciaPontos(x1,y1,x2,y2);
    d2 = distanciaPontos(x2,y2,x3,y3);
    d3 = distanciaPontos(x3,y3,x1,y1);
    per = d1 + d2 + d3;
    printf("Perimetro do triangulo: %.2f", per);
    return 0;
}