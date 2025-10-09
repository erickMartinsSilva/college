#include <stdio.h>

typedef struct {} Registro;

int chave(Registro* r);
void leRegistro(FILE* F, Registro* r);

int main() {
    FILE* f;
    long int inicio = 0, fim, meio, inicioReg, fimReg;
    Registro buffer;
    char c;
    int chaveProcurada, achou = 0;

    f = fopen("arquivo.csv", "rb");
    if(!f) {
        fprintf(stderr, "ERRO: Arquivo inexistente");
    }

    fseek(f, 0, SEEK_END);
    fim = ftell(f);

    while(inicio <= fim) {
        meio = (inicio+fim)/2;

        fseek(f, meio, SEEK_SET);
        c = fgetc(f);
        while(c != '\n') {
            c = fgetc(f);
        }

        inicioReg = ftell(f);
        leRegistro(f, &buffer);
        fimReg = meio;

        if(chaveProcurada > chave(&buffer)) {
            inicioReg = meio + 1;
        } if(chaveProcurada < chave(&buffer)) {
            fimReg = meio - 1;
        } else {
            achou = 1;
            break;
        }

        inicio = inicioReg;
        fim = fimReg;
    }

    if(!achou) {
        printf("Registro não encontrado");
    } else {
        printf("Registro encontrado na posição %ld", meio);
    }

    fclose(f);
    return 0;
}