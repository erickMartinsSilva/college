#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ferramenta.h"

int main(int argc, char** argv) {
    FILE *a;

    if(argc != 5) {
        fprintf(stderr, "Erro: Poucos argumentos na chamada do programa (USO: %s [NUMERO] [NOME] [QTD] [CUSTO])", argv[0]);
        return 1;
    }

    a = fopen("ferramentas.dat", "r+b");

    Ferramenta buffer;
    Ferramenta registro = {argv[2], atoi(argv[3]), atof(argv[4])};
    long numeroRegistro = atoi(argv[1]);

    fseek(a, numeroRegistro, SEEK_SET);
    fread(&buffer, sizeof(Ferramenta), 1, a);
    if(strcmp(buffer.nome, "") != 0) {
        fprintf(stderr, "Erro: Posição de registro ocupada");
        return 1;
    } else {
        fseek(a, -sizeof(Ferramenta), SEEK_CUR);
        fwrite(&registro, sizeof(Ferramenta), 1, a);
    }

    fclose(a);
    return 0;
}