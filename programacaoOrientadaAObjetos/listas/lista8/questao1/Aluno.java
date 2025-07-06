package listas.lista8.questao1;

public class Aluno implements Comparable<Aluno> {
    private String id;
    private String nome;
    private double nota;

    public Aluno(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getNota() {
        return nota;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }

    public boolean equals(Object o) {
        if(o instanceof Aluno) {
            Aluno a = (Aluno) o;
            return this.id.equals(a.id);
        }
        return false;
    }

    public int compareTo(Aluno a) {
        return Character.compare(a.id.toLowerCase().charAt(0), this.id.toLowerCase().charAt(0));
    }

    public String toString() {
        return "ID: " + id + " | Nome: " + nome + " | Nota: " + nota;
    }
}