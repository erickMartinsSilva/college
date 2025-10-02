package exercicios.fj11.cap3;

public class MultiplosDe3Entre1e100 {
    public static void main(String[] args) {
        for(int i = 1; i <= 100; i++) {
            if(i % 3 == 0) {
                System.out.println(i);
            }
        }
    }
}
