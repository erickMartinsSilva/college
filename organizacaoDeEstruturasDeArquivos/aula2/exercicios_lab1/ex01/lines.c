// lines: conta quantas linhas um arquivo de texto tem
#include <stdio.h>

int main(int argc, char** argv) {
    FILE *entrada;
    char c;
    int count = 1;

    if(argc != 2) {
        fprintf(stderr, "Erro: Quantidade inválida de argumentos.\nUso: lines [ARQUIVO]");
        return 1;
    }

    entrada = fopen(argv[1], "r");
    if(!entrada) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo para leitura. Verifique suas permissões.\n");
    }

    c = fgetc(entrada);
    while(c != EOF) {
        if(c == '\n') {
            count++;
        }
        c = fgetc(entrada);
    }

    fclose(entrada);
    printf("%d\n", count);
    return 0;
}