package cap12;

public class SaldoInsuficienteException extends Exception {
    public SaldoInsuficienteException(double valor) {
        super("Saldo insuficiente para sacar o valor de: R$" + valor);
    }
}