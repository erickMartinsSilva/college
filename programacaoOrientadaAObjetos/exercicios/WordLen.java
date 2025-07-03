// Exibe o tamanho em caracteres de uma string
package exercicios;

import java.util.Scanner;

public class WordLen {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.next();
        scan.close();
        System.out.println(input.length());
    }
}
