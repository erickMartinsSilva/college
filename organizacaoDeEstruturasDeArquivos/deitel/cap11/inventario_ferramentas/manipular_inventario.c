#include <stdio.h>
#include "ferramenta.h"

void menu() {
    printf("\n=== INVENTÁRIO DE FERRAMENTAS ===\n\n");
    printf("1. Adicionar registro\n2. Remover registro\n3. Ver registro\n4. Ver registros preenchidos\n5. Remover todos os registros\n6. Sair\n\n");
}

void add_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("\nInsira o número do registro que você quer adicionar: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("Erro: Número de registro inválido\n\n");
    } else {
        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);

        if(buffer.numero != 0) {
            printf("\nErro: Registro já existe\n");
        } else {
            FerramentaData ferramenta = {num, "", 0, 0.0};

            printf("Insira o nome da ferramenta: ");
            scanf(" %[^\n]", ferramenta.nome);
            printf("Insira a quantidade da ferramenta: ");
            scanf("%d", &ferramenta.qtd);
            printf("Insira o custo da ferramenta: R$");
            scanf("%f", &ferramenta.custo);

            fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
            fwrite(&ferramenta, sizeof(FerramentaData), 1, hPtr);

            printf("\nEscrita realizada com sucesso!\n");
        }
    }
}    

void remove_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("\nInsira o número do registro que você quer remover: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("\nErro: Número de registro inválido\n");
    } else {
        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);

        if(buffer.numero == 0) {
            printf("\nErro: Registro vazio\n");
        } else {
            FerramentaData ferramentaVazia = {0, "", 0, 0.0};

            fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
            if(fwrite(&ferramentaVazia, sizeof(FerramentaData), 1, hPtr) == 1) {
                printf("\nRegistro removido com sucesso!\n");
            } else {
                printf("\nErro ao remover registro\n");
            }
        }
    }
}

void remove_all_entries(FILE *hPtr) {
    char escolha;
    printf("Tem certeza que deseja remover todos os registros? Essa ação não pode ser desfeita.\n(S/N): ");
    scanf(" %c", &escolha);

    if(escolha == 83 || escolha == 115) {
        FerramentaData ferramentaVazia = {0, "", 0, 0.0};

        rewind(hPtr);
        for(int i = 0; i < AMOUNT_ENTRYS; i++) {
            fwrite(&ferramentaVazia, sizeof(FerramentaData), 1, hPtr);
        }

        printf("\nRegistros removidos com sucesso!\n");
    } else if(escolha == 78 || escolha == 110) {
        printf("\nRetornando ao menu principal...\n");
    } else {
        printf("\nEscolha inválida\n");
    }
}

void print_entry(FILE *hPtr) {
    int num;
    FerramentaData buffer;

    printf("\nInsira o número do registro que deseja visualizar: ");
    scanf("%d", &num);

    if(num < 1 || num > AMOUNT_ENTRYS) {
        printf("\nErro: Número de registro inválido\n");
    } else {
        fseek(hPtr, (num-1) * sizeof(FerramentaData), SEEK_SET);
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);
        
        if(buffer.numero == 0) {
            printf("\nRegistro vazio!\n");
        } else {
            printf("\nRegistro %d\nNome: %s\nQuantidade: %d\nCusto: %.2f\n",
                buffer.numero,
                buffer.nome,
                buffer.qtd,
                buffer.custo);
        }
    }
}

void print_all_entries(FILE *hPtr) {
    FerramentaData buffer;
    
    rewind(hPtr);

    for(int i = 0; i < AMOUNT_ENTRYS; i++) {
        fread(&buffer, sizeof(FerramentaData), 1, hPtr);
        if(buffer.numero != 0) {
            if(i == 0) {
                printf("\nNúmero\tNome\t\t\tQtd\tCusto\n");
            }
            printf("%d\t%s\t\t%d\tR$%.2f\n",
                    buffer.numero,
                    buffer.nome,
                    buffer.qtd,
                    buffer.custo);
        }
    }
}

int main() {
    FILE *hPtr;
    FerramentaData buffer;
    int op;

    hPtr = fopen("hardware.dat", "rb+");
    if(!hPtr) {
        fprintf(stderr, "ERRO: Não foi possível abrir o arquivo de inventário. Se ele não existir, inicialize-o com inicializar_inventario.\n");
        return 1;
    }
    
    do {
        menu();
        printf("Insira a opção desejada: ");
        scanf("%d", &op);

        switch(op) {
            case 1: add_entry(hPtr); break;
            case 2: remove_entry(hPtr); break;
            case 3: print_entry(hPtr); break;
            case 4: print_all_entries(hPtr); break;
            case 5: remove_all_entries(hPtr); break;
            case 6: break;
            default: printf("Erro: Opção inválida\n\n");
        }
    } while(op != 6);

    printf("Saindo...\n");
    fclose(hPtr);
    return 0;
}