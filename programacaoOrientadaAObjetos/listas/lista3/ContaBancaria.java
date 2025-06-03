package listas.lista3;

public class ContaBancaria {
    private double saldo;
    private Data dataAbertura;

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Data getDataAbertura() {
        return dataAbertura;
    }

    public void setDataAbertura(Data d) {
        dataAbertura = new Data();
        dataAbertura.setDia(d.getDia());
        dataAbertura.setMes(d.getMes());
        dataAbertura.setAno(d.getAno());
    }

    public String getDataAberturaFormatada() {
        String dia = String.valueOf(dataAbertura.getDia());
        String mes = String.valueOf(dataAbertura.getMes());
        String ano = String.valueOf(dataAbertura.getAno());
        return dia + '/' + mes + '/' + ano;
    }

    public String getSaldoFormatado() {
        String valor = String.valueOf(saldo);
        return "R$ " + valor;
    }

    public void depositar(double valor) {
        saldo += valor;
    }

    public void sacar(double valor) {
        if(saldo < valor) {
            System.out.println("Saldo insuficiente");
        } else {
            saldo -= valor;
        }
    }
}
