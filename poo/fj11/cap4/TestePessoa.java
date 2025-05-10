package fj11.cap4;

public class TestePessoa {
	public static void main(String[] args) {
		Pessoa p1 = new Pessoa();
		p1.nome = "Erick";
		p1.idade = 19;
		System.out.println(p1.nome);
		System.out.println(p1.idade);
		p1.fazAniversario();
		System.out.println(p1.idade);
	}
}
