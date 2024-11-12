// Algoritmo que usa busca binária para encontrar um elemento numa lista ordenada
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

int binarySearch(int arr[], int alvo) {
    int left = 0, right = SIZE-1, mid, achou = 0;
    while(left <= right) {
        mid = (left+right)/2;
        if(arr[mid] == alvo) {
            return mid;
        }
        else if (arr[mid] < alvo) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, alvo, resultado;
    printArray(arr);
    cout << "Insira o numero que deseja buscar na lista: ";
    cin >> alvo;
    resultado = binarySearch(arr,alvo);
    if(resultado == -1) {
        cout << "Numero nao encontrado" << endl;
    }
    else {
        cout << "Numero encontrado! Indice: " << resultado+1 << endl;
    }
    return 0;
}