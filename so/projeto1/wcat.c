#include <stdio.h>

int main(int argc, char *argv[]) {
    char linha[100];
    FILE *arquivo;
    if(argc == 1) {
        return 0;
    }
    else {
        for(int i = 1; i < argc; i++) {
            arquivo = fopen(argv[i], "r");
            if(arquivo == NULL) {
                printf("wcat: cannot open file\n");
                return 1;
            }
            else {
                while(fgets(linha, sizeof(linha), arquivo) != NULL) {
                    printf("%s", linha);
                }
                printf("\n");
            }
            fclose(arquivo);
        }
    }
    return 0;
}
