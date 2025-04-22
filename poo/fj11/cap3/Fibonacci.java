package cap3;

public class Fibonacci {
    public static void main(String[] args) {
        int n = 1, fib, fibn1 = 1;
        do {
            fib = 0;
            if(n == 1) {
                fib = 0;
            } else if (n == 2) {
                fib = fibn1;
            } else {
                fib += fibn1;
                fibn1 = fib;
            }
            System.out.println(fib);
            n++;
        } while(fib < 100);
    }
}