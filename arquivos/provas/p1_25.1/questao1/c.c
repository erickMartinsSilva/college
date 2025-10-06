// Questão 1-c)
// Escreva uma função eficiente que, dado um mês e um ano passados por parâmetro, calcule o total pago nesse período.

#include <stdio.h>
#include "../pagamento.h"

FILE *a;

int ano_mes(int mes, int ano) {
  return ano * 100 + mes;
}

float total_pago_mes_ano(int mes, int ano) {
  Pagamento buffer;
  long int inicio = 0, fim, meio;
  int anoMes = ano_mes(mes, ano);
  float total_pago = 0;

  fseek(a, 0, SEEK_END);
  fim = ftell(a) / sizeof(Pagamento);
  meio = (inicio+fim) / 2;
  rewind(a);

  while(inicio <= fim) {
    fseek(a, meio * sizeof(Pagamento), SEEK_SET);
    fread(&buffer, sizeof(Pagamento), 1, a);
    if((ano_mes(buffer.mes, buffer.ano)) < anoMes) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }

    meio = (inicio+fim) / 2;
  }

  printf("%d %d", ano_mes(buffer.mes, buffer.ano), anoMes);

  while(ano_mes(buffer.mes, buffer.ano) == anoMes) {
    printf("%f\n", buffer.valor);
    total_pago += buffer.valor;
    fread(&buffer, sizeof(Pagamento), 1, a);
  }

  return total_pago;
}

int main() {
  a = fopen("beneficios.dat", "rb");

  int mes = 12, ano = 2024;

  float total_pago = total_pago_mes_ano(mes, ano);
  printf("Total pago no mês %d de %d: R$%.2f\n", mes, ano, total_pago);
}
