package aula4;

public class Conta {
    private String nomeCliente;
    private int matricula;
    private double saldo;
    private String senha;

    public String getNomeCliente() {
        return this.nomeCliente;
    }

    public void setNomeCliente(String n) {
        this.nomeCliente = n;
    }

    public double getSaldo() {
        return this.saldo;
    }

    public void setSaldo(double s) {
        this.saldo = s;
    }

    public String getSenha() {
        return this.senha;
    }

    public void setSenha(String s) {
        this.senha = s;
    }

    public int getMatricula() {
        return this.matricula;
    }

    public void setMatricula(int m) {
        this.matricula = m;
    }

    public void debitar(double valor) {
        if(valor > this.saldo) {
            System.out.println("Saldo insuficiente para completar a transação");
        } else {
            this.saldo -= valor;
        }
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }
}