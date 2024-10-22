#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[100];
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
                while(fgets(buffer, sizeof(buffer), arquivo) != NULL) {
                    printf("%s", buffer);
                }
                printf("\n");
            }
            fclose(arquivo);
        }
    }
    return 0;
}
