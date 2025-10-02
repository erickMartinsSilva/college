package provas.P2.prova23_1.questao1;

public class FormatoIncorretoException extends Exception {
    public FormatoIncorretoException(String str, int numHashtags) {
        super("ERRO: A string " + str + " possui " + numHashtags + " elementos #");
    }
}
