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
	fim = ftell(f) / sizeof(Endereco);

	long int meio = (inicio+fim)/2;
	
	fseek(f, meio * sizeof(Endereco), SEEK_SET);
	qt = fread(&e,sizeof(Endereco),1,f);
	while(inicio <= fim) {
		c++;

		if(strncmp(argv[1],e.cep, 8) < 0) {
			fim = meio - 1;
		}
		if(strncmp(argv[1],e.cep, 8) > 0) {
			inicio = meio + 1;
		}
		if(strncmp(argv[1],e.cep,8) == 0) {
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			break;
		}

		meio = (inicio + fim)/2;
		fseek(f, meio * sizeof(Endereco), SEEK_SET);

		qt = fread(&e,sizeof(Endereco),1,f);		
	}
	
	fclose(f);
}

