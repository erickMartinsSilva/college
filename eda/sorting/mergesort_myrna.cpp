#include <iostream>

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

void intercala(int arr[], int inicio, int fim, int meio) {
    int i, aux[8], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio+1;
    while(inicioA1 <= meio && inicioA2 <= fim) {
        if(arr[inicioA1] > arr[inicioA2]) {
            aux[posLivre] = arr[inicioA2];
            inicioA2++;
        }
        else {
            aux[posLivre] = arr[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }
    for(i = inicioA1; i <= meio; i++) {
        aux[posLivre] = arr[i];
        posLivre++;
    }
    for(i = inicioA2; i <= fim; i++) {
        aux[posLivre] = arr[i];
        posLivre++;
    }
    for(i = inicio; i <= fim; i++) {
        arr[i] = aux[i];
    }
}

void mergeSort(int arr[], int inicio, int fim) {
    int meio;
    if(inicio < fim) {
        meio = (inicio+fim)/2;
        mergeSort(arr,inicio,meio);
        mergeSort(arr,meio+1,fim);
        intercala(arr,inicio,fim,meio);
    }
}

int main() {
    int arr[8] = {3, 4, 2, 10, 5, 7, 9, 12};
    cout << "Vetor inicial: ";
    exibeArray(arr);
    mergeSort(arr,0,7);
    exibeArray(arr);
    return 0;
}
