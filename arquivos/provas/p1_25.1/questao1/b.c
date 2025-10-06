// Questão 1-b)
// Considere que existe um segundo arquivo binário chamado novos.dat, contendo novos registros de pagamento a serem adicionados.
// Realize a inclusão em lote, ou seja, adicionar todos os registros de novos.dat ao final de beneficios.dat.

#include <stdio.h>
#include "../pagamento.h"

void inclusaoLotes(FILE *a, FILE *b) {
  Pagamento *buffer;

  while(fread(buffer, sizeof(Pagamento), 1, b) > 0) {
    fwrite(buffer, sizeof(Pagamento), 1, a);
  }
}

int main() {
  FILE *a, *b;

  a = fopen("beneficios.dat", "ab");
  b = fopen("novos.dat", "rb");

  inclusaoLotes(a, b);

  fclose(a);
  fclose(b);

  return 0;
}
