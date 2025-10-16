#include <stdio.h>
#include <string.h>
#include "endereco.h"

int main(int argc, char** argv) {
    FILE *f1, *f2;
    EnderecoIndice buffer;
    Endereco buffer2;
    int cmp, achou = 0;
    long inicio = 0, fim, meio;

    if(argc == 1) {
        printf("USO: %s [CEP]\n", argv[0]);
        return 1;
    }

    f1 = fopen("indice_ceps.dat", "rb");
    if(!f1) {
        fprintf(stderr, "ERRO: Arquivo cep_indice.dat inexistente\n");
        return 1;
    }

    f2 = fopen("cep.dat", "rb");
    if(!f2) {
        fprintf(stderr, "ERRO: Arquivo cep.dat inexistente\n");
        return 1;
    }

    fseek(f1, 0, SEEK_END);
    fim = (ftell(f1) / sizeof(EnderecoIndice))-1;

    while(inicio <= fim) {
        meio = (inicio+fim)/2;
        fseek(f1, meio * sizeof(EnderecoIndice), SEEK_SET);
        
        fread(&buffer, sizeof(EnderecoIndice), 1, f1);
        cmp = strncmp(argv[1],buffer.cep,8);
        if(cmp > 0) {
            inicio = meio + 1;
        }
        else if(cmp < 0) {
            fim = meio - 1;
        } else {
            achou = 1;
            break;
        }
    }

    if(achou) {
        fseek(f2, buffer.pos * sizeof(Endereco), SEEK_SET);
        fread(&buffer2, sizeof(Endereco), 1, f2);
        printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n\n",
            buffer2.logradouro,buffer2.bairro,buffer2.cidade,buffer2.uf,buffer2.sigla,buffer2.cep
        );
    } else {
        printf("CEP não encontrado\n");
    }

    fclose(f1);
    fclose(f2);
    return 0;
}