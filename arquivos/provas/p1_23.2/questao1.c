#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {} S;

// b)
void particiona(FILE* entrada, char* nomeSaida, int deslocamento, int qt) {
    FILE* saida;
    S buffer;
    saida = fopen(nomeSaida, "wb");

    fseek(entrada, deslocamento, SEEK_SET);
    while(qt > 0 && fread(&buffer, sizeof(S), 1, entrada) != 0) {
        fwrite(&buffer, sizeof(S), 1, saida);
        qt--;
    }

    fclose(saida);
}

// a)
int main(int argc, char** argv) { // argv[1]: nome do arquivo, argv[2]: inteiro N
    FILE *f;
    int n; 
    
    f = fopen(argv[1],"rb");
    if(!f) {
        fprintf(stderr, "ERRO: Arquivo não existente");
        return 1;
    }

    n = atoi(argv[2]);
    if(!n) {
        fprintf(stderr, "ERRO: Argumento incorreto");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    // Tamanho do arquivo em bytes:
    long int tamanhoBytes = ftell(f);
    printf("Tamanho do arquivo %s em bytes: %ld", argv[1], tamanhoBytes);
    // Qtd. registros:
    long int qtdRegistros = tamanhoBytes / sizeof(S);
    printf("Quantidade de registros: %ld", qtdRegistros);
    // Qtd. registros por partição:
    long int registrosPorParticao = qtdRegistros / n;
    printf("Quantidade de registros / partição: %ld", registrosPorParticao);
    long int resto = qtdRegistros % n;

    if(registrosPorParticao < 1 || registrosPorParticao > MAX) {
        fprintf(stderr, "ERRO: Entrada inválida");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        long int desloc;
        desloc = i * registrosPorParticao * sizeof(S);

        printf("Deslocamento para o primeiro registro da partição %d: %ld", i+1, desloc);
    }

    return 0;
}