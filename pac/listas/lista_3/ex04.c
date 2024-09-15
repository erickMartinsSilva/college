#include <stdio.h>

int validaMatricula(int mat) {
    int ano, sem, num;
    if (ano >= 10 && ano <= 90) {
        return 1;
    }
    else {
        return 0;
    }
    if (sem == 1 || sem == 2) {
        return 1;
    }
    else {
        return 0;
    }
    if (num >= 1 && num <= 90) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    int mat, ano, sem, num;
    printf("VALIDADOR DE MATRICULAS\n");
    printf("Insira uma matricula (AASNN): ");
    scanf("%d", &mat);
    ano = mat / 1000;
    sem = (mat % 1000) / 100;
    num = mat % 100;
    if (validaMatricula(mat) == 1) {
        printf("Matricula valida!");
    }
    else if (validaMatricula(mat) == 0) {
        printf("Matricula invalida");
    }
    return 0;
}