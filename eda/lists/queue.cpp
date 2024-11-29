// Exemplo do funcionamento de uma lista encadeada com a política de fila (LIFO)
#include <iostream>

using namespace std;

struct no {
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
noPtr topo = NULL;

int menu() {
    int op; 
    cout << "\n1. Adicionar\n2. Remover\n3. Imprimir lista\n4. Sair\n";
    cin >> op;
    return op;
}

bool listaVazia() {
    if(topo) {
        return false;
    } else return true;
}

void imprimirLista() {
    noPtr aux = topo;
    if(!listaVazia()) {
        while(aux != NULL) {
            cout << aux->info << " ";
            aux = aux->prox;
        }
    } else cout << "Lista vazia!";
}

void enqueue() {
    noPtr ult, p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;
    p->prox = NULL;
    if(listaVazia()) {
        topo = p;
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista();
    } else {
        ult = topo;
        while(ult->prox != NULL) {
            ult = ult->prox;
        }
        ult->prox = p;
        cout << "Elemento adicionado com sucesso!\nNova lista: "; imprimirLista();
    }
}

void dequeue() {
    noPtr p = topo;
    if(listaVazia()) {
        cout << "Lista vazia!";
    } else {
        topo = topo->prox;
        delete(p);
        cout << "Elemento removido com sucesso!\nNova lista: "; imprimirLista();
    }
}

int main() {
    int op;
    do {
        op = menu();
        switch(op) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: imprimirLista(); break;
            default: break;
        }
    } while(op != 4);
    return 0;
}