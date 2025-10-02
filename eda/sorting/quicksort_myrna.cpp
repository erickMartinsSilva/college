// Algoritmo que usa o Quick Sort para organizar um vetor de 8 posições (Escrito por Myrna Amorim)
#include <iostream>
#include <stdlib.h>

using namespace std;

void exibeArray(int arr[]) {
    cout << "[";
    for(int i = 0; i < 8; i++) {
        if(i == 7) {
            cout << arr[i] << "]\n";
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort(int arr[], int inicio, int fim) {
    int i, j, chave;
    if(fim - inicio < 2) {
        if((fim - inicio) == 1) {
            if(arr[inicio] > arr[fim]) {
                troca(&arr[inicio],&arr[fim]);
            }
        }
    }
    else {
        i = inicio;
        j = fim;
        chave = arr[inicio];
        while(j > i) {
            i++;
            while(arr[i] < chave) {
                i++;
            }
            while(arr[j] > chave) {
                j--;
            }
            if(j > i) {
                troca(&arr[i],&arr[j]);
            }
        }
        troca(&arr[inicio],&arr[j]);
        exibeArray(arr);
        quickSort(arr,inicio,j-1);
        exibeArray(arr);
        quickSort(arr,j+1,fim);
        exibeArray(arr);
    }
}

int main() {
    int arr[8] = {10, 29, 30, 18, 12, 34, 59, 72};
    cout << "Vetor inicial: ";
    exibeArray(arr);
    quickSort(arr, 0, 7);
    return 0;
}
