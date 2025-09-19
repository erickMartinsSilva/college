#include <stdio.h>
#include "ferramenta.h"

void menu() {
    printf("=== INVENTÁRIO DE FERRAMENTAS ===");
    printf("\n1. Adicionar registro\n2. Remover registro\n3. Ver registro\n4. Ver todos os registros\n5. Sair\n");
}

void add_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("Insira o número do registro que você quer adicionar: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("Erro: Número de registro inválido\n\n");
    } else {
        rewind(hPtr);

        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);

        if(buffer.numero != 0) {
            printf("Erro: Registro já existe\n\n");
        } else {
            FerramentaData ferramenta = {num, "", 0, 0.0};

            printf("Insira informações da ferramenta (Nome Quantidade Custo): ");

            // FIXME: esse scanf dá um loop infinito na main
            scanf(" %[^\n] %d %d", ferramenta.nome, &ferramenta.qtd, &ferramenta.custo);

            fwrite(&ferramenta, sizeof(FerramentaData), 1, hPtr);

            printf("Escrita realizada com sucesso!\n\n");
        }
    }
}    

void remove_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("Insira o número do registro que você quer remover: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("Erro: Número de registro inválido\n\n");
    } else {
        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);

        if(buffer.numero != 0) {
            FerramentaData ferramentaVazia = {0, "", 0, 0.0};
            
            fwrite(&ferramentaVazia, sizeof(FerramentaData), 1, hPtr);

            printf("Registro removido com sucesso!\n\n");
        } else {
            printf("Erro: Registro já está vazio\n\n");
        }
    }
}

void print_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("Insira o número do registro que deseja visualizar: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("Erro: Número de registro inválido\n\n");
    } else {
        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);
        
        if(buffer.numero == 0) {
            printf("Registro vazio!\n\n");
        } else {
            printf("Registro %d\nNome: %s\nQuantidade: %d\nCusto: %.2f\n\n",
                num,
                buffer.nome,
                buffer.qtd,
                buffer.custo);
        }
    }
}

void print_all_entries(FILE *hPtr) {
    FerramentaData buffer;
    int i = 0;

    rewind(hPtr);
    
    fread(&buffer, sizeof(FerramentaData), 1, hPtr);
    while(i <= AMOUNT_ENTRYS) {
        if(buffer.numero != 0) {
            printf("Registro %d\nNome: %s\nQuantidade: %d\nCusto: %.2f\n",
                buffer.numero,
                buffer.nome,
                buffer.qtd,
                buffer.custo);
        }
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);
        i++;
    }
}

int main() {
    FILE *hPtr;
    FerramentaData buffer;

    hPtr = fopen("hardware.dat", "rb+");
    if(!hPtr) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
    } else {
        int op;
        do {
            menu();
            printf("Insira a opção desejada: ");
            scanf("%d", &op);

            switch(op) {
                case 1: add_entry(hPtr); break;
                case 2: remove_entry(hPtr); break;
                case 3: print_entry(hPtr); break;
                case 4: print_all_entries(hPtr); break;
                case 5: break;
                default: printf("Erro: Opção inválida\n\n");
            }
        } while(op != 5);
    }

    printf("Saindo...\n");
    fclose(hPtr);
    return 0;
}