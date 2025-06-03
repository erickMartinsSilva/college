#include <stdio.h>

int horaParaMinuto(int h, int min) {
    return (h * 60) + min;
}
int main() {
    int horario, h, min;
    printf("Insira um horario: ");
    scanf("%d", &horario);
    h = horario / 100;
    min = horario % 100;
    printf("%dh%dmin convertido em minutos = %d min", h, min, horaParaMinuto(h,min));
    return 0;
}