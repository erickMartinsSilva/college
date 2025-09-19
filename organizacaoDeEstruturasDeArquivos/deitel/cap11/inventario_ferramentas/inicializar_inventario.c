// inicializa o inventário com 100 registros vazios
#include <stdio.h>
#include <ferramenta.h>

int main() {
    FILE *hPtr;
    FerramentaData ferramenta = {0, "", 0, 0.0};

    hPtr = fopen("hardware.dat", "wb");
    
    for(int i = 0; i < AMOUNT_ENTRYS; i++) {
        fwrite(&ferramenta, sizeof(FerramentaData), 1, hPtr);
    }

    fclose(hPtr);
    return 0;
}