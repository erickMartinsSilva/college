// O código, após obter matrícula e salário de 15 funcionários, lista um relatório em ordem decrescente, a soma salarial, a média salarial e quais e quantos funcionários recebem um salário abaixo da média

#include <iostream>

#define SIZE 5

using namespace std;

void leDados(int matricula[], float salario[]) {
    for(int i = 0; i < SIZE; i++) {
        cout << "===== FUNCIONARIO " << i+1 << " =====\n";
        cout << "Matricula: ";
        cin >> matricula[i];
        cout << "Salario: R$";
        cin >> salario[i];
    }
}

void relatorioOrdenadoDecrescente(int matricula[], float salario[]) {
    int maior, aux;
    float aux2;
    for(int i = 0; i < SIZE; i++) {
        maior = i;
        for(int j = i+1; j < SIZE; j++) {
            if(salario[j] > salario[maior]) {
                maior = j;
            }
        }
        if(maior != i) {
            aux = salario[i];
            salario[i] = salario[maior];
            salario[maior] = aux;
            aux2 = matricula[i];
            matricula[i] = matricula[maior];
            matricula[maior] = aux2;
        }
    }
    cout << "\n= RELATORIO DECRESCENTE =\n";
    cout << "FUNCIONARIO\tSALARIO\t\n";
    for(int i = 0; i < SIZE; i++) {
        cout << "     " << matricula[i] << "\t\tR$" << salario[i] << "\t\n"; 
    }
}

float soma(float salario[]) {
    float soma = 0;
    for(int i = 0; i < SIZE; i++) {
        soma += salario[i];
    }
    return soma;
}

void menoresQueMedia(int matricula[], float salario[]) {
    float media = soma(salario) / SIZE;
    int contador = 0;
    cout << "Media salarial: R$" << media << "\n";
    cout << "Funcionarios que recebem menos que a media: \n";
    for(int i = 0; i < SIZE; i++) {
        if(salario[i] < media) {
            cout << "Funcionario " << matricula[i] << ": R$" << salario[i] << "\n";
            contador++;
        }
    }
    cout << "TOTAL: " << contador << " funcionarios\n";
}

int main() {
    int matricula[SIZE];
    float salario[SIZE];
    leDados(matricula,salario);
    relatorioOrdenadoDecrescente(matricula,salario);
    cout << "\nSoma dos salarios: R$" << soma(salario) << "\n";
    menoresQueMedia(matricula,salario);
    return 0;
}
