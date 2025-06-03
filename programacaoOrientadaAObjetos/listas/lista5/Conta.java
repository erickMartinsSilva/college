package listas.lista5;

public class Conta {
    private int numero;
    private double saldo;
    private double limite;

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public void deposita(double valor) {
        saldo += valor;
    }

    public void saca(double valor) {
        if(valor > saldo) {
            System.out.println("Saldo insuficiente");
        } else saldo -= valor;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }
}
