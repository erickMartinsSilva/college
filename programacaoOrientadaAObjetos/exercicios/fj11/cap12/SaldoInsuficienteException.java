package exercicios.fj11.cap12;

public class SaldoInsuficienteException extends RuntimeException {
    public SaldoInsuficienteException(double valor) {
        super("Saldo insuficiente para sacar o valor de: R$" + valor);
    }
}