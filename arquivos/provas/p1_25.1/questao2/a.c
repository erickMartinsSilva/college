#include <stdio.h>
#include "../pagamento.h"

int main() {
  FILE *a;
  Pagamento buffer;

  a = fopen("beneficios.dat", "rb");

  fseek(a, 4 * sizeof(Pagamento), SEEK_SET);
  fread(&buffer, sizeof(Pagamento), 1, a);

  fseek(a, 8 * sizeof(Pagamento), SEEK_SET);
  fread(&buffer, sizeof(Pagamento), 1, a);
  printf("%s %f", buffer.cpf, buffer.valor);

  fseek(a, -2 * sizeof(Pagamento), SEEK_CUR);
  fread(&buffer, sizeof(Pagamento), 1, a);
  printf("%s %f", buffer.nome, buffer.valor);

  fseek(a, -1 * sizeof(Pagamento), SEEK_END);
  fread(&buffer, sizeof(Pagamento), 1, a);
  fscanf(a, "%s %f", buffer.cpf, buffer.valor);
}
