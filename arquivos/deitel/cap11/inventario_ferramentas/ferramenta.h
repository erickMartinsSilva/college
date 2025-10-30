#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#define AMOUNT_ENTRYS 100

typedef struct _FerramentaData {
    int numero;
    char nome[50];
    int qtd;
    float custo;
} FerramentaData;

void printFerramenta(FerramentaData, char);

#endif