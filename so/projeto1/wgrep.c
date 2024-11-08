#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *linha = NULL;
    size_t size = 0;
    FILE *arquivo;
    if(argc < 3) {
        return 0;
    }
    else {
        for(int i = 2; i < argc; i++) { 
            arquivo = fopen(argv[i], "r"); 
            if(arquivo == NULL) {
                fprintf(stderr,"wgrep: cannot open file\n");
                return 1;
            }
            else {
                while((size = getline(&linha,&size,arquivo)) != -1) {
                    if(strstr(linha, argv[1]) != NULL) {
                        printf("%s", linha);
                    }
                }
            }
            fclose(arquivo);
        }
    }
    return 0;
}
