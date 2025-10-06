#include <stdio.h>

typedef struct {
    int matricula;
} Estrutura;

int main() {
    FILE *arq1, *arq2, *saida;
    Estrutura buffer1, buffer2;
    long int inicio = 0, fim, meio;

    arq1 = fopen("Arquivo1.dat", "rb");
    arq2 = fopen("Arquivo2.dat", "rb");
    saida = fopen("Resultado.dat", "wb");

    fseek(arq2, 0, SEEK_END);
    fim = ftell(arq2) / sizeof(Estrutura);

    meio = (inicio + fim)/2;

    fread(&buffer1, sizeof(Estrutura), 1, arq1);
    while(!feof(arq1)) {
        int achou = 0;

        fseek(arq2, (meio-1) * sizeof(Estrutura), SEEK_SET);
        fread(&buffer2, sizeof(Estrutura), 1, arq2);
        while(inicio <= fim) {
            if(buffer1.matricula < buffer2.matricula) {
                fim = meio - 1;
            }
            if(buffer1.matricula > buffer2.matricula) {
                inicio = meio + 1;
            }
            if(buffer1.matricula == buffer2.matricula) {
                achou = 1;
                break;
            }

            fseek(arq2, (meio-1) * sizeof(Estrutura), SEEK_SET);
            fread(&buffer2, sizeof(Estrutura), 1, arq2);
        }

        if(!achou) {
            fwrite(&buffer1, sizeof(Estrutura), 1, saida);
        }

        fread(&buffer1, sizeof(Estrutura), 1, arq1);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(saida);
    return 0;
}