package listas.lista3.exercicio_aluno;

import java.util.Scanner;

public class Sist {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Aluno a1 = new Aluno();
        String nome;
        double nota1, nota2;

        System.out.print("Nome do aluno: ");
        nome = scan.nextLine();
        a1.setNome(nome);
        System.out.print("Nota 1: ");
        nota1 = scan.nextDouble();
        a1.setNota1(nota1);
        System.out.print("Nota 2: ");
        nota2 = scan.nextDouble();
        a1.setNota2(nota2);

        a1.resultado();
    }
}
