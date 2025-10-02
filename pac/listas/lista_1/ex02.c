#include <stdio.h>

float mediaAluno(float n1, float n2) {
    float media = (n1 + n2) / 2;
    return media;
}
int main() {
    float n1, n2, media;
    printf("Insira as duas notas de um aluno: ");
    scanf("%f %f", &n1, &n2);
    media = mediaAluno(n1,n2);
    printf("Media = %.2f", media);
    return 0;
}