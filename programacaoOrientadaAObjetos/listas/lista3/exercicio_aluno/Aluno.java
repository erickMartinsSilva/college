package listas.lista3.exercicio_aluno;

public class Aluno {
    private String nome;
    private double nota1;
    private double nota2;

    public String getNome() {
        return nome;
    }

    public double getNota1() {
        return nota1;
    }

    public double getNota2() {
        return nota2;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNota1(double nota1) {
        if(nota1 > 10) {
            nota1 = 10;
            System.out.println("Nota 1 ajustada: " + nota1);
        } else if(nota1 < 0) {
            nota1 = 0;
            System.out.println("Nota 2 ajustada: " + nota1);
        }

        this.nota1 = nota1;
    }

    public void setNota2(double nota2) {
        if(nota2 > 10) {
            nota2 = 10;
            System.out.println("Nota ajustada: " + nota2);
        } else if(nota2 < 0) {
            nota2 = 0;
            System.out.println("Nota ajustada: " + nota2);
        }

        this.nota2 = nota2;
    }

    private double media() {
        double media = (this.nota1 + this.nota2) / 2;
        System.out.println("Media do aluno: " + media);
        return media;
    }

    public void resultado() {
        double media = this.media();

        System.out.print("Situação: ");
        if(media < 4) {
            System.out.println("Reprovado");
        } else if(media >= 4 && media <= 5.9) {
            System.out.println("Em recuperação");
        } else {
            System.out.println("Aprovado");
        }
    }
}
