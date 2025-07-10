package provas.P2.prova23_1.questao1;

import java.util.Scanner;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        CriaPaises c = new CriaPaises();
        List<Pais> listaPaises = c.retornaPaises();

        System.out.print("Insira o código de um país: ");
        String entrada = scan.nextLine();
        Pais p = new Pais(entrada);
        if(listaPaises.contains(p)) {
            p = listaPaises.get(listaPaises.indexOf(p));
            System.out.println("Nome: " + p.getNome());
            System.out.println("Densidade: " + p.getDensidadePopulacional());
            System.out.println("Países vizinhos: " + p.getFronteiras());
        } else System.out.println("País não encontrado");

        scan.close();
    }
}
