package cap12;

public class TesteConta {
	public static void main(String[] args) {
		Conta c1 = new Conta();
		Data data = new Data();
		data.dia = 21;
		data.mes = 12;
		data.ano = 2006;
		c1.dataAbertura = data;
        try {
            // exceção: valor de depósito inválido (negativo)
            c1.depositar(-100);
        } catch (IllegalArgumentException e) {
            System.out.println("Erro: " + e);
        }
		System.out.println(c1.recuperaDadosParaImpressao());

        ContaCorrente cc = new ContaCorrente(1);
        cc.deposita(50);
        try {
            // exceção: valor de saque maior que valor de saldo
            cc.saca(60);
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
	}
}
