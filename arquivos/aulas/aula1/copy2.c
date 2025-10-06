// copy2.c: cria uma cópia do arquivo especificado nos argumentos do comando
// uso: ./copy2 [ORIGEM] [DESTINO]

#include <stdio.h>

#define READ_SIZE 8192

int main(int argc, char** argv) {
    FILE *entrada, *saida;
    char buffer[READ_SIZE];
    int qtd;

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

    // fread: lê um bloco de tamanho determinado de um arquivo e armazena em uma variável
    // argumentos: variável que armazenará o bloco (buffer), tamanho do bloco, qtd de blocos, ponteiro para FILE
    qtd = fread(buffer, sizeof(char), READ_SIZE, entrada);
    // processo se repete até o fread não conseguir obter mais blocos do arquivo
    while(qtd > 0) {
        // fwrite: escreve o conteúdo de uma variável num arquivo
        // argumentos: variável que armazena o bloco (buffer), tamanho do bloco, qtd de blocos, ponteiro para FILE
        fwrite(buffer, sizeof(char), qtd, saida);
        qtd = fread(buffer, sizeof(char), READ_SIZE, entrada);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}