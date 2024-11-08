#include <iostream>

using namespace std;

int main() {
    int a, *p; // declaração de um inteiro a e de um ponteiro para inteiro p

    a = 30;
    p = &a; // o ponteiro p aponta para o endereço da variável a

    cout << "Valor de a: " << a << endl; // valor da variável a (imprime 30)
    cout << "Valor de *p: " << *p << endl; // valor que o ponteiro p aponta para (imprime 30)
    cout << "Valor de &a: " << &a << endl; // endereço da variável a
    cout << "Valor de p: " << p << endl; // endereço que o ponteiro p aponta para (endereço de a)
    cout << "Valor de &p: " << &p << endl; // 
    cout << "Valor de &*p: " << &*p << endl; // desreferenciamento do ponteiro (endereço de a)
    cout << "Valor de *&p: " << *&p << endl; // desreferenciamento do ponteiro (endereço de a)
}