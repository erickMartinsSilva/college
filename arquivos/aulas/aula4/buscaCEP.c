// buscaCEP.c: programa que utiliza busca binária para procurar um determinado CEP num arquivo de registros de endereço

#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char** argv)
{
	FILE *f;
	Endereco e;
	int qt;
	int c;
	long int inicio = 0;
	long int fim;

	if(argc != 2) {
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	c = 0;
	f = fopen("cep_ordenado.dat","rb");
	if(!f) {
		fprintf(stderr, "Erro ao abrir arquivo cep_ordenado.dat. O arquivo existe?\n");
		return 1;
	}

	fseek(f, 0, SEEK_END);
	fim = ftell(f) / sizeof(Endereco); // fim: último registro de endereço do arquivo

	long int meio = (inicio+fim)/2; // definição da posição do endereço no meio do arquivo
	
	fseek(f, meio * sizeof(Endereco), SEEK_SET);
	qt = fread(&e,sizeof(Endereco),1,f);
	while(inicio <= fim) {
		c++;

		// se o cep buscado for menor que o do meio, buscar na primeira metade do arquivo
		if(strncmp(argv[1],e.cep, 8) < 0) {
			fim = meio - 1;
		}
		// se o cep buscado for maior que o do meio, buscar na segunda metade do arquivo
		if(strncmp(argv[1],e.cep, 8) > 0) {
			inicio = meio + 1;
		}
		// se o cep buscado for o do meio, imprimir suas informações
		if(strncmp(argv[1],e.cep,8) == 0) {
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			break;
		}

		// definição do novo meio do arquivo e endereço lido para a próxima iteração
		meio = (inicio + fim)/2;
		fseek(f, meio * sizeof(Endereco), SEEK_SET);

		qt = fread(&e,sizeof(Endereco),1,f);		
	}
	
	fclose(f);
}

