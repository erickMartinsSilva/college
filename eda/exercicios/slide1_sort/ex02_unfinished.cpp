#include <iostream>

using namespace std;

void leDados(int matricula[], float salario[]) {
    for(int i = 0; i < 15; i++) {
        cout << "==== FUNCIONARIO " << i+1 << "====\n";
        cout << "Matricula: ";
        cin >> matricula[i];
        cout << "Salario: R$";
        cin >> salario[i];
    }
}
 
int main() {
    int matricula[15], trocou, aux;
    float salario[15], aux2;
    leDados(matricula,salario);
    do {
        trocou = 0;
        for(int i = 0; i < SIZE; i++) {
            if(salario[i] < salario[i+1]) {
                trocou = 1;
                aux = salario[i];
                salario[i] = salario[i+1];
                salario[i+1] = aux;
                aux = matricula[i];
                matricula[i] = matricula[i+1];
                matricula[i+1] = aux;
            }
        }
    } while(trocou);
}