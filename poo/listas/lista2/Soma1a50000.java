// Exercício 4: Imprima a soma de todos os números entre 1 e 50.000, exceto os números entre 100 e 137
package listas.lista2;

public class Soma1a50000 {
    public static void main(String[] args) {
        int soma = 0;

        for(int i = 1; i <= 50000; i++) {
            if(!(i >= 100 && i <= 137)) {
                soma += i;
            }
        }

        System.out.println(soma);
    }
}
