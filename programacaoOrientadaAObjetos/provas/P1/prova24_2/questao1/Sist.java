package provas.P1.prova24_2.questao1;

import java.util.Scanner;

public class Sist {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Insira uma frase: ");
        String input = scan.nextLine();

        boolean temPalavrao = Utilidades.moderar(input);
        if(temPalavrao) {
            System.out.println("A frase contem um ou mais palavroes");
        } else System.out.println("A frase nao contem palavroes");
    }
}