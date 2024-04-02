// Nome: Erick Martins Silva
// Data: 22/02/24
// Instituição: CEFET/RJ
// Descrição: O programa abaixo resolve uma equação do segundo grau utilizando a fórmula de Bhaskara

#include <stdio.h> // biblioteca padrão do C com comandos de entrada e saída
#include <math.h> // biblioteca para comandos de operações matemáticas como potenciação e radiciação

int main() {
    float a, b, c, delta, x1, x2, x; // declaração de variáveis do tipo "real"
    printf("Digite valores para A, B e C: "); // printf faz a máquina escrever algo no terminal
    scanf("%f %f %f", &a, &b, &c); // scanf lê o que o usuário escrever
    delta = b*b - 4*a*c; // inserção de uma expressão matemática dentro da variável delta
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("A equacao possui 2 raizes reais, sendo elas %f e %f", x1, x2);
    }
    if (delta == 0) {
        x = -b/(2*a);
        printf("A equacao possui 1 raiz real, sendo ela %f",x);
    }
    if (delta < 0) {
        printf("A equacao nao possui raizes reais");
    }
    return 0;
}