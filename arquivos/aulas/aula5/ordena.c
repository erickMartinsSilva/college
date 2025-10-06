// ordena.c: programa que ordena um arquivo de registros de endereço dividindo-o em blocos e intercalando-os.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NUM_PARTES: número de blocos em que o arquivo base será dividido para ordenação
#define NUM_PARTES 4

typedef struct _Endereco {
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
} Endereco;

// === função de comparação entre dois registros de endereço, será utilizada para ordenar os registros por CEP ===
int compara(const void *e1, const void *e2) {
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

// === função que mescla dois arquivos de registro de endereço, ordenando-os no processo ===
void intercala(char *f1, char *f2, char* fsaida) {
	printf("%s - %s\n", f1, f2);
	FILE *a, *b, *saida;
	Endereco ea, eb;

	// a, b -> arquivos que serão intercalados
	a = fopen(f1, "rb");
	b = fopen(f2, "rb");
	saida = fopen(fsaida, "wb"); // arquivo gerado pela intercalação de a, b

	fread(&ea,sizeof(Endereco), 1, a);
	fread(&eb,sizeof(Endereco), 1, b);

	// processo se repete até chegar ao fim de um dos arquivos
	while(!feof(a) && !feof(b)) {
		if(compara(&ea, &eb) < 0) { // ea < eb
			fwrite(&ea, sizeof(Endereco), 1, saida);
			fread(&ea, sizeof(Endereco), 1, a);
		} else { // ea >= eb
			fwrite(&eb, sizeof(Endereco), 1, saida);
			fread(&eb, sizeof(Endereco), 1, b);
		}
	}

	// escreve os registros que sobraram de a no arquivo de saída, se houver
	while(!feof(a)) {
		fwrite(&ea, sizeof(Endereco), 1, saida);
		fread(&ea, sizeof(Endereco), 1, a);		
	}
	
	// escreve os registros que sobraram de b no arquivo de saída, se houver
	while(!feof(b))	{
		fwrite(&eb, sizeof(Endereco), 1, saida);
		fread(&eb, sizeof(Endereco), 1, b);		
	}

	fclose(a);
	fclose(b);
	// remove arquivos criados para cada bloco na intercalação
	remove(f1);
	remove(f2);
	fclose(saida);
}

int main(int argc, char**argv)
{
	FILE *a, *b, *f, *saida;
	Endereco *e;
    char nome_saida[20], nome_a[20], nome_b[20], nome_c[20];
	long posicao, qtd, parte, resto;

	f = fopen("cep.dat","rb");
	fseek(f,0,SEEK_END);
	posicao = ftell(f); // posicao: tamanho total do arquivo em bytes
	qtd = posicao/sizeof(Endereco); // qtd: quantidade de registros de endereço que o arquivo possui
	parte = qtd/NUM_PARTES; // define o tamanho que cada bloco do arquivo deve ter
    resto = qtd % NUM_PARTES; // define o tamanho do resto do arquivo, se houver
    rewind(f);

    // === divisão do arquivo principal em um número de partes definido por NUM_PARTES ===
    for(int i = 0; i < NUM_PARTES; i++) {
        if(i == NUM_PARTES - 1) {
            parte += resto;
        }
        e = (Endereco*) malloc(parte*sizeof(Endereco));

        fread(e, sizeof(Endereco), parte, f);
        qsort(e, parte, sizeof(Endereco), compara);

        sprintf(nome_saida, "cep_%d.dat", i); // armazena nome de um bloco num array de string
        saida = fopen(nome_saida, "wb"); // criando arquivo para armazenar um bloco
        fwrite(e, sizeof(Endereco), parte, saida); // inserindo uma parte do arquivo base num bloco

        fclose(saida);
        free(e);
    }

    int i = 0;
    int k = NUM_PARTES;

	// === intercalação de cada bloco para gerar o arquivo ordenado ===
    sprintf(nome_a, "cep_%d.dat", i);
    sprintf(nome_b, "cep_%d.dat", i+1);
    sprintf(nome_c, "cep_%d.dat", k);
	// processo se repete até que todas as intercalações possíveis tenham sido feitas
    while(k <= (NUM_PARTES * 2) - 2) {
        intercala(nome_a, nome_b, nome_c);
        i += 2;
        k++;

        sprintf(nome_a, "cep_%d.dat", i);
        sprintf(nome_b, "cep_%d.dat", i+1);
        sprintf(nome_c, "cep_%d.dat", k);
    }

    rename(nome_a, "cep_ordenado.dat"); // renomeia o arquivo ordenado

    fclose(f);
}

