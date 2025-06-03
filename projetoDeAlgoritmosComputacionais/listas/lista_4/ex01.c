#include <stdio.h>

int tabuadaDeN(int n) {
    for (n = 1; n <= 10; n++) {
        printf("Tabuada do %d\n", n);
        for (int i = 1; i <= 10; i++) {
            printf("%d * %d = %d\n", n, i, n * i);
        }
    }
    return 0;
}
int main() {
    int n;
    int t = tabuadaDeN(n);
    return 0;
}