package fj11.cap4;

public class TestePorta {
	public static void main(String[] args) {
		Porta porta = new Porta();
		porta.abre();
		porta.fecha();
		System.out.println(porta.estaAberta());
		porta.abre();
		System.out.println(porta.estaAberta());
		porta.cor = "azul";
		System.out.println(porta.cor);
		porta.pinta("verde");
	}
}
