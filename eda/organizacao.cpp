#include <iostream>

#define SIZE 3

using namespace std;

void leVetor(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        cout << "Insira o valor do " << i+1 << "o elemento: ";
        cin >> arr[i];
    }
}

void exibeVetor(int arr[]) {
    cout << "[";
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE-1) {
            cout << arr[i] << "]\n";
        }
        else {
            cout << arr[i] << ",";
        }
    }
}

void menu() {
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Sair\nSelecione o metodo que deseja usar: ";
}

void bubbleSort(int arr[SIZE]) {
    int trocou, aux;
    do {
        trocou = 0;
        for(int i = 0; i < SIZE; i++) {
            if(arr[i] > arr[i+1]) {
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                trocou = 1;
            }
        }
    } while(trocou);
}

void selectionSort(int arr[SIZE]) {
    int menor, aux;
    for(int i = 0; i < SIZE - 1; i++) {
        menor = i;
        for(int j = i+1; j < SIZE; j++) {
            if(arr[menor] > arr[j]) {
                menor = j;
            }
        }
        if(menor != i) {
            aux = arr[i];
            arr[i] = arr[menor];
            arr[menor] = aux;
        }
    }
}

int main() {
    int op, arr[SIZE];
    do {
        leVetor(arr);
        menu();
        cin >> op;
        switch(op) {
            case 1:
            bubbleSort(arr);
            break;
            case 2:
            selectionSort(arr);
            break;
            case 3:
            break;
        }
        exibeVetor(arr);
    } while(op != 3);
    return 0;
}