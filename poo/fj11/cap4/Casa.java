public class Casa {
	String cor;
	Porta porta1;
	Porta porta2;
	Porta porta3;

	public void pinta(String novaCor) {
		this.cor = novaCor;
		System.out.println("Casa pintada com sucesso. Nova cor: " + this.cor);
	}

	public int NumeroPortasAbertas() {
		int contador = 0;
		if(porta1.estaAberta()) {
			contador++;
		}
		if(porta2.estaAberta()) {
			contador++;
		}
		if(porta3.estaAberta()) {
			contador++;
		}
		return contador;
	}
}
