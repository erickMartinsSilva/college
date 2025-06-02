package fj11.cap4;

public class TesteFibonacci {
	public static void main(String[] args) {
		Fibonacci fibonacci = new Fibonacci();
		for(int i = 1; i <= 15; i++) {
			int resultado = fibonacci.calculaFibonacci(i);
			System.out.println(resultado);
		}
	}
}
