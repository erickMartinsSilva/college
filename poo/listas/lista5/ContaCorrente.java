package listas.lista5;

public class ContaCorrente extends Conta implements Tributavel {
    public double calculaTributos() {
        return super.getSaldo() * 0.01;
    }
}
