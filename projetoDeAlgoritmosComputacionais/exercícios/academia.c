// O programa simula um software de academia, permitindo que o usuário adicione, modifique e remova alunos, além de exibir relatórios

#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 5

typedef struct {
	char nome[100], nome_atividade[100];
	int idade;
 	float peso, altura;
} aluno;

int menu() {
	int escolha;
	printf("\n1. Ler dados dos alunos\n");
	printf("2. Exibir alunos cadastrados\n");
	printf("3. Exibir relatorio ordenado\n");
	printf("4. Atualizar dados do aluno\n");
	printf("5. Remover aluno\n");
	printf("6. Sair\n");
	scanf("%d", &escolha);
	return escolha;
}

void leDados(aluno turma[]) {
  	for(int i = 0; i < SIZE; i++) {
		printf("====== ALUNO %d ======\n", i+1);
		printf("Nome: ");
		scanf("     %[^\n]c", turma[i].nome);
		printf("Idade: ");
		scanf("%d", &turma[i].idade);
		printf("Peso (kg): ");
		scanf("%f", &turma[i].peso);
		printf("Altura (m): ");
		scanf("%f", &turma[i].altura);
		printf("Atividade: ");
		scanf("     %[^\n]c", turma[i].nome_atividade);
  	}
}	

void atualizaDados(aluno turma[]) {
	char nome[100];
	int achou;
	printf("\nInsira o nome do aluno: ");
	scanf("    %[^\n]s", nome);
	for(int i = 0; i < SIZE; i++) {
		achou = 0;
		if(strcmp(nome,turma[i].nome) == 0) {
			achou = 1;
			printf("Aluno encontrado!\n");
			printf("Insira a idade do aluno: ");
			scanf("%d", &turma[i].idade);
			printf("Insira o peso do aluno: ");
			scanf("%f", &turma[i].peso);
			printf("Insira a altura do aluno: ");
			scanf("%f", &turma[i].altura);
			printf("Insira a atividade que o aluno faz: ");
			scanf("     %[^\n]s", turma[i].nome_atividade);
		}
	}
	if (achou == 0) {
		printf("Aluno nao encontrado\n");
	}
}

void removeAluno(aluno turma[]) {
	char nome[100];
	aluno aux;
	int achou, trocou;
	printf("Insira o nome do aluno: ");
	scanf("     %[^\n]s", nome);
	for(int i = 0; i < SIZE; i++) {
		achou = 0;
		if(strcmp(nome,turma[i].nome) == 0) {
			achou = 1;
			strcpy(turma[i].nome,"");
			turma[i].idade = 0;
			turma[i].peso = 0;
			turma[i].altura = 0;
			strcpy(turma[i].nome_atividade,"");
			break;
		}
	}
	do {
		for(int i = 0; i < SIZE-1; i++) {
			trocou = 0;
			if(strcmp(turma[i].nome,turma[i+1].nome) < 0) {
				trocou = 1;
				aux = turma[i];
				turma[i] = turma[i+1];
				turma[i+1] = aux;
			}
		}
	} while(trocou);
	if(achou) {
		printf("Aluno encontrado e removido com sucesso!\n");
	}
	else {
		printf("Aluno nao encontrado\n");
	}
}

void imprimeDados(aluno turma[]) {
  	for(int i = 0; i < SIZE; i++) {
		if(strlen(turma[i].nome) != 0) {
			printf("====== ALUNO %d ======\n", i+1);
			printf("Nome: %s\n", turma[i].nome);
			printf("Idade: %d anos\n", turma[i].idade);
			printf("Peso: %.2f kg\n", turma[i].peso);
			printf("Altura: %.2f m\n", turma[i].altura);
			printf("Atividade: %s\n", turma[i].nome_atividade);
		}
 	}
}

void relatorioOrdenado(aluno turma[]) {
  int trocou;
  aluno aux;
  do {
	for(int i = 0; i < SIZE-1; i++) {
		trocou = 0;
		if(strcmp(turma[i].nome,turma[i+1].nome) > 0) {
			aux = turma[i];
			turma[i] = turma[i+1];
			turma[i+1] = aux;
			trocou = 1;
		}
	}
  } while(trocou);
	printf("\nNome\tIdade\tPeso (kg)\tAltura (m)\tAtividade\tIMC\t\n");
	for(int i = 0; i < SIZE; i++) {
		if(strlen(turma[i].nome) != 0) {
			printf("%s\t", turma[i].nome);
			printf("%d\t", turma[i].idade);
			printf("%.2f\t\t", turma[i].peso);
			printf("%.2f\t\t", turma[i].altura);
			printf("%s\t\t", turma[i].nome_atividade);
			printf("%.2f\n", turma[i].peso/pow(turma[i].altura,2));
		}
 	}
}

int main() {
	aluno turma[SIZE], turma_ord[SIZE];
	int escolha;
	printf("\n===== ACADEMIA =====\n");
	do {
		switch(escolha = menu()) {
			case 1:
				leDados(turma);
				break;
			case 2:
				imprimeDados(turma);
				break;
			case 3:
				for(int i = 0; i < SIZE; i++) {
					turma_ord[i] = turma[i];
				}
				relatorioOrdenado(turma_ord);
				break;
			case 4:
				atualizaDados(turma);
				break;
			case 5:
				removeAluno(turma);
				break;
			case 6:
				break;
			default:
				printf("Escolha invalida, tente novamente: ");
				break;
		}
	} while(escolha != 6);
  	return 0;
}