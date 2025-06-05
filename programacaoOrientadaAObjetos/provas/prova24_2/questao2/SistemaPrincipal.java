package provas.prova24_2.questao2;

import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class SistemaPrincipal {
    public static void main(String[] args) {
        ArrayList<Planta> plantas = new ArrayList<>();
        Scanner scan = new Scanner(System.in);

        int op;
        do {
            System.out.println("1. Cadastrar planta");
            System.out.println("2. Verificar cadastro de planta");
            System.out.println("3. Exibir plantas em ordem crescente de tamanho");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            op = scan.nextInt();
            scan.nextLine();

            switch(op) {
                case 1:
                    System.out.print("Identificação: ");
                    String id = scan.nextLine();
                    System.out.print("Nome: ");
                    String nome = scan.nextLine();
                    System.out.print("Tamanho (cm): ");
                    double tamanho = scan.nextDouble();
                    scan.nextLine();
                    System.out.print("Tipo (Briofita/Pteridofita): ");
                    String tipo = scan.nextLine();

                    if(tipo.equals("Briofita")) {
                        Briofita b = new Briofita(id);
                        b.setNome(nome);
                        b.setTamanho(tamanho);
                        plantas.add(b);
                    } else if(tipo.equals("Pteridofita")) {
                        Pteridofita p = new Pteridofita(id);
                        p.setNome(nome);
                        p.setTamanho(tamanho);
                        plantas.add(p);
                    } else System.out.println("Erro: Tipo inválido");
                    break;
                case 2:
                    System.out.print("Insira a identificação da planta: ");
                    String ident = scan.nextLine();
                    Planta p = new Planta(ident);
                    if(Utils.existe(plantas, p)) {
                        System.out.println("Planta encontrada!");
                        for(int i = 0; i < plantas.size(); i++) {
                            if(plantas.get(i).equals(p)) {
                                System.out.println(plantas.get(i));
                            }
                        }
                    } else System.out.println("A planta com ID " + ident + " não existe.");
                    break;
                case 3:
                    System.out.println(Arrays.toString(Utils.ordena(plantas)));
                    break;
                default:
                    break;
            }
        } while(op != 4);
    }
}