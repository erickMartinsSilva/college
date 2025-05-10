package cap3;

public class Fatoriais {
    public static void main(String[] args) {
        long fatorial;
        for(int i = 0; i <= 20; i++) {
            fatorial = 1;
            if(i != 0) {
                int j = i;
                while(j > 0) {
                    fatorial *= j;
                    j--;
                }
            }
            System.out.println(i + "! = " + fatorial);
        }
    }
}
