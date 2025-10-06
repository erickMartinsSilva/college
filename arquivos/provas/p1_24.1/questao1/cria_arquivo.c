#include <stdio.h>
#include "ferramenta.h"

int main() {
    Ferramenta ferramentaVazia = {"", 0, 0};
    FILE *a;

    a = fopen("ferramentas.dat", "wb");

    for(int i = 0; i < 100; i++) {
        fwrite(&ferramentaVazia, sizeof(Ferramenta), 1, a);
    }

    fclose(a);
    return 0;
}