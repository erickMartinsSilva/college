#include <stdio.h>
#include <string.h>
#include "ferramenta.h"

int main() {
    FILE *a;
    Ferramenta buffer;
    int somatorioFerramentasTotal = 0;
    int somatorioFerramentasDistintas = 0;

    a = fopen("ferramentas.dat", "rb");

    fread(&buffer, sizeof(Ferramenta), 1, a);
    while(!feof(a)) {
        if(strcmp(buffer.nome, "") != 0) {
            printf("Registro: %ld | Nome: %s | Qtd: %d | Custo: R$%.2f\n",
            ftell(a) / sizeof(Ferramenta), buffer.nome, buffer.qtd, buffer.custo
        );

            somatorioFerramentasTotal += buffer.qtd;
            somatorioFerramentasDistintas++;
        }

        fread(&buffer, sizeof(Ferramenta), 1, a);
    }

    printf("Quantidade de ferramentas distintas: %d", somatorioFerramentasDistintas);
    printf("Quantidade total de ferramentas: %d", somatorioFerramentasTotal);

    fclose(a);
    return 0;
}