// copy.c: cria uma cópia do arquivo especificado nos argumentos do comando
// uso: ./copy [ORIGEM] [DESTINO]

#include <stdio.h>

// argc: número de argumentos passados para o programa contando com o próprio programa
// argv: array de strings contendo cada argumento passado para o programa contando com o próprio programa (argv[0])
int main(int argc, char** argv) {
    FILE *entrada, *saida; // FILE: estrutura utilizada para representar arquivos em programas em C
    int c;

    if(argc != 3) {
        fprintf(stderr, "Erro. Uso do comando: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO]", argv[0]);
        return 1;
    }

    // fopen: função utilizada para abrir um arquivo
    // argumentos: nome do arquivo, modo de abertura (rb = leitura binária)
    entrada = fopen(argv[1], "rb");
    if(!entrada) {
        // fprintf: grava texto em um arquivo de stream.
        // nesse caso, gravando uma mensagem de erro para a saída de erro padrão (stderr)
        fprintf(stderr, "Não foi possível abrir o arquivo para leitura.");
        return 1;
    }

    // wb = escrita binária, criando o arquivo caso ele não exista. se ele existir, será sobrescrito
    saida = fopen(argv[2], "wb");
    if(!saida) {
        fprintf(stderr, "Não foi possível abrir o arquivo para escrita.");
        return 1;
    }

    // fgetc: obtém um caractere de um arquivo e armazena-o numa variável (nesse caso, c)
    // argumentos: ponteiro para estrutura FILE
    c = fgetc(entrada);
    while(c != EOF) {
        // fputc: insere um caractere num arquivo
        // argumentos: caractere, ponteiro para estrutura FILE
        fputc(c, saida);
        c = fgetc(entrada);
    }

    // fclose: fecha um arquivo
    // argumentos: ponteiro para estrutura FILE
    fclose(entrada);
    fclose(saida);
    return 0;
}