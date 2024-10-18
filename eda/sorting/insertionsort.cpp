#include <iostream>

using namespace std;

void exibeVetor(int arr[]) {
    cout << "[";
    for(int i = 0; i < 6; i++) {
        if(i == 5) {
            cout << arr[i] << "]";
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

void insertionSort(int arr[]) {
    int chave, aux, j;
    cout << "Vetor inicial: ";
    exibeVetor(arr);
    cout << "\n";
    for(int i = 0; i < 6; i++) {
        chave = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > chave) {
            aux = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = aux;
            j--;
            exibeVetor(arr);
            cout << "\n";
        }
    }
}

int main() {
    int arr[6] = {17, 38, 2, 7, 10, 9};
    insertionSort(arr);
    return 0;
} 