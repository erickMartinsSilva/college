// letters: conta quantas linhas de texto um arquivo tem
#include <stdio.h>

int main(int argc, char** argv) {
    FILE *entrada;
    int counts[256] = {};
    char c;

    if(argc != 2) {
        fprintf(stderr, "Erro: Quantidade de argumentos insuficiente. Uso: letters [ARQUIVO]\n");
    }

    entrada = fopen(argv[1], "r");

    c = fgetc(entrada);
    while(c != EOF) {
        counts[c]++;
        c = fgetc(entrada);
    }
    fclose(entrada);
    
    for(int i = 65; i < 123; i++) {
        if(i == 91) {
            i += 6;
        }
        if(counts[i] != 0) {
            printf("%c = %d\n", i, counts[i]);
        }
    }

    return 0;
}
