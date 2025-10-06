// Questão 1-d)
// Para cada ano distinto no arquivo, imprima os dados de todos os beneficiários que receberam:
// O maior valor do benefício naquele ano,
// e o menor valor de benefício naquele ano.

#include <stdio.h>
#include "../pagamento.h"

int main() {
  FILE *a;
  Pagamento buffer, maior = {0}, menor = {0};
  int ano_atual, qt;

  a = fopen("beneficios.dat", "rb");

  fread(&buffer, sizeof(Pagamento), 1, a);
  while(!feof(a)) {
    ano_atual = buffer.ano;
    maior = buffer;
    menor = buffer;

    while(ano_atual == buffer.ano) {
      if(buffer.valor > maior.valor) {
        maior = buffer;
      }
      if(buffer.valor < menor.valor) {
        menor = buffer;
      }

      fread(&buffer, sizeof(Pagamento), 1, a);
    }

    printf("Beneficiário que recebeu o maior valor de benefício em %d: \n%s\n%s\n%d\nR$%.2f\n",
      ano_atual, maior.cpf, maior.nome, maior.mes, maior.valor
    );
    printf("Beneficiário que recebou o menor valor de benefício em %d: \n%s\n%s\n%d\nR$%.2f\n",
      ano_atual, menor.cpf, menor.nome, menor.mes, menor.valor
    );

    fread(&buffer, sizeof(Pagamento), 1, a);
  }

  return 0;
}
