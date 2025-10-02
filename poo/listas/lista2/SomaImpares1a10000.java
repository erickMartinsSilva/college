// Exercício 3: Imprima a soma de todos os números ímpares de 1 a 10000
package listas.lista2;

public class SomaImpares1a10000 {
    public static void main(String[] args) {
        int soma = 0;

        for(int i = 1; i <= 10000; i++) {
            if(i % 2 != 0) {
                soma += i;
            }
        }

        System.out.println(soma);
    }
}