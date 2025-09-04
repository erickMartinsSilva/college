// cria uma cópia do arquivo especificado nos argumentos do comando
// uso: ./copy2 [ORIGEM] [DESTINO]

#include <stdio.h>

#define SIZE 8192

int main(int argc, char** argv) {
    // declaração de estruturas de arquivos para armazenar os arquivos de entrada e saída e de um buffer de 8 bytes
    FILE *entrada, *saida;
    char buffer[SIZE];
    int qtd;

    if(argc != 3) {
        fprintf(stderr, "Erro. Uso do comando: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO]", argv[0]);
        return 1;
    }

    // abre o arquivo de entrada no modo leitura binária
    entrada = fopen(argv[1], "rb");
    if(!entrada) {
        fprintf(stderr, "Não foi possível abrir o arquivo para leitura.");
        return 1;
    }

    // abre o arquivo de saída no modo escrita binária
    saida = fopen(argv[2], "wb");
    if(!saida) {
        fprintf(stderr, "Não foi possível abrir o arquivo para escrita.");
        return 1;
    }

    // fread com fwrite: lê do arquivo de entrada e escreve no de saída em blocos de tamanho do buffer
    qtd = fread(buffer, sizeof(char), SIZE, entrada);
    while(qtd > 0) {
        fwrite(buffer, sizeof(char), qtd, saida);
        qtd = fread(buffer, sizeof(char), SIZE, entrada);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}