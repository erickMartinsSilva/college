#include <stdio.h>

int calculaDifMin(int hp, int minp, int he, int mine) {
    return ((hp * 60) + minp) - ((he * 60) + mine);
}

int main() {
    int horp, hore, hp, minp, he, mine;
    printf("Insira o horario previsto de chegada de um voo: ");
    scanf("%d", &horp);
    printf("Insira o horario efetivo de chegada de um voo: ");
    scanf("%d", &hore);
    hp = horp / 100;
    minp = horp % 100;
    he = hore / 100;
    mine = hore % 100;
    printf("Diferenca em minutos entre os horarios: %d min", calculaDifMin(hp,minp,he,mine));
    return 0;
}