#include <stdio.h>
#include "ferramenta.h"

void printFerramenta(FerramentaData f, char mode) {
    // o caractere mode define como as informações da ferramenta serão exibidas
    switch(mode) {
        // case 'd': por linha
        case 100: 
            printf("\nRegistro %d:\nNome: %s\nQuantidade: %d\nCusto: R$%.2f\n\n",
                f.numero, f.nome, f.qtd, f.custo
            );
            break;
        // case 't': tabular
        case 116: 
            printf("%d\t%s\t\t%d\tR$%.2f\n\n",
                f.numero, f.nome, f.qtd, f.custo
            );
            break;
    }
}