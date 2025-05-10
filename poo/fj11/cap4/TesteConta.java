package fj11.cap4;

public class TesteConta {
	public static void main(String[] args) {
		Conta c1 = new Conta();
		Data data = new Data();
		data.dia = 21;
		data.mes = 12;
		data.ano = 2006;
		c1.dataAbertura = data;
		System.out.println(c1.recuperaDadosParaImpressao());
	}
}
