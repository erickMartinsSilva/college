package fj11.cap3;
import java.util.Scanner;

public class OperacoesComX {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Insira valor para X: ");
        int x = scan.nextInt();

        System.out.print(x + " ");
        while(x != 1) {
            if(x % 2 == 0) {
                x /= 2;
            } else {
                x = 3 * x + 1;
            }
            System.out.print(x + " ");
        }
    }
}
