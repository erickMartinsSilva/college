package provas.P2.prova22_1;

public class FormatoIncorretoException extends Exception {
    public FormatoIncorretoException(String entrada) {
        super("O formato da String " + entrada + " esta incorreto.");
    }
}
