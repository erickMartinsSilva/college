package cap12;

public class Conta {
	String nome;
	int numero;
	String agencia;
	double saldo;
	Data dataAbertura;

	public void sacar(double saque) {
		if(saque > this.saldo) {
			System.out.println("ERRO: Valor de saque maior que saldo disponível");
		} else {
			this.saldo -= saque;
			System.out.println("Saque realizado com sucesso. Novo saldo: R$" + this.saldo);
		}
	}

	public void depositar(double deposito) {
        if(deposito < 0) {
            throw new IllegalArgumentException("Valor de depósito inválido");
        } else {
            this.saldo += deposito;
        }
    }

	public double calculaRendimento() {
		return this.saldo * 0.1;
	}

	public String recuperaDadosParaImpressao() {
		String dados = "\nTitular: " + this.nome;
		dados += "\nNúmero da conta: " + this.numero;
		dados += "\nAgência: " + this.agencia;
		dados += "\nSaldo: R$" + this.saldo;
		dados += "\nData de abertura: " + dataAbertura.formatada();
		return dados;
	}
}