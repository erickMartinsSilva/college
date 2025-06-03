package listas.lista4.ufc;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Lutador[] lutadores = new Lutador[10];

        for(int i = 0; i < lutadores.length; i++) {
            System.out.println("Lutador " + (i+1));
            System.out.print("Nome: ");
            String nome = scan.nextLine();
            System.out.print("Idade: ");
            int idade = scan.nextInt();
            System.out.print("Peso: ");
            double peso = scan.nextDouble();
            scan.nextLine();

            if(peso <= 65.0) {
                lutadores[i] = new PesoPena(nome, idade, peso);
            } else if(peso <= 83.9) {
                lutadores[i] = new PesoMedio(nome, idade, peso);
            } else if(peso <= 93.0) {
                lutadores[i] = new MeioPesado(nome, idade, peso);
            } else if(peso <= 120.2) {
                lutadores[i] = new PesoPesado(nome, idade, peso);
            }
        }

        System.out.println("Insira um numero de 0 a 9: ");
        int escolha = scan.nextInt();
        System.out.println("Lutador escolhido: " + lutadores[escolha]);
        System.out.println("Possiveis lutas: ");
        lutadores[escolha].possiveisLutas(lutadores);
        System.out.print("Luta sorteada: " + lutadores[escolha].sorteioLuta(lutadores));
    }
}
