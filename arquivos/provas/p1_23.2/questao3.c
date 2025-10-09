#include <stdio.h>

int main() {
    FILE* f;
    char c;
    int count = 0;

    f = fopen("arquivo.txt", "r");
    if(!f) {
        fprintf(stderr, "ERRO: Arquivo inexistente\n");
        return 1;
    }

    c = fgetc(f);
    while(c != EOF && count >= 0) {
        if(c == '{') {
            count++;
        }
        if(c == '}') {
            count--;
        }
        c = fgetc(f);
    }

    if(count > 0 || count < 0) {
        printf("Chaves desbalanceadas\n");
    } else {
        printf("Chaves balanceadas\n");
    }

    fclose(f);
    return 0;
}