package exercicios.fj11.cap4;

public class Fibonacci {
	public int calculaFibonacci(int n) {
		if(n == 1) {
			return 0;
		} else if (n == 2) {
			return 1;
		} else {
			return calculaFibonacci(n-2) + calculaFibonacci(n-1);
		}
	}
}

