#include <stdio.h>

int main() {
    char bloco[3] = { '\0' };
    FILE* f = fopen("letras.dat","rb");
    fseek(f,-2,SEEK_END);
    fread(bloco,sizeof(char),3,f);
    printf("(a) %3.3s %ld %d\n", bloco, ftell(f), feof(f)); // YZ 26 1
    fseek(f,-3,SEEK_END);
    fread(bloco,sizeof(char),3,f);
    printf("(b) %3.3s %ld %d\n", bloco, ftell(f), feof(f)); // XYZ 26 0
    fseek(f,10,SEEK_SET);
    fread(bloco,sizeof(char),3,f);
    printf("(c) %3.3s %ld %d\n", bloco, ftell(f), feof(f)); // KLM 13 0
    fread(bloco,sizeof(char),3,f);
    printf("(d) %3.3s %ld %d\n", bloco, ftell(f), feof(f)); // NOP 16 0
    fseek(f,-3,SEEK_CUR);
    fread(bloco,sizeof(char),3,f);
    printf("(e) %3.3s %ld %d\n", bloco, ftell(f), feof(f)); // NOP 16 0
    fclose(f);
}