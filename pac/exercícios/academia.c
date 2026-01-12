// academia.c: simulação de um software para uso em academias

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_ALUNOS_SIZE 5

typedef struct {
	char nome[100], nome_atividade[100];
	int idade;
  float peso, altura;
} Aluno;

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

void leDados(Aluno alunos[]) {
  	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
		printf("====== ALUNO %d ======\n", i+1);
		printf("Nome: ");
		scanf("     %[^\n]c", alunos[i].nome);
		printf("Idade: ");
		scanf("%d", &alunos[i].idade);
		printf("Peso (kg): ");
		scanf("%f", &alunos[i].peso);
		printf("Altura (m): ");
		scanf("%f", &alunos[i].altura);
		printf("Atividade: ");
		scanf("     %[^\n]c", alunos[i].nome_atividade);
  	}
}	

void atualizaDados(Aluno alunos[]) {
	char nome[100];
	int achou;
	printf("\nInsira o nome do aluno: ");
	scanf("    %[^\n]s", nome);
	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
		achou = 0;
		if(strcmp(nome,alunos[i].nome) == 0) {
			achou = 1;
			printf("Aluno encontrado!\n");
			printf("Insira a idade do aluno: ");
			scanf("%d", &alunos[i].idade);
			printf("Insira o peso do aluno: ");
			scanf("%f", &alunos[i].peso);
			printf("Insira a altura do aluno: ");
			scanf("%f", &alunos[i].altura);
			printf("Insira a atividade que o aluno faz: ");
			scanf("     %[^\n]s", alunos[i].nome_atividade);
		}
	}
	if (!achou) {
		printf("Aluno nao encontrado\n");
	}
}

void removeAluno(Aluno alunos[]) {
	char nome[100];
	Aluno aux;
	int achou, trocou;
	printf("Insira o nome do aluno: ");
	scanf("     %[^\n]s", nome);
	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
		achou = 0;
		if(strcmp(nome,alunos[i].nome) == 0) {
			achou = 1;
			strcpy(alunos[i].nome,"");
			alunos[i].idade = 0;
			alunos[i].peso = 0;
			alunos[i].altura = 0;
			strcpy(alunos[i].nome_atividade,"");
			break;
		}
	}
	do {
		for(int i = 0; i < MAX_ALUNOS_SIZE-1; i++) {
			trocou = 0;
			if(strcmp(alunos[i].nome,alunos[i+1].nome) < 0) {
				trocou = 1;
				aux = alunos[i];
				alunos[i] = alunos[i+1];
				alunos[i+1] = aux;
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

void imprimeDados(Aluno turma[]) {
  	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
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

void relatorioOrdenado(Aluno alunos[]) {
  int trocou;
  Aluno aux;
  do {
	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
		trocou = 0;
		if(strcmp(alunos[i].nome,alunos[i+1].nome) > 0) {
			aux = alunos[i];
			alunos[i] = alunos[i+1];
			alunos[i+1] = aux;
			trocou = 1;
		}
	}
  } while(trocou);
	printf("\nNome\tIdade\tPeso (kg)\tAltura (m)\tAtividade\tIMC\t\n");
	for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
		if(strlen(alunos[i].nome) != 0) {
			printf("%s\t", alunos[i].nome);
			printf("%d\t", alunos[i].idade);
			printf("%.2f\t\t", alunos[i].peso);
			printf("%.2f\t\t", alunos[i].altura);
			printf("%s\t\t", alunos[i].nome_atividade);
			printf("%.2f\n", alunos[i].peso/pow(alunos[i].altura,2));
		}
 	}
}

int main() {
	Aluno alunos[MAX_ALUNOS_SIZE], alunos_ordenados[MAX_ALUNOS_SIZE];
	int escolha;
	printf("\n===== ACADEMIA =====\n");
	do {
		switch(escolha = menu()) {
			case 1:
				leDados(alunos);
				break;
			case 2:
				imprimeDados(alunos);
				break;
			case 3:
				for(int i = 0; i < MAX_ALUNOS_SIZE; i++) {
					alunos_ordenados[i] = alunos[i];
				}
				relatorioOrdenado(alunos_ordenados);
				break;
			case 4:
				atualizaDados(alunos);
				break;
			case 5:
				removeAluno(alunos);
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
