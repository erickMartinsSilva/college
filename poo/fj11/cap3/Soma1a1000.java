package cap3;

public class Soma1a1000 {
    public static void main(String[] args) {
        int soma = 0;
        for(int i = 0; i < 1000; i++) {
            soma += (i+1);
        }
        System.out.println(soma);
    }
}
