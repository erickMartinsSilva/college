// cria uma cópia do arquivo especificado nos argumentos do comando
// uso: ./copy [ORIGEM] [DESTINO]

#include <stdio.h>

int main(int argc, char** argv) {
    FILE *entrada, *saida;
    int c;

    if(argc != 3) {
        fprintf(stderr, "Erro. Uso do comando: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO]", argv[0]);
        return 1;
    }

    entrada = fopen(argv[1], "rb");
    if(!entrada) {
        fprintf(stderr, "Não foi possível abrir o arquivo para leitura.");
        return 1;
    }

    saida = fopen(argv[2], "wb");
    if(!saida) {
        fprintf(stderr, "Não foi possível abrir o arquivo para escrita.");
        return 1;
    }

    // fgetc com fputc: copia os conteúdos do arquivo de entrada e escreve no de saída, byte por byte
    c = fgetc(entrada);
    while(c != EOF) {
        fputc(c, saida);
        c = fgetc(entrada);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}