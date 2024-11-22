// Implementação de uma pilha com menu que permite listar a pilha além de adicionar e remover elementos dela
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

noPtr topo = NULL;

int menu() {
    int op = 0;
    cout << "\n1. Empilhar\n2. Desempilhar\n3. Listar\n4. Sair\n";
    do {
        if(op > 4) {
            cout << "ERRO: Opcao invalida. Tente novamente: ";
        }
        cin >> op;
    } while(op > 4);
    return op;
}

bool listaVazia() {
    if(topo) {
        return false;
    } else return true;
}

void push() {
    noPtr p;
    int valor;

    p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> valor;
    p->info = valor;
    p->prox = topo;
    topo = p;
}

void imprimirLista() {
    noPtr aux;
    aux = topo;
    if(!listaVazia()) {
        while(aux != NULL) {
            cout << aux->info;
            aux = aux->prox;
        }
    } else cout << "Lista vazia!";
}

void pop() {
    noPtr p = topo;
    if(!listaVazia()) {
        topo = topo->prox;
        delete(p);
        cout << "Elemento retirado da pilha.";
    } else cout << "Lista vazia!";
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: imprimirLista(); break;
            default: break;
        }
    } while(op != 4);
    return 0;
}