// Questão 1-a)
// Dado um arquivo binário "beneficios.dat" já existente contendo registros válidos, escreva um trecho de código que apresente:
// - O tamanho do arquivo em bytes;
// - O número total de registros contidos no arquivo.

#include <stdio.h>
#include "../pagamento.h"

int main() {
  FILE *b;
  long int tamanho_bytes, total_registros;

  b = fopen("beneficios.dat", "rb");

  fseek(b, 0, SEEK_END);
  tamanho_bytes = ftell(b);
  total_registros = tamanho_bytes / sizeof(Pagamento);

  printf("Tamanho total do arquivo em bytes: %ld\n", tamanho_bytes);
  printf("Número total de registros do arquivo: %ld\n", total_registros);

  return 0;
}
