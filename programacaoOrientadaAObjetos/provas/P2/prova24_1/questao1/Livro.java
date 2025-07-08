package provas.P2.prova24_1.questao1;

public class Livro {
    private String titulo;
    private String autor;
    private int ano;
    private String isbn;

    public Livro(String isbn) {
        this.isbn = isbn;
    }

    public Livro(String titulo, String autor, int ano, String isbn) {
        this.titulo = titulo;
        this.autor = autor;
        this.ano = ano;
        this.isbn = isbn;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAno() {
        return ano;
    }

    public String getIsbn() {
        return isbn;
    }

    public boolean equals(Object o) {
        if(o instanceof Livro) {
            Livro l = (Livro) o;
            return this.isbn.equals(l.isbn);
        }
        return false;
    }
}
