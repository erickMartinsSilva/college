package exercicios.fj11.cap4;

public class TesteCasa {
	public static void main(String[] args) {
		Casa casa = new Casa();
		Porta porta1 = new Porta();
		Porta porta2 = new Porta();
		Porta porta3 = new Porta();

		casa.porta1 = porta1;
		casa.porta2 = porta2;
		casa.porta3 = porta3;

		casa.cor = "amarelo";
		casa.pinta("azul");

		casa.porta1.abre();
		casa.porta2.abre();
		casa.porta3.fecha();
		
		System.out.println(casa.NumeroPortasAbertas());
	}
}
