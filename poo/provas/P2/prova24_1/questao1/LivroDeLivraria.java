package provas.P2.prova24_1.questao1;

public class LivroDeLivraria extends Livro {
    private boolean vendido;

    public boolean isVendido() {
        return vendido;
    }

    public void setVendido(boolean vendido) {
        this.vendido = vendido;
    }

    public LivroDeLivraria(String isbn) {
        super(isbn);
    }

    public LivroDeLivraria(String titulo, String autor, int ano, String isbn) {
        super(titulo, autor, ano, isbn);
    }
}
