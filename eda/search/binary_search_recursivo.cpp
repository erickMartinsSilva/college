// Algoritmo que usa busca binária implementada de forma recursiva para encontrar um elemento numa lista ordenada
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

int binarySearch(int arr[], int inicio, int fim, int alvo) {
    int mid;
    if(inicio <= fim) {
        mid = (inicio+fim)/2;
        if(arr[mid] == alvo) {
            return mid;
        }
        if(arr[mid] < alvo) {
            return binarySearch(arr, mid+1, fim, alvo);
        }
        else {
            return binarySearch(arr, inicio, mid-1, alvo);
        }
    }
    else {
        return -1;
    }
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, alvo, resultado;
    printArray(arr);
    cout << "Insira um numero para buscar: ";
    cin >> alvo;
    resultado = binarySearch(arr,0,SIZE-1,alvo);
    if(resultado == -1) {
        cout << "Numero nao encontrado" << endl;
    }
    else {
        cout << "Numero encontrado! Indice: " << resultado+1 << endl;
    }
}