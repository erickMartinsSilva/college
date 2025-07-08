package provas.P2.prova24_1.questao1;

public class LivroDeBiblioteca extends Livro {
    private boolean alugado;

    public boolean isAlugado() {
        return alugado;
    }

    public void setAlugado(boolean alugado) {
        this.alugado = alugado;
    }

    public LivroDeBiblioteca(String isbn) {
        super(isbn);
    }

    public LivroDeBiblioteca(String titulo, String autor, int ano, String isbn) {
        super(titulo, autor, ano, isbn);
    }
}
