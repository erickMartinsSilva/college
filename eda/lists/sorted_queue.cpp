// Exemplo do funcionamento de uma lista encadeada ordenada com a política de fila
#include <iostream>

using namespace std;

struct no { // declaração de uma estrutura que representa cada elemento da lista encadeada
    int info; // valor do elemento
    struct no* prox; // ponteiro que aponta para o endereço do próximo elemento da lista
};

typedef struct no* noPtr;
noPtr topo = NULL; // como topo aponta para NULL, a lista inicialmente está vazia

int menu() {
    int op;
    cout << "\n1. Inserir\n2. Consultar\n3. Sair\n";
    cin >> op;
    return op;
}

bool listaVazia() {
    if(topo == NULL) {
        return true;
    } else return false;
}

void inserir() {
    noPtr aux, ant, p = new no;
    cout << "Entre com o numero a ser inserido na lista: ";
    cin >> p->info;
    if(listaVazia()) { // se a lista estiver vazia, p será o primeiro elemento da lista
        topo = p;
        p->prox = NULL;
    } else { // se não, como a lista é ordenada, precisamos definir onde p precisa estar
        aux = topo;
        while(aux->prox != NULL && p->prox > aux->prox) { // confere se p é maior que todos os elementos ou se ele está entre dois elementos na lista
            ant = aux;
            aux = aux->prox;
        }
        if(aux == topo) { // se aux for igual a topo, significa que nada do while foi feito, logo p é menor que todos os elementos da lista
            p->prox = aux; // p aponta para o elemento que era o topo da lista
            topo = p; // topo aponta para p, logo p é o novo primeiro elemento da lista
        } else {
            p->prox = aux; // o próximo elemento de p será o elemento na variável aux. se aux = NULL, p será o último elemento da lista
            ant->prox = p; // se p estiver entre dois elementos, o próximo elemento de p será aux e o próximo elemento do anterior será p
        }
    }
}

void consultar() {
    int num, cntd = 1; noPtr aux; bool achei = false;
    if(listaVazia()) {
        cout << "Lista vazia!\n";
    } else {
        cout << "Insira um numero para verificar se o mesmo esta na lista: ";
        cin >> num;
        aux = topo;
        while(aux != NULL && !achei) { // percorre a lista encadeada até chegar no fim ou até o número ser encontrado
            if(aux->info == num) {
                achei = true;
            } else {
                aux = aux->prox;
                cntd++; // contador para verificar a posição do número na lista
            }
        }
        if(achei) {
            cout << "Numero encontrado! Posicao: " << cntd << endl;
        } else cout << "Numero nao encontrado\n";
    }
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: inserir(); break;
            case 2: consultar(); break;
            default: break;
        }
    } while(op != 3);
    return 0;
}