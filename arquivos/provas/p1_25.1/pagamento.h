#ifndef PAGAMENTO_H
#define PAGAMENTO_H

typedef struct {
  char cpf[12], nome[80];
  int mes, ano;
  float valor;
} Pagamento;

#endif
