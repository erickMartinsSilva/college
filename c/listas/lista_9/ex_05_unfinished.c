#include <stdio.h>

typedef struct _Produto produto
typedef struct _Movimento movimento

struct _Produto {
    int cod;
    char nome[20];
    int qtd_estoque;
}
struct _Movimento {
    int cod;
    char tipo;
    int qtd_movimento;
}

void leDadosProdutos(produto lista[20]) {
    printf("==== LEITURA DE DADOS =====\n");
    for(int i = 0; i < 20; i++) {
        printf("== Produto %d ==\n", i+1);
        printf("Codigo: ");
        scanf("%d", &lista[i].cod);
        printf("Nome: ");
        scanf(" %[^\n]c", lista[i].nome);
        printf("Quantidade em estoque: ");
        scanf("%d", &lista[i].qtd_estoque);
    }
}

void Movimento(produto lista[20], movimento mov) {
    int solicitada, devolvida, pendente;
    for(int i = 0; i < 20; i++) {
        if (mov.cod == lista[i].cod) {
            if(mov.tipo == 's') {
                solicitada = mov.qtd_movimento;
                devolvida = 0;
                if(lista[i].qtd_estoque -= mov.qtd_movimento < 0) {
                    pendente = (lista[i].qtd_estoque - mov.qtd_movimento) * -1;
                    lista[i].qtd_estoque = 0;
                } 
            }
            else if(mov.tipo == 'd') {
                solicitada = 0;
                devolvida = mov.qtd_movimento;
                pendente = 0;
                lista[i].qtd_estoque += mov.qtd_movimento;
            }
        }
    }
}

void geraSaida(produto lista[20], movimento mov) {
    int solicitada, devolvida, pendente;
    printf("==== SAIDA ====\n");
    for(int i = 0; i < 20; i++) {
        printf("=== Produto %d ===\n", i+1);
        printf("Codigo: %d\n", lista[i].cod);
        printf("Nome: %s\n", lista[i].nome);
        Movimento(lista, mov);
        printf("Quantidade solicitada: %d\n", solicitada);
        printf("Quantidade devolvida: %d\n", devolvida);
        printf("Quantidade pendente: %d\n", pendente);
        printf("Quantidade total em estoque: %d\n", lista[i].qtd_estoque);
    }
}

int main() {
    produto lista[20];
    movimento mov;
    leDadosProdutos(lista);
    do {
        printf("s. Solicitacao\n");
        printf("d. Devolucao\n");
        printf("Insira a operacao de movimento desejada (E para encerrar): ");
        do {
            scanf("%c", &mov.tipo);
            if(mov.tipo != 's' || mov.tipo != 'd') {
                printf("Escolha invalida. Tente novamente: ");
            }
        } while(mov.tipo != 's' || mov.tipo != 'd');
        if(mov.tipo == 'E') {
            break;
        }
        printf("Codigo: ");
        scanf("%d", &mov.cod);
        printf("Quantidade: ");
        scanf("%d". &mov.qtd_movimento);
        geraSaida(lista, mov)
    } while(mov.tipo != 'E');
    return 0;
}

