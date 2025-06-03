#include <stdio.h>

float calcula_media(float a, float b) {
    return (a + b) / 2;
}
int main() {
    int mat;
    float p1, p2, t1, t2, mp, mtr, mt;
    printf("Insira a matricula do aluno: ");
    scanf("%d", &mat);
    printf("Insira as notas da primeira e segunda prova: ");
    scanf("%f %f", &p1, &p2);
    printf("Insira as notas do primeiro e segundo trabalho: ");
    scanf("%f %f", &t1, &t2);
    mp = calcula_media(p1,p2);
    mtr = calcula_media(t1,t2);
    mt = mp + mtr;
    printf("<-------------------------------->\n");
    printf("Matricula do aluno: %d\n", mat);
    printf("Media das provas: %.2f\n", mp);
    printf("Media dos trabalhos: %.2f\n", mtr);
    printf("Media final: %.2f\n", mt);
    return 0;
}