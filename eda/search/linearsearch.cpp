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
    int i = 0;
    while(i < SIZE) {
        if(arr[i] == alvo) {
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}

int main() {
    int alvo, i, arr[SIZE] = {72, 39, 8, 56, 91, 23, 65, 4, 19, 88};
    printArray(arr);
    cout << "Insira um numero para buscar: ";
    cin >> alvo;
    switch(i = linearSearch(arr, alvo)) {
        case -1: cout << "Numero nao encontrado\n"; break;
        default: cout << "Numero encontrado! Indice: " << i << endl; break;
    }
    return 0;
}
