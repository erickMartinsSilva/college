#include <stdio.h>

int main() {
    FILE *a;
    char c;
    int count = 0;

    a = fopen("arquivo.txt", "r");

    c = fgetc(a);
    while(c != EOF) {
        if(c == '{') {
            count++;
        } 
        if(c == '}') {
            count--;
        }
        if(count == -1) {
            break;
        }

        c = fgetc(a);
    }

    if(count == -1) {
        printf("Chaves não estão balanceadas");
    } else {
        printf("Chaves estão balanceadas");
    }

    fclose(a);
    return 0;
}