#include <iostream>

using namespace std;

struct produto {
    int cod;
    struct produto* prox;
};

struct cliente {
    int info;
    struct produto* p;
    struct cliente* ant;
    struct cliente* prox;
};

typedef struct cliente* clientePtr;
typedef struct produto* produtoPtr;

int menu() {
    int op;
    cout << "1. Adicionar cliente\n2. Registrar consumo do cliente\n3. Remover cliente\n4. Sair" << endl;
    cin >> op;
    return op;
}

bool listaClientesVazia(clientePtr T) {
    if(T) {
        return false;
    } else return true;
}

bool listaPedidosVazia(produtoPtr T) {
    if(T) {
        return false;
    } else return true;
}

void removerCliente(clientePtr* T, clientePtr* F, clientePtr aux) {
    if(aux == *T) {
        if((*T)->prox != NULL) {
            (*T)->prox->ant = NULL;
        }
        *T = (*T)->prox;
    } else if (aux == *F) {
        if((*F)->ant != NULL) {
            (*F)->ant->prox = NULL;
        }
        *F = (*F)->ant;
    } else {
        if(aux->ant != NULL) {
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }
    }
    delete aux;
}

void chegadaCliente(clientePtr* T, clientePtr* F) {
    clientePtr p = new cliente;
    if(listaClientesVazia(*T)) {
        p->info = 100;
        p->ant = NULL;
        p->prox = NULL;
        *T = p;
        *F = p;
    } else {
        (*F)->prox = p;
        p->ant = *F;
        p->prox = NULL;
        p->info = (p->ant->info + 100);
        *F = p;
    }
    cout << "Cliente adicionado com sucesso! Codigo: " << p->info << endl;
}

void consumoCliente(clientePtr* T) {
    int cod_cliente, cod_produto;
    if(listaClientesVazia(*T)) {
        cout << "Erro! Nao ha clientes registrados" << endl;
    } else {
        cout << "Codigo do cliente: ";
        cin >> cod_cliente;
        clientePtr aux = *T;
        while(aux->prox != NULL && aux->info != cod_cliente) {
            aux = aux->prox;
        }
        if(aux->info == cod_cliente) {
           produtoPtr q = new produto, aux2 = aux->p;
           cout << "Codigo do produto: ";
           cin >> cod_produto;
           q->cod = cod_produto;
           if(listaPedidosVazia(aux->p)) {
                aux->p = q;
           } else {
                while(aux2->prox != NULL) {
                    aux2 = aux2->prox;
                }
                aux2->prox = q;
                q->prox = NULL;
           }
           cout << "Produto de codigo " << cod_produto << " adicionado com sucesso a lista do cliente de codigo " << cod_cliente << endl;
        } else cout << "Erro! Cliente nao encontrado" << endl;
    }
}

void saidaCliente(clientePtr* T, clientePtr* F) {
    if(listaClientesVazia(*T)) {
        cout << "Erro! Nao ha clientes registrados" << endl;
    } else {
        clientePtr aux = *T;
        int cod_cliente;
        cout << "Codigo do cliente: ";
        cin >> cod_cliente;
        while(aux->prox != NULL && aux->info != cod_cliente) {
            aux = aux->prox;
        }
        if(aux->info == cod_cliente) {
            if(listaPedidosVazia(aux->p)) {
                removerCliente(T,F,aux);
            } else {
                cout << "Consumo do cliente de codigo " << aux->info << ": ";
                produtoPtr aux2 = aux->p, ant;
                while(aux2 != NULL) {
                    cout << aux2->cod << " ";
                    ant = aux2;
                    aux->p = aux->p->prox;
                    aux2 = aux2->prox;
                    delete ant;
                }
                removerCliente(T,F,aux);
                cout << "\nCliente removido com sucesso" << endl;
            }
        } else cout << "Erro! Cliente nao encontrado" << endl;
    }
}  

int main() {
    clientePtr T = NULL, F = NULL;
    int op;
    do {
        switch(op = menu()) {
            case 1: chegadaCliente(&T, &F); break;
            case 2: consumoCliente(&T); break;
            case 3: saidaCliente(&T, &F); break;
            default: break;
        }
    } while(op != 4);
    return 0;
}