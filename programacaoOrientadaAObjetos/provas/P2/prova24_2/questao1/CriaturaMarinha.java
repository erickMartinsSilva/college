package provas.P2.prova24_2.questao1;

public class CriaturaMarinha {
    private String tag;
    private String nomeEspecie;
    private int profundidadeEncontrada;

    public CriaturaMarinha(String tag, String nomeEspecie, int profundidadeEncontrada) {
        this.tag = tag;
        this.nomeEspecie = nomeEspecie;
        this.profundidadeEncontrada = profundidadeEncontrada;
    }

    public String getTag() {
        return tag;
    }

    public String getNomeEspecie() {
        return nomeEspecie;
    }

    public int getProfundidadeEncontrada() {
        return profundidadeEncontrada;
    }

    public String toString() {
        return "Tag: " + tag + " | Nome da Espécie: " + nomeEspecie + " | Profundidade encontrada: " + profundidadeEncontrada;
    }
}
