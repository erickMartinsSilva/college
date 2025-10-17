#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "endereco.h"

int compara(const void *i1, const void *i2) {
    return strncmp(((EnderecoIndice*)i1)->cep, ((EnderecoIndice*)i2)->cep, 8);
}

int main() {
    FILE *f, *saida;
    Endereco buffer; 
    EnderecoIndice* indices;
    long qtdEnderecos, currentPos;

    // cria índice
    f = fopen("cep.dat", "rb");
    if(!f) {
        fprintf(stderr, "ERRO: Arquivo cep.dat inexistente\n");
    }
    saida = fopen("indice_ceps.dat", "w+b");

    fseek(f, 0, SEEK_END);
    qtdEnderecos = ftell(f) / sizeof(Endereco);
    rewind(f);

    indices = (EnderecoIndice*) malloc(qtdEnderecos * sizeof(EnderecoIndice));

    printf("Lendo endereços de cep.dat e criando registros...\n");
    long i = 0;
    fread(&buffer, sizeof(Endereco), 1, f);
    while(!feof(f) && i < qtdEnderecos) {
        strcpy(indices[i].cep, buffer.cep);
        indices[i].pos = i;
        fread(&buffer, sizeof(Endereco), 1, f);
        i++;
    }
    qsort(indices, qtdEnderecos, sizeof(EnderecoIndice), compara);

    fwrite(indices, sizeof(EnderecoIndice), qtdEnderecos, saida);
    free(indices);

    printf("Finalizado!\n");
    fclose(saida);
    return 0;
}