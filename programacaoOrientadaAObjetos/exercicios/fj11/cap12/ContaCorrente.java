package cap12;

public class ContaCorrente {
    private int numero;
    private double saldo;

    public ContaCorrente(int numero) {
        this.numero = numero;
    }

    public int getNumero() {
        return numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public void deposita(double valor) {
        this.saldo += valor;
    }

    public void saca(double valor) throws SaldoInsuficienteException {
        if(valor < 0) {
            throw new IllegalArgumentException("Valor de saque inválido");
        } else if(valor > saldo) {
            throw new SaldoInsuficienteException(valor);
        }
    }
}