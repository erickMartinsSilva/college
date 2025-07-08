package provas.P2.prova24_1.questao1;

import java.util.ArrayList;

public class Instituicao {
    private String nome;
    private ArrayList<Livro> listaLivros = new ArrayList<Livro>();

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void inserir(Livro l) {
        listaLivros.add(l);
    }

    public ArrayList<Livro> retornarLista() {
        return listaLivros;
    }
}
