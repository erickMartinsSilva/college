public class Porta {
	boolean aberta;
	String cor;
	float dimensaoX;
	float dimensaoY;
	float dimensaoZ;

	public void abre() {
		if(aberta) {
			System.out.println("A porta já está aberta!");
		} else {
			this.aberta = true;
			System.out.println("Porta aberta");
		}
	}

	public void fecha() {
		if(aberta) {
			this.aberta = false;
			System.out.println("Porta fechada");
		} else {
			System.out.println("A porta já está fechada!");
		}
	}

	public void pinta(String novaCor) {
		this.cor = novaCor;
		System.out.println("Porta pintada com sucesso. Nova cor: " + this.cor);
	}

	public boolean estaAberta() {
		if(this.aberta) {
			return true;
		} else return false;
	}
}
