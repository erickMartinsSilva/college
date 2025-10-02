package provas.P1.prova23_1.questao1;

public class Biscoito {
    private String id;
    private String cor;
    private int preco;

    public Biscoito(String id) {
        this.id = id;
    }
    public String getId() {
        return id;
    }
    public String getCor() {
        return cor;
    }
    public int getPreco() {
        return preco;
    }
    public boolean equals(Object o) {
        if(o instanceof Biscoito) {
            Biscoito b = (Biscoito) o;
            return this.getId().equals(b.getId());
        }
        return false;
    }
}
