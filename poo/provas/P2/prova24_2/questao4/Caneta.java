package provas.P2.prova24_2.questao4;

public class Caneta extends Escritor {
    private String cor;
    private static int quantidade;

    public Caneta() {
        System.out.println("X");
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        Caneta.quantidade = quantidade;
    }
}
