#include <stdio.h>

typedef struct {
    int id;
    char nome[30];
    char especie[20];
    int idade;
    float peso;
} Animal;

long int buscar_registro(FILE *r, int id) {
    Animal buffer;
    int qt;

    printf("Insira o ID do animal que deseja buscar: ");
    scanf("%d", &id);

    fread(&buffer, sizeof(Animal), 1, r);
    while(!feof(r) || buffer.id != id) {
        fread(&buffer, sizeof(Animal), 1, r);
    }

    if(buffer.id == id) {
        printf("ID: %d | Nome: %s | Espécie: %s | Idade: %d anos | Peso: %.2f kg",
            buffer.id, buffer.nome, buffer.especie, buffer.idade, buffer.peso
        );
        return ftell(r) / sizeof(Animal);
    }

    printf("Erro: registro não encontrado");
    return -1;
}

void adicionar_registro(FILE *r) {
    Animal buffer;
    long int pos;

    printf("Insira as informações do novo registro (id nome espécie idade peso): ");
    scanf("%d %s %s %d %f", buffer.id, buffer.nome, buffer.especie, buffer.idade, buffer.peso);

    pos = buscar_registro(r, buffer.id);
    if(pos != -1) {
        printf("Erro: um registro com esse id já existe");
    } else {
        fseek(r, 0, SEEK_END);
        fwrite(&buffer, sizeof(Animal), 1, r);
    }
}

void alterar_registro(FILE *r, int id) {
    long int pos = buscar_registro(r, id);

    if(pos == -1) {
        printf("Erro: registro não existe");
    } else {
        Animal buffer;
        printf("Insira as informações do novo registro (id nome espécie idade peso): ");
        scanf("%s %s %d %f", buffer.nome, buffer.especie, buffer.idade, buffer.peso);

        fseek(r, -sizeof(Animal), SEEK_CUR);
        fwrite(&buffer, sizeof(Animal), 1, r);
    }
}

int main() {
    FILE *r;
    long int pos;
    int id;

    r = fopen("registro_animais.dat", "a+b");

    pos = buscar_registro(r, id);
    adicionar_registro(r);
    alterar_registro(r, id);

    fclose(r);
    return 0;
}