// Algoritmo que usa da busca sequencial para encontrar um número informado pelo usuário em uma lista não-organizada
#include <iostream>

#define SIZE 10

using namespace std;

void printArray(int arr[]) {
    cout << "[";
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE-1) {
            cout << arr[i] << "]" << endl;
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

int linearSearch(int arr[], int alvo) {
    bool achou = false;
    int i = 0;
    while(!achou && i < SIZE) {
        if(arr[i] == alvo) {
            achou = true;
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}

int main() {
    int alvo, arr[SIZE] = {72, 39, 8, 56, 91, 23, 65, 4, 19, 88};
    printArray(arr);
    cout << "Insira um numero para buscar: ";
    cin >> alvo;
    if(linearSearch(arr,alvo) == -1) {
        cout << "Numero nao encontrado\n";
    }
    else {
        cout << "Numero encontrado! Indice: " << linearSearch(arr,alvo) + 1 << "\n";
    }
    return 0;
}
