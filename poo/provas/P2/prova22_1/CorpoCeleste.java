package provas.P2.prova22_1;

public class CorpoCeleste implements Comparable<CorpoCeleste> {
    private String id;
    private String nome;
    private double distancia;

    public CorpoCeleste(String id) {
        this.id = id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setDistancia(double distancia) {
        this.distancia = distancia;
    }

    public String toString() {
        return "ID: " + id + " | Nome: " + nome + " | Distância: " + distancia;
    }

    public boolean equals(CorpoCeleste c) {
        return this.id.equals(c.id);
    }

    public int compareTo(CorpoCeleste c) {
        return Double.compare(c.distancia, this.distancia);
    }
}
