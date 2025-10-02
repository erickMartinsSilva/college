#include <stdio.h>

int semanaseDias(int dia) {
    if (dia / 7 == 0 && dia != 1) {
        printf("%d dias", dia);
    }
    else if (dia == 1) {
        printf("1 dia");
    }
    else if (dia % 7 == 0 && dia / 7 != 1) {
        printf("%d semanas", dia / 7);
    }
    else if (dia / 7 == 1) {
        printf("1 semana");
    }
    else {
        printf("%d semanas e %d dias", dia / 7, dia % 7);
    }
    return 0;
}
int main() {
    int dia;
    printf("Insira o numero de dias de determinado evento: ");
    scanf("%d", &dia);
    int s = semanaseDias(dia);
    return 0;
}